OlivineBay_MapScripts::
	.byte 0


OlivineBay_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineBay_Text_Fisher, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_Ludicolo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LUDICOLO, CRY_MODE_NORMAL
	msgbox OlivineBay_Text_Ludicolo, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineBay_EventScript_PokefanM::
	lock
	faceplayer
	msgbox OlivineBay_Text_PokefanM, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_Rocker::
	lock
	faceplayer
	msgbox OlivineBay_Text_Rocker, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_ShellBellExpert::
	lock
	faceplayer
	checkitem ITEM_SHOAL_SALT, 4
	goto_if_eq VAR_RESULT, FALSE, OlivineBay_EventScript_NotEnoughShoalSaltOrShells
	checkitem ITEM_SHOAL_SHELL, 4
	goto_if_eq VAR_RESULT, FALSE, OlivineBay_EventScript_NotEnoughShoalSaltOrShells
	msgbox OlivineBay_Text_WouldYouLikeShellBell, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineBay_EventScript_DeclineShellBell
	checkitemspace ITEM_SHELL_BELL
	call_if_eq VAR_RESULT, FALSE, OlivineBay_EventScript_CheckSpaceWillBeFreed
	goto_if_eq VAR_RESULT, 2, OlivineBay_EventScript_NoRoomForShellBell
	msgbox OlivineBay_Text_MakeShellBellRightAway, MSGBOX_DEFAULT
	removeitem ITEM_SHOAL_SALT, 4
	removeitem ITEM_SHOAL_SHELL, 4
	giveitem ITEM_SHELL_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull  @ Never FALSE, we already made sure there will be room in the bag.
	msgbox OlivineBay_Text_ExplainShellBell, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2  @ Not read. Perhaps meant to stop him from re-explaining the Shell Bell if multiple are received in one sitting.
	release
	end

@ If the bag is full, check if a slot will be freed when 4 Shoal Salt or Shells are given
OlivineBay_EventScript_CheckSpaceWillBeFreed::
	checkitem ITEM_SHOAL_SALT, 5
	goto_if_eq VAR_RESULT, TRUE, OlivineBay_EventScript_CheckSpaceWillBeFreedShells
	return

OlivineBay_EventScript_CheckSpaceWillBeFreedShells::
	checkitem ITEM_SHOAL_SHELL, 5
	goto_if_eq VAR_RESULT, TRUE, OlivineBay_EventScript_NoSpaceWillBeFreed
	return

OlivineBay_EventScript_NoSpaceWillBeFreed::
	setvar VAR_RESULT, 2
	return

OlivineBay_EventScript_NoRoomForShellBell::
	msgbox OlivineBay_Text_NoSpaceInYourBag, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_NotEnoughShoalSaltOrShells::
	checkitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, TRUE, OlivineBay_EventScript_HasSomeShoalSaltOrShell
	checkitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, TRUE, OlivineBay_EventScript_HasSomeShoalSaltOrShell
	msgbox OlivineBay_Text_AreYouPlanningOnGoingInThere, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_HasSomeShoalSaltOrShell::
	msgbox OlivineBay_Text_BringMe4ShoalSaltAndShells, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_DeclineShellBell::
	msgbox OlivineBay_Text_WantedToMakeShellBell, MSGBOX_DEFAULT
	release
	end

OlivineBay_EventScript_Roman::
	trainerbattle_single TRAINER_ROMAN OlivineBay_Text_RomanSeen, OlivineBay_Text_RomanBeaten
	msgbox OlivineBay_Text_RomanAfter, MSGBOX_AUTOCLOSE
	end

OlivineBay_EventScript_Vito::
	trainerbattle_single TRAINER_VITO OlivineBay_Text_VitoSeen, OlivineBay_Text_VitoBeaten
	msgbox OlivineBay_Text_VitoAfter, MSGBOX_AUTOCLOSE
	end

OlivineBay_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA OlivineBay_Text_KeiraSeen, OlivineBay_Text_KeiraBeaten
	msgbox OlivineBay_Text_KeiraAfter, MSGBOX_AUTOCLOSE
	end

OlivineBay_EventScript_Matt::
	trainerbattle_single TRAINER_MATT OlivineBay_Text_MattSeen, OlivineBay_Text_MattBeaten
	msgbox OlivineBay_Text_MattAfter, MSGBOX_AUTOCLOSE
	end

OlivineBay_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON OlivineBay_Text_ColtonSeen, OlivineBay_Text_ColtonBeaten
	msgbox OlivineBay_Text_ColtonAfter, MSGBOX_AUTOCLOSE
	end

