CherrygroveBay_MapScripts::
	.byte 0

CherrygroveBay_EventScript_SwimmerMTyler::
	trainerbattle_single TRAINER_TYLER, CherrygroveBay_Text_TylerIntro, CherrygroveBay_Text_TylerDefeat
	msgbox CherrygroveBay_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_DragonTamerZander::
	trainerbattle_single TRAINER_ZANDER, CherrygroveBay_DragonTamerZander_Text_Intro, CherrygroveBay_DragonTamerZander_Text_Defeat
	msgbox CherrygroveBay_DragonTamerZander_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_SwimmerFLeah::
	trainerbattle_single TRAINER_LEAH, CherrygroveBay_Text_LeahIntro, CherrygroveBay_Text_LeahDefeat
	msgbox CherrygroveBay_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_BeautyVeronica::
	trainerbattle_single TRAINER_VERONICA, CherrygroveBay_Text_VeronicaIntro, CherrygroveBay_Text_VeronicaDefeat
	msgbox CherrygroveBay_Text_VeronicaPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_FisherAlec::
	trainerbattle_single TRAINER_ALEC, CherrygroveBay_Text_AlecIntro, CherrygroveBay_Text_AlecDefeat
	msgbox CherrygroveBay_Text_AlecPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_ExpertMudSlap::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_MUD_SLAP, CherrygroveBay_EventScript_ExpertMudSlap_After

	msgbox CherrygroveBay_Text_ExpertMudSlap_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_MUD_SLAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull

	setflag FLAG_RECEIVED_TM_MUD_SLAP
	release
	end

CherrygroveBay_EventScript_ExpertMudSlap_After:
	msgbox CherrygroveBay_Text_ExpertMudSlap_After, MSGBOX_DEFAULT
	release
	end

CherrygroveBay_EventScript_Tuber::
	lock
	faceplayer
	msgbox CherrygroveBay_Text_Tuber, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveBay_Text_Tuber:
	.string "Whee! The water's so nice!\p"
	.string "I could play here all day!\p"
	.string "Hey, hey!\n"
	.string "Do you wanna play too?$"

CherrygroveBay_Text_TylerIntro:
	.string "The sea's my turf!\n"
	.string "Try to keep up with me!$"

CherrygroveBay_Text_TylerDefeat:
	.string "Whoa… too fast…$"

CherrygroveBay_Text_TylerPostBattle:
	.string "My WARTORTLE and I swim every\n"
	.string "day together.\p"
	.string "It's crazy fast… I can barely\n"
	.string "keep up sometimes!$"

CherrygroveBay_DragonTamerZander_Text_Intro:
	.string "Look up.\n"
	.string "Someday, dragons will rule the\n"
	.string "sky above us.\p"
	.string "Until then… I train.$"

CherrygroveBay_DragonTamerZander_Text_Defeat:
	.string "So high… yet still outflown.$"

CherrygroveBay_DragonTamerZander_Text_PostBattle:
	.string "When dragons fly, the sky feels\n"
	.string "endless.\p"
	.string "That's why I train to reach\n"
	.string "those heights.$"

CherrygroveBay_Text_LeahIntro:
	.string "Isn't the sunshine lovely?\n"
	.string "The water feels just right!$"

CherrygroveBay_Text_LeahDefeat:
	.string "Oh! Was the tide against me?$"

CherrygroveBay_Text_LeahPostBattle:
	.string "My CORSOLA loves days like\n"
	.string "this.\p"
	.string "Warm sun, calm waves…\n"
	.string "CHERRYGROVE BAY is perfect!$"

CherrygroveBay_Text_VeronicaIntro:
	.string "This warmth is perfect for my\n"
	.string "complexion.\p"
	.string "Let's see if you can keep up.$"

CherrygroveBay_Text_VeronicaDefeat:
	.string "Oh my… I lost my glow.$"

CherrygroveBay_Text_VeronicaPostBattle:
	.string "I adore places like this.\n"
	.string "Sunlight brings out true beauty.\p"
	.string "Battles are nice, but I much\n"
	.string "prefer relaxing in the warmth.$"

CherrygroveBay_Text_ExpertMudSlap_Intro:
	.string "A clever trainer uses every\n"
	.string "tool at their disposal.\p"
	.string "You know. Even fighting dirty\n"
	.string "has its merits.\p"
	.string "Take this. It may seem simple,\n"
	.string "but it can turn the tide.$"

CherrygroveBay_Text_ExpertMudSlap_After:
	.string "Lowering your foe's ACCURACY\n"
	.string "can create openings.\p"
	.string "Use your POKéMON's moves\n"
	.string "with cunning, not just force.$"

CherrygroveBay_Text_AlecIntro:
	.string "The sea's full of surprises!\p"
	.string "My REMORAID and I never miss\n"
	.string "a good catch!$"

CherrygroveBay_Text_AlecDefeat:
	.string "Ack! My aim was off!$"

CherrygroveBay_Text_AlecPostBattle:
	.string "REMORAID may be small, but\n"
	.string "it's got incredible accuracy!\p"
	.string "Watching it fire shots across\n"
	.string "the water never gets old!$"
