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

CherrygroveBay_EventScript_PokeRangerMMarcel::
	trainerbattle_single TRAINER_MARCEL, CherrygroveBay_Text_MarcelIntro, CherrygroveBay_Text_MarcelDefeat
	msgbox CherrygroveBay_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_SwimmerFLeah::
	trainerbattle_single TRAINER_LEAH, CherrygroveBay_Text_LeahIntro, CherrygroveBay_Text_LeahDefeat
	msgbox CherrygroveBay_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_BeautyVeronica::
	trainerbattle_single TRAINER_VERONICA, CherrygroveBay_Text_VeronicaIntro, CherrygroveBay_Text_VeronicaDefeat
	msgbox CherrygroveBay_Text_VeronicaPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_SwimmerFMary::
	trainerbattle_single TRAINER_MARY, CherrygroveBay_Text_MaryIntro, CherrygroveBay_Text_MaryDefeat
	msgbox CherrygroveBay_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_EventScript_FisherMatthew::
	trainerbattle_single TRAINER_MATTHEW, CherrygroveBay_Text_MatthewIntro, CherrygroveBay_Text_MatthewDefeat
	msgbox CherrygroveBay_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

CherrygroveBay_Text_MatthewIntro:
	.string "Patience is key when you're\n"
	.string "fishing.\p"
	.string "Let's see if you've got the\n"
	.string "same patience in battle.$"

CherrygroveBay_Text_MatthewDefeat:
	.string "Ah… got away…$"

CherrygroveBay_Text_MatthewPostBattle:
	.string "Sometimes the big catch slips\n"
	.string "right through your fingers.\p"
	.string "That's no reason to give up,\n"
	.string "though.$"

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


CherrygroveBay_Text_TylerIntro:
	.string "The sea's my turf!\n"
	.string "Try to keep up with me!$"

CherrygroveBay_Text_TylerDefeat:
	.string "Whoa… too fast…$"

CherrygroveBay_Text_TylerPostBattle:
	.string "My Wartortle and I swim every\n"
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

CherrygroveBay_Text_MarcelIntro:
	.string "Hold on a moment.\n"
	.string "I'm studying these trees and\n"
	.string "the life around them.\p"
	.string "Let me see how fierce you are\n"
	.string "in battle.$"

CherrygroveBay_Text_MarcelDefeat:
	.string "Hmm… Your approach checks out.$"

CherrygroveBay_Text_MarcelPostBattle:
	.string "Trees tell stories if you know\n"
	.string "how to observe them.\p"
	.string "Protecting them means\n"
	.string "understanding what grows nearby.$"

CherrygroveBay_Text_LeahIntro:
	.string "Isn't the sunshine lovely?\n"
	.string "The water feels just right!$"

CherrygroveBay_Text_LeahDefeat:
	.string "Oh! Was the tide against me?$"

CherrygroveBay_Text_LeahPostBattle:
	.string "My Corsola loves days like\n"
	.string "this.\p"
	.string "Warm sun, calm waves…\n"
	.string "Cherrygrove Bay is perfect!$"

CherrygroveBay_Text_VeronicaIntro:
	.string "This warmth is perfect for my\n"
	.string "complexion.\p"
	.string "Let’s see if you can keep up.$"

CherrygroveBay_Text_VeronicaDefeat:
	.string "Oh my… I lost my glow.$"

CherrygroveBay_Text_VeronicaPostBattle:
	.string "I adore places like this.\n"
	.string "Sunlight brings out true beauty.\p"
	.string "Battles are nice, but I much\n"
	.string "prefer relaxing in the warmth.$"

CherrygroveBay_Text_MaryIntro:
	.string "The waves are perfect today!\n"
	.string "Let's make a splash!$"

CherrygroveBay_Text_MaryDefeat:
	.string "Splash… I sank…$"

CherrygroveBay_Text_MaryPostBattle:
	.string "I love riding the waves out\n"
	.string "here.\p"
	.string "Battling in the water just\n"
	.string "feels more exciting!$"

CherrygroveBay_Text_ExpertMudSlap_Intro:
	.string "Battles aren't just about\n"
	.string "power.\p"
	.string "A clever trainer uses every\n"
	.string "tool at their disposal.\p"
	.string "Take this. It may seem simple,\n"
	.string "but it can turn the tide.$"

CherrygroveBay_Text_ExpertMudSlap_After:
	.string "Lowering your foe's accuracy\n"
	.string "can create openings.\p"
	.string "Use your Pokémon's moves\n"
	.string "with cunning, not just force.$"