OlivineBay_EventScript_ShoalSalt::
	finditem ITEM_SHOAL_SALT
	end

OlivineBay_Text_Fisher:
	.string "Ahh… OLIVINE BAY.\p"
	.string "...\p"
	.string "You see that tower over there?\p"
	.string "The LIGHTHOUSE.\p"
	.string "People think it's just a building.\p"
	.string "Tall.\p"
	.string "Stone.\p"
	.string "Bright light.\p"
	.string "But it's more than that.\p"
	.string "That light's guided sailors\n"
	.string "for generations.\p"
	.string "Storms roll in fast out here.\p"
	.string "...\p"
	.string "Fog too.\p"
	.string "Real thick.\p"
	.string "...\p"
	.string "When the sea turns mean…\p"
	.string "...\p"
	.string "That light's the only thing\n"
	.string "you can trust.\p"
	.string "...\p"
	.string "I remember one night…\p"
	.string "Waves like walls.\p"
	.string "Wind screaming.\p"
	.string "...\p"
	.string "Couldn't see my own hands.\p"
	.string "...\p"
	.string "But that light?\p"
	.string "...\p"
	.string "Never flickered.\p"
	.string "...\p"
	.string "Not once.\p"
	.string "...\p"
	.string "They say a POKéMON keeps it\n"
	.string "shining.\p"
	.string "...\p"
	.string "A gentle one.\p"
	.string "...\p"
	.string "Doesn't battle.\p"
	.string "...\p"
	.string "Just shines.\p"
	.string "...\p"
	.string "Funny, huh?\p"
	.string "...\p"
	.string "Really impressive, actually.\p"
	.string "…\p"
	.string "Anyway.\p"
	.string "...\p"
	.string "So like I was saying…\p"
	.string "When you think about it…\p"
	.string "...\p"
	.string "I mean really think…\p"
	.string "...\p"
	.string "In a world full of fighting…\p"
	.string "...\p"
	.string "The most important POKéMON…\p"
	.string "...\p"
	.string "Just helps.\p"
	.string "...\p"
	.string "Some folks climb all the way up.\p"
	.string "Step by step.\p"
	.string "...\p"
	.string "Me?\p"
	.string "...\p"
	.string "I just sit here.\p"
	.string "...\p"
	.string "Fish.\p"
	.string "...\p"
	.string "Think.\p"
	.string "...\p"
	.string "Watch the light.\p"
	.string "...\p"
	.string "As long as it's there…\p"
	.string "...\p"
	.string "I know we'll make it home.$"

OlivineBay_Text_Ludicolo:
	.string "LUDICOLO: Ka-Gaahaha.$"

OlivineBay_Text_PokefanM:
	.string "Ahh… feel that breeze?\p"
	.string "Perfect, isn't it?\p"
	.string "Out here by the sea, the wind's\n"
	.string "got a rhythm all its own.\p"
	.string "Hey! Don't you think so?\p"
	.string "...\p"
	.string "My LUDICOLO sure does!\p"
	.string "It starts swaying the moment\n"
	.string "the wind picks up.\p"
	.string "Step by step…\n"
	.string "Sometimes you've just gotta\n"
	.string "enjoy the moment!\p"
	.string "...\p"
	.string "Right, partner?\p"
	.string "...\p"
	.string "Ludi! Ludi!$"

OlivineBay_Text_Rocker:
	.string "I'm waiting for someone!\n"
	.string "...\p"
	.string "Huh?\n"
	.string "You think I look nervous?\p"
	.string "No way!\n"
	.string "I'm totally cool!\p"
	.string "She's just running late.\n"
	.string "...\p"
	.string "Tch…\p"
	.string "She said we'd meet here\n"
	.string "I even showed up early.\p"
	.string "Don't tell anyone that.\n"
	.string "...\p"
	.string "She likes the ocean, you know?\n"
	.string "Says the waves have rhythm.$"

OlivineBay_Text_RomanSeen:
	.string "Ah, the sea air… exquisite.\p"
	.string "I often come here to unwind.\p"
	.string "...\p"
	.string "Hm?\n"
	.string "A trainer of modest appearance?\p"
	.string "Very well.\n"
	.string "Show me something worthwhile.$"

OlivineBay_Text_RomanBeaten:
	.string "What?\p"
	.string "That was… unexpected.$"

OlivineBay_Text_RomanAfter:
	.string "Money can buy many things,\n"
	.string "but not skill like that.\p"
	.string "Do try not to squander it.$"

