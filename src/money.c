#include "global.h"
#include "money.h"
#include "graphics.h"
#include "event_data.h"
#include "string_util.h"
#include "text.h"
#include "menu.h"
#include "window.h"
#include "sprite.h"
#include "strings.h"
#include "decompress.h"
#include "item.h"
#include "tx_randomizer_and_challenges.h"
#include "random.h"

#define MAX_MONEY 9999999

EWRAM_DATA static u8 sMoneyBoxWindowId = 0;
EWRAM_DATA static u8 sMoneyLabelSpriteId = 0;

#define MONEY_LABEL_TAG 0x2722

static const struct OamData sOamData_MoneyLabel =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_MoneyLabel[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_MoneyLabel[] =
{
    sSpriteAnim_MoneyLabel,
};

static const struct SpriteTemplate sSpriteTemplate_MoneyLabel =
{
    .tileTag = MONEY_LABEL_TAG,
    .paletteTag = MONEY_LABEL_TAG,
    .oam = &sOamData_MoneyLabel,
    .anims = sSpriteAnimTable_MoneyLabel,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_MoneyLabel =
{
    .data = gShopMenuMoney_Gfx,
    .size = 256,
    .tag = MONEY_LABEL_TAG,
};

static const struct CompressedSpritePalette sSpritePalette_MoneyLabel =
{
    .data = gShopMenu_Pal,
    .tag = MONEY_LABEL_TAG
};

u32 GetMoney(u32 *moneyPtr)
{
    return *moneyPtr ^ gSaveBlock2Ptr->encryptionKey;
}

void SetMoney(u32 *moneyPtr, u32 newValue)
{
    *moneyPtr = gSaveBlock2Ptr->encryptionKey ^ newValue;
}

bool8 IsEnoughMoney(u32 *moneyPtr, u32 cost)
{
    if (GetMoney(moneyPtr) >= cost)
        return TRUE;
    else
        return FALSE;
}

void AddMoney(u32 *moneyPtr, u32 toAdd)
{
    u32 toSet = GetMoney(moneyPtr);

    // can't have more money than MAX
    if (toSet + toAdd > MAX_MONEY)
    {
        toSet = MAX_MONEY;
    }
    else
    {
        toSet += toAdd;
        // check overflow, can't have less money after you receive more
        if (toSet < GetMoney(moneyPtr))
            toSet = MAX_MONEY;
    }

    SetMoney(moneyPtr, toSet);
}

void RemoveMoney(u32 *moneyPtr, u32 toSub)
{
    u32 toSet = GetMoney(moneyPtr);

    // can't subtract more than you already have
    if (toSet < toSub)
        toSet = 0;
    else
        toSet -= toSub;

    SetMoney(moneyPtr, toSet);
}

u32 GetMomSavings(void)
{
    return gSaveBlock1Ptr->momSavings;
}

void SetMomSavings(u32 newValue)
{
    if (newValue > MAX_MONEY)
        newValue = MAX_MONEY;
    gSaveBlock1Ptr->momSavings = newValue;
}

void AddMomSavings(u32 toAdd)
{
    u32 cur = GetMomSavings();
    if (cur + toAdd < cur || cur + toAdd > MAX_MONEY) //overflow or cap
        SetMomSavings(MAX_MONEY);
    else
        SetMomSavings(cur + toAdd);
}

void RemoveSavings(u32 toSub)
{
    u32 cur = GetMomSavings();
    SetMomSavings(cur > toSub ? cur - toSub : 0);
}

void WithdrawMomSavings(void)
{
    AddMoney(&gSaveBlock1Ptr->money, GetMomSavings());
    SetMomSavings(0);
}

#define MOM_RARE_ITEM_CHANCE 5 // percent chance mom finds a rare item and picks from its table instead

static const u16 sMomItemProbabilities[] = { 30, 42, 53, 63, 72, 80, 87, 93, 100}; 
//cumulative percentage, one per window slot - ondex 0 (cheapest item in current tier) is most likely
// index 8 (priciest item in teat) is least likely. Ends at 100 so a roll always matches.

//the items mom may purchase
static const u16 sMomItemTable[] =
{
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_BURN_HEAL,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_FULL_HEAL,
    ITEM_REPEL,
    ITEM_ETHER,
    ITEM_HYPER_POTION,
    ITEM_ULTRA_BALL,
    ITEM_REVIVE,
    ITEM_NUGGET,
    ITEM_RARE_CANDY,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_KINGS_ROCK,
}; //18 entries, cheap -> pricey - 18 was chosen because the optionWindow is size 9 and tier maxes at 9 so 9 + 9 = 18

static const u16 sMomRareItemTable[] =
{
    ITEM_NUGGET,
    ITEM_FIRE_STONE,
    ITEM_THUNDER_STONE,
    ITEM_WATER_STONE,
    ITEM_MOON_STONE,
    ITEM_SUN_STONE,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY, //not sure what to put here
};

u16 TryMomPurchase(void)
{
    u8 tier;
    u16 chosenItem;
    u32 savings = GetMomSavings();
    u32 discountedPrice;
    u32 rand, j;

    gSpecialVar_0x8006 = FALSE; // side channel: did she buy from the rare table?

    if (Random() % 100 < MOM_RARE_ITEM_CHANCE)
    {
        chosenItem = sMomRareItemTable[Random() % ARRAY_COUNT(sMomRareItemTable)];
        discountedPrice = (ItemId_GetPrice(chosenItem) * 9) / 10; //10% off - mom is a shopper ;)
        if (discountedPrice == 0 || discountedPrice > savings || !CheckPCHasSpace(chosenItem, 1))
            return ITEM_NONE; // found something rare but couldn't afford it - no purchase this cycle

        RemoveSavings(discountedPrice);
        AddPCItem(chosenItem, 1);
        gSpecialVar_0x8006 = TRUE;
        return chosenItem;

    }

    tier = GetCurrentBadgeCount(); // 0-8, Johto bagdes only
    if (tier >= NUM_BADGES)
        tier = 9; //owning all 8 Johto Badges unlocks the top window

    rand = Random() % 100;
    for (j = 0; j < (s32)ARRAY_COUNT(sMomItemProbabilities); j++)
    {
        if (sMomItemProbabilities[j] > rand)
            break;
    }

    chosenItem = sMomItemTable[tier + j];
    discountedPrice = (ItemId_GetPrice(chosenItem) * 9) / 10; //10% off - mom is a shopper ;)
    if (discountedPrice == 0 || discountedPrice > savings || !CheckPCHasSpace(chosenItem, 1))
        return ITEM_NONE; // found something but couldn't afford it - no purchase this cycle

    RemoveSavings(discountedPrice);
    AddPCItem(chosenItem, 1);
    return chosenItem;
}

bool8 IsEnoughForCostInVar0x8005(void)
{
    return IsEnoughMoney(&gSaveBlock1Ptr->money, gSpecialVar_0x8005);
}

void SubtractMoneyFromVar0x8005(void)
{
    RemoveMoney(&gSaveBlock1Ptr->money, gSpecialVar_0x8005);
}

void PrintMoneyAmountInMoneyBox(u8 windowId, int amount, u8 speed)
{
    PrintMoneyAmount(windowId, 32, 1, amount, speed);
}

void PrintMoneyAmount(u8 windowId, u8 x, u8 y, int amount, u8 speed)
{
    u8 *txtPtr;
    s32 strLength;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN, 7);

    strLength = 7 - StringLength(gStringVar1);
    txtPtr = gStringVar4;

    while (strLength-- > 0)
        *(txtPtr++) = CHAR_SPACER;

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, x, y, speed, NULL);
}

