.set LOCALID_RUFFLET, 3

MossdeepCity_House2_MapScripts::
	.byte 0

MossdeepCity_House2_EventScript_Man::
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin::
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Rufflet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RUFFLET, CRY_MODE_NORMAL
	msgbox MossdeepCity_House2_Text_Rufflet, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_RUFFLET_DELIVERED_MAIL
	clearflag FLAG_GARBAGEFLAG
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_RuffletExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_RuffletExitWest
	removeobject LOCALID_RUFFLET
	release
	end

MossdeepCity_House2_EventScript_RuffletExitNorth::
	applymovement LOCALID_RUFFLET, MossdeepCity_House2_Movement_RuffletExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_RuffletExitWest::
	applymovement LOCALID_RUFFLET, MossdeepCity_House2_Movement_RuffletExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_RuffletExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_RuffletExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
	.string "My little sister exchanges MAIL with\n"
	.string "her boyfriend in FORTREE.\p"
	.string "I don't envy her one bit at all.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
	.string "Even though I can't see my friend in\n"
	.string "FORTREE, my POKéMON carries MAIL\l"
	.string "back and forth for us.\p"
	.string "I'm not lonesome, even though we're\n"
	.string "apart.$"

MossdeepCity_House2_Text_Rufflet:
	.string "RUFFLET: Pihyoh!$"

