Route30_House_MapScripts::
	.byte 0


Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, Route30_House_EventScript_BaldMan_PreBerryMaster
	goto_if_unset FLAG_BERRY_MASTER_INTRO, Route30_House_EventScript_BaldMan_BerryMasterIntro
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route30_House_EventScript_BaldMan_AlreadyReceived
	goto Route30_House_EventScript_BaldMan_GiveBerry

Route30_House_EventScript_BaldMan_PreBerryMaster::
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE

Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_House_EventScript_BaldMan_BerryMasterIntro::
	msgbox Route30_BerryHouse_Text_BerryMasterIntro, MSGBOX_DEFAULT
	setflag FLAG_BERRY_MASTER_INTRO
	goto Route30_House_EventScript_BaldMan_GiveBerry

Route30_House_EventScript_BaldMan_GiveBerry::
	random 7
	switch VAR_RESULT
	case 0, Route30_House_EventScript_BaldMan_GiveLiechi
	case 1, Route30_House_EventScript_BaldMan_GiveGanlon
	case 2, Route30_House_EventScript_BaldMan_GiveSalac
	case 3, Route30_House_EventScript_BaldMan_GivePetaya
	case 4, Route30_House_EventScript_BaldMan_GiveApicot
	case 5, Route30_House_EventScript_BaldMan_GiveLansat
	case 6, Route30_House_EventScript_BaldMan_GiveStarf
	end

Route30_House_EventScript_BaldMan_GiveLiechi::
	giveitem ITEM_LIECHI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Liechi, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GiveGanlon::
	giveitem ITEM_GANLON_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Ganlon, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GiveSalac::
	giveitem ITEM_SALAC_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Salac, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GivePetaya::
	giveitem ITEM_PETAYA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Petaya, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GiveApicot::
	giveitem ITEM_APICOT_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Apicot, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GiveLansat::
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Lansat, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_GiveStarf::
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route30_BerryHouse_Text_Starf, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_AlreadyReceived::
	msgbox Route30_BerryHouse_Text_BerryMasterAlreadyReceived, MSGBOX_DEFAULT
	goto Route30_House_EventScript_BaldMan_End

Route30_House_EventScript_BaldMan_End::
	closemessage
	release
	end

Route30_BerryHouse_Text_BerryMasterIntro:
	.string "Ah, you've earned your third BADGE!\p"
	.string "That means you're becoming quite the\n"
	.string "POKéMON TRAINER!\p"
	.string "I've got something special for you.\p"
	.string "I've studied BERRIES for years, and\n"
	.string "I'd like to share some of my rarer\n"
	.string "finds with you.\p"
	.string "From now on, come see me once a day,\n"
	.string "and I'll give you a rare BERRY!$"

Route30_BerryHouse_Text_BerryMasterAlreadyReceived:
	.string "Ah, you've already received your BERRY\n"
	.string "for today.\p"
	.string "Come back tomorrow. I'll have another\n"
	.string "rare BERRY waiting for you!$"

Route30_BerryHouse_Text_Liechi:
	.string "Today's BERRY is a LIECHI BERRY!\p"
	.string "Did you know? When a POKéMON's HP gets\n"
	.string "low, a LIECHI BERRY boosts its ATTACK.\p"
	.string "Quite a spicy little BERRY, isn't it?$"

Route30_BerryHouse_Text_Ganlon:
	.string "Today's BERRY is a GANLON BERRY!\p"
	.string "When a POKéMON's HP gets low, it can\n"
	.string "boost its DEFENSE with this BERRY.\p"
	.string "A tough BERRY for tough POKéMON!$"

Route30_BerryHouse_Text_Salac:
	.string "Today's BERRY is a SALAC BERRY!\p"
	.string "When a POKéMON's HP gets low, this\n"
	.string "BERRY can boost its SPEED.\p"
	.string "Sometimes, being fast is the best\n"
	.string "way to win!$"

Route30_BerryHouse_Text_Petaya:
	.string "Today's BERRY is a PETAYA BERRY!\p"
	.string "When a POKéMON's HP gets low, this\n"
	.string "BERRY can boost its SP. ATK.\p"
	.string "Perfect for a POKéMON that likes\n"
	.string "to attack from a distance!$"

Route30_BerryHouse_Text_Apicot:
	.string "Today's BERRY is an APICOT BERRY!\p"
	.string "When a POKéMON's HP gets low, this\n"
	.string "BERRY can boost its SP. DEF.\p"
	.string "A little BERRY with a big defense!$"

Route30_BerryHouse_Text_Lansat:
	.string "Today's BERRY is a LANSAT BERRY!\p"
	.string "When a POKéMON's HP gets low, this\n"
	.string "BERRY can greatly improve its chance\n"
	.string "of landing a critical hit!$"

Route30_BerryHouse_Text_Starf:
	.string "Today's BERRY is a STARF BERRY!\p"
	.string "When a POKéMON's HP gets low, this\n"
	.string "BERRY can sharply raise one of its\n"
	.string "stats at random.\p"
	.string "Even I don't know what you'll get!$"

Route30_BerryHouse_Text_MonEatBerries:
	.string "When you follow that path up north,\n"
	.string "you will see MR. POKéMON’s house.\p"
	.string "But before you go, allow me to\n"
	.string "tell you about BERRIES!\p"
	.string "POKéMON get healthier by eating\n"
	.string "BERRIES.\p"
	.string "They can even eat BERRIES\n"
	.string "they're holding in battle.\p"
	.string "BERRIES can also be turned into\n"
	.string "BALLS by KURT in AZALEA TOWN.\p"
	.string "Here. I'll share one with you!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Check trees for BERRIES.\n"
	.string "They grow back after a few hours.$"