void PrintMoneyAmountInMoneyBoxWithBorder(u8 windowId, u16 tileStart, u8 pallete, int amount)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, tileStart, pallete);
    PrintMoneyAmountInMoneyBox(windowId, amount, 0);
}

void ChangeAmountInMoneyBox(int amount)
{
    PrintMoneyAmountInMoneyBox(sMoneyBoxWindowId, amount, 0);
}

void DrawMoneyBox(int amount, u8 x, u8 y)
{
    struct WindowTemplate template;

    SetWindowTemplateFields(&template, 0, x + 1, y + 1, 10, 2, 15, 8);
    sMoneyBoxWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sMoneyBoxWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sMoneyBoxWindowId);
    CopyWindowToVram(sMoneyBoxWindowId, COPYWIN_MAP);
    PrintMoneyAmountInMoneyBoxWithBorder(sMoneyBoxWindowId, 0x214, 14, amount);
    AddMoneyLabelObject((8 * x) + 19, (8 * y) + 11);
}

void HideMoneyBox(void)
{
    RemoveMoneyLabelObject();
    ClearStdWindowAndFrameToTransparent(sMoneyBoxWindowId, FALSE);
    CopyWindowToVram(sMoneyBoxWindowId, COPYWIN_GFX);
    RemoveWindow(sMoneyBoxWindowId);
}

void AddMoneyLabelObject(u16 x, u16 y)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_MoneyLabel);
    LoadCompressedSpritePalette(&sSpritePalette_MoneyLabel);
    sMoneyLabelSpriteId = CreateSprite(&sSpriteTemplate_MoneyLabel, x, y, 0);
}

void RemoveMoneyLabelObject(void)
{
    DestroySpriteAndFreeResources(&gSprites[sMoneyLabelSpriteId]);
}
