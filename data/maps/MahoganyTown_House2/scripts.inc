MahoganyTown_House2_MapScripts::
	.byte 0

MahoganyTown_House2_EventScript_MimicGuy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_MIMIC, MahoganyTownHouse2_EventScript_ReceivedBulletSeed
	msgbox MahoganyTownHouse2_Text_MimicGive, MSGBOX_DEFAULT
	giveitem ITEM_TM_MIMIC
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_MIMIC
	msgbox MahoganyTownHouse2_Text_MimicReceived, MSGBOX_DEFAULT
	release
	end

MahoganyTownHouse2_EventScript_ReceivedBulletSeed::
	goto_if_set FLAG_FINITE_TMS, MahoganyTownHouse2_EventScript_ReceivedBulletSeedFinite
	msgbox MahoganyTownHouse2_Text_TMsCanBeReused, MSGBOX_DEFAULT
	release
	end

MahoganyTownHouse2_EventScript_ReceivedBulletSeedFinite::
	msgbox Route35NationalParkGate_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end


MahoganyTownHouse2_Text_MimicGive:
	.string "Ah, young one!\p"
	.string "I am also a young one, yet I mimic\n"
	.string "the speech and mannerisms of the\l"
	.string "elderly folk of this town.\p"
	.string "It is an art of imitation...\n"
	.string "a study of others' movements!\p"
	.string "And so, I have something fitting\n"
	.string "for you, young one.\p"
	.string "Young one, take this TM!$"

MahoganyTownHouse2_Text_MimicReceived:
	.string "That TM contains MIMIC.\p"
	.string "It allows your POKéMON to copy\n"
	.string "the move of an opponent in battle.$"

MahoganyTownHouse2_Text_MimicAfter:
	.string "Fwofwo! To mimic another is to\n"
	.string "understand them completely!\p"
	.string "Tell me, young one...\n"
	.string "could you imitate as flawlessly\l"
	.string "as I?$"

MahoganyTownHouse2_Text_TMsCanBeReused:
	.string "By the way, a TM, TECHNICAL MACHINE,\n"
	.string "can be used as many times as you want!$"
	
