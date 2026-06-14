Route32South_MapScripts::
	.byte 0

Route32South_EventScript_FisherMatthew::
	trainerbattle_single TRAINER_MATTHEW, Route32South_Text_MatthewIntro, Route32South_Text_MatthewDefeat
	msgbox Route32South_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route32South_Text_MatthewIntro:
	.string "Patience is key when you're\n"
	.string "fishing.\p"
	.string "Let's see if you've got the\n"
	.string "same patience in battle.$"

Route32South_Text_MatthewDefeat:
	.string "Ah… got away…$"

Route32South_Text_MatthewPostBattle:
	.string "Sometimes the big catch slips\n"
	.string "right through your fingers.\p"
	.string "That's no reason to give up,\n"
	.string "though.$"

Route32South_EventScript_SwimmerFMary::
	trainerbattle_single TRAINER_MARY, Route32South_Text_MaryIntro, Route32South_Text_MaryDefeat
	msgbox Route32South_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

Route32South_Text_MaryIntro:
	.string "The waves are perfect today!\n"
	.string "Let's make a splash!$"

Route32South_Text_MaryDefeat:
	.string "Splash… I sank…$"

Route32South_Text_MaryPostBattle:
	.string "I love riding the waves out\n"
	.string "here.\p"
	.string "Battling in the water just\n"
	.string "feels more exciting!$"

Route32South_EventScript_PokeRangerMMarcel::
	trainerbattle_single TRAINER_MARCEL, Route32South_Text_MarcelIntro, Route32South_Text_MarcelDefeat
	msgbox Route32South_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route32South_Text_MarcelIntro:
	.string "Hold on a moment.\n"
	.string "I'm studying these trees and\n"
	.string "the life around them.\p"
	.string "Let me see how fierce you are\n"
	.string "in battle.$"

Route32South_Text_MarcelDefeat:
	.string "Hmm… Your approach checks out.$"

Route32South_Text_MarcelPostBattle:
	.string "Trees tell stories if you know\n"
	.string "how to observe them.\p"
	.string "Protecting them means\n"
	.string "understanding what grows nearby.$"

Route32South_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY Route32South_Text_PicnickerTiffanySeen, Route32South_Text_PicnickerTiffanyBeaten
	msgbox Route32South_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route32South_Text_PicnickerTiffanySeen:
    .string "Are you going to STARSHOAL CAVE too?\p"
    .string "Let's play for a little while!$"

Route32South_Text_PicnickerTiffanyBeaten:
    .string "I played too much!$"

Route32South_Text_PicnickerTiffanyWantsPicnic:
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"

Route32South_EventScript_ArtistCaroline::
	trainerbattle_single TRAINER_CAROLINE, Route32South_Text_CarolineIntro, Route32South_Text_CarolineDefeat
	msgbox Route32South_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

Route32South_Text_CarolineIntro:
	.string "The waves… the blossoms…\n"
	.string "Such a peaceful scene.\p"
	.string "I was just about to paint it,\n"
	.string "but perhaps a battle will\n"
	.string "inspire me first.$"

Route32South_Text_CarolineDefeat:
	.string "Oh… my colors faltered…$"

Route32South_Text_CarolinePostBattle:
	.string "Battles can be like art.\p"
	.string "Every move adds a new stroke\n"
	.string "to the canvas.\p"
	.string "This quiet beach… and those\n"
	.string "cherry blossoms…\n"
	.string "they're simply perfect.$"