OlivineBay_Text_VitoSeen:
	.string "I was just thinking about\n"
	.string "SLOWPOKE.\p"
	.string "Aren't they amazing?\n"
	.string "So calm… so still…\p"
	.string "...\p"
	.string "You don't get it, do you?\p"
	.string "Fine!\n"
	.string "I'll show you their greatness!$"

OlivineBay_Text_VitoBeaten:
	.string "Whaaat…?\p"
	.string "Even SLOWPOKE couldn't win…?$"

OlivineBay_Text_VitoAfter:
	.string "SLOWPOKE are incredible.\p"
	.string "They don't rush.\n"
	.string "They don't panic.\p"
	.string "Sometimes they don't even react!\p"
	.string "...\p"
	.string "I've been watching one for hours.\p"
	.string "...\p"
	.string "I think it blinked.$"


OlivineBay_Text_KeiraSeen:
	.string "Hey! Watch it!\p"
	.string "You almost splashed me!\p"
	.string "...\p"
	.string "Heh, just kidding.\p"
	.string "You're a trainer, right?\n"
	.string "Then let's make some waves!$"

OlivineBay_Text_KeiraBeaten:
	.string "Whoa! Okay!\p"
	.string "You've got real strength!$"

OlivineBay_Text_KeiraAfter:
	.string "The sea's always changing.\p"
	.string "Calm one minute,\n"
	.string "rough the next.\p"
	.string "...\p"
	.string "Battles feel the same way.\p"
	.string "You've gotta go with the flow!\p"
	.string "...\p"
	.string "Come swim sometime!\n"
	.string "It clears your head!$"

OlivineBay_Text_MattSeen:
	.string "Hey! You're not scared of deep\n"
	.string "water, are you?\p"
	.string "...\p"
	.string "Heh, doesn't matter.\n"
	.string "Out here, you either swim…\n"
	.string "or you sink!\p"
	.string "Let's see how you handle it!$"

OlivineBay_Text_MattBeaten:
	.string "Whoa… guess I sank that time…$"

OlivineBay_Text_MattAfter:
	.string "You've gotta respect the sea.\p"
	.string "Get careless, and it'll drag you\n"
	.string "under in no time.$"

OlivineBay_Text_ColtonSeen:
	.string "The water's perfect today!\p"
	.string "Hey, you look like a trainer.\n"
	.string "Let's have a quick battle!$"

OlivineBay_Text_ColtonBeaten:
	.string "Ah, wiped out…\n"
	.string "Didn't last long!$"

OlivineBay_Text_ColtonAfter:
	.string "Short battles, quick swims…\n"
	.string "that's how I like it.\p"
	.string "Alright, back in the water!$"

OlivineBay_Text_AreYouPlanningOnGoingInThere:
	.string "Are you planning on exploring\n"
	.string "all of JOHTO's coast?\p"
	.string "How about bringing me back some\n"
	.string "SHOAL SALT and SHOAL SHELLS?\p"
	.string "You can find them around the sea\n"
	.string "do not forget that SHOAL SHELLS\p"
	.string "tend to be located near CHERRYGROVE\n"
	.string "CITY. While SHOAL SALT can be found\l"
	.string "here.\p"
	.string "I can make you something good if\n"
	.string "you bring me the ingredients.$"

OlivineBay_Text_BringMe4ShoalSaltAndShells:
	.string "If you bring me four each of the\n"
	.string "SHOAL SALT and SHOAL SHELLS,\l"
	.string "I can make you a SHELL BELL…\p"
	.string "You can get those ingredients\n"
	.string "every day.$"

OlivineBay_Text_WouldYouLikeShellBell:
	.string "Oh, hey! SHOAL SALT and SHOAL SHELLS!\n"
	.string "And enough of them, too!\p"
	.string "Would you like me to make you\n"
	.string "a SHELL BELL with them?$"

OlivineBay_Text_MakeShellBellRightAway:
	.string "All righty, then! I'll make you\n"
	.string "a SHELL BELL right away.\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "There! Done!$"

OlivineBay_Text_ExplainShellBell:
	.string "Have a POKéMON hold on to that.\n"
	.string "It'll love it, that's for certain.\p"
	.string "Why, the SHELL BELL's chime…\n"
	.string "It's simply sublime!\p"
	.string "You can get its ingredients every day,\n"
	.string "so I can make you more.$"

OlivineBay_Text_WantedToMakeShellBell:
	.string "Oh… Is that so…\n"
	.string "I wanted to make a SHELL BELL…$"

OlivineBay_Text_NoSpaceInYourBag:
	.string "You don't have space in your BAG\n"
	.string "if I were to make it for you.\p"
	.string "You should make room and come back\n"
	.string "for a SHELL BELL.$"
	
