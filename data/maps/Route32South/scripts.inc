Route32South_MapScripts::
	.byte 0

Route32South_EventScript_SwimmerFLeah::
trainerbattle_single TRAINER_LEAH, Route32South_Text_LeahIntro, Route32South_Text_LeahDefeat
	msgbox Route32South_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end	

Route32South_Text_LeahIntro:
	.string "Isn't the sunshine lovely?\n"
	.string "The water feels just right!$"

Route32South_Text_LeahDefeat:
	.string "Oh! Was the tide against me?$"

Route32South_Text_LeahPostBattle:
	.string "My CORSOLA loves days like\n"
	.string "this.\p"
	.string "Warm sun, calm waves…\n"
	.string "CHERRYGROVE BAY is perfect!$"

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
	trainerbattle_single TRAINER_TIFFANY, Route32South_Text_PicnickerTiffanySeen, Route32South_Text_PicnickerTiffanyBeaten, Route32South_EventScript_TryRegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32South_EventScript_RematchTiffany
	msgbox Route32South_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route32South_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY, Route32South_Text_TiffanyRematchIntro, Route32South_Text_TiffanyRematchDefeat
	msgbox Route32South_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route32South_EventScript_TryRegisterTiffany::
	msgbox Route32South_Text_TiffanyRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY
	release
	end
Route32South_Text_PicnickerTiffanySeen:
    .string "Are you going to STARSHOAL CAVE too?\p"
    .string "Let's play for a little while!$"

Route32South_Text_PicnickerTiffanyBeaten:
    .string "I played too much!$"

Route32South_Text_PicnickerTiffanyWantsPicnic:
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"

Route32South_Text_TiffanyRegisterPrompt:
	.string "That was lots of fun!\p"
	.string "Let's have another battle the next\n"
	.string "time you're out this way.\p"
	.string "Can I get your number?$"

Route32South_Text_TiffanyRematchIntro:
	.string "Hi again!\p"
	.string "My POKéMON and I have been having\n"
	.string "lots of fun together.\p"
	.string "Let's play another round!$"

Route32South_Text_TiffanyRematchDefeat:
	.string "Oops!\p"
	.string "I got carried away again!$"

Route32South_Text_TiffanyPostRematch:
	.string "Battles are always more fun when\n"
	.string "everyone's smiling.\p"
	.string "Next time, let's have another\n"
	.string "picnic afterward!$"

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

Route32South_EventScript_DragonTamerZander::
	trainerbattle_single TRAINER_ZANDER, Route32South_DragonTamerZander_Text_Intro, Route32South_DragonTamerZander_Text_Defeat, Route32South_EventScript_TryRegisterZander
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32South_EventScript_RematchZander
	msgbox Route32South_DragonTamerZander_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route32South_EventScript_RematchZander::
	trainerbattle_rematch TRAINER_ZANDER, Route32South_DragonTamerZander_Text_RematchIntro, Route32South_DragonTamerZander_Text_RematchDefeat
	msgbox Route32South_DragonTamerZander_Text_PostRematch, MSGBOX_AUTOCLOSE
	end

Route32South_EventScript_TryRegisterZander::
	msgbox Route32South_DragonTamerZander_Text_RegisterPrompt, MSGBOX_DEFAULT
register_matchcall TRAINER_ZANDER
release
end

Route32South_DragonTamerZander_Text_Intro:
	.string "Look up.\n"
	.string "Someday, dragons will rule the\n"
	.string "sky above us.\p"
	.string "Until then… I train.$"

Route32South_DragonTamerZander_Text_Defeat:
	.string "So high… yet still outflown.$"

Route32South_DragonTamerZander_Text_PostBattle:
	.string "When dragons fly, the sky feels\n"
	.string "endless.\p"
	.string "That's why I train to reach\n"
	.string "those heights.$"

Route32South_DragonTamerZander_Text_RegisterPrompt:
	.string "Few trainers inspire me to train\n"
	.string "harder than you.\p"
	.string "When we meet again, let our dragons\n"
	.string "cross paths once more.\p"
	.string "Can I get your number?$"

Route32South_DragonTamerZander_Text_RematchIntro:
	.string "The sky still lies beyond my reach…\p"
	.string "But each battle brings me closer.\p"
	.string "Show me how much farther I have\n"
	.string "to climb.$"

Route32South_DragonTamerZander_Text_RematchDefeat:
	.string "Even dragons must keep\n"
	.string "reaching higher…$"

Route32South_DragonTamerZander_Text_PostRematch:
	.string "One day my dragons will soar\n"
	.string "without limits.\p"
	.string "Until then… I will continue\n"
	.string "to train.$"

