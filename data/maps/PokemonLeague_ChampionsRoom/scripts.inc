.set LOCALID_LEAGUE_LANCE, 1
.set LOCALID_LEAGUE_MARY, 2
.set LOCALID_LEAGUE_OAK, 3
.set LOCALID_LEAGUE_CHALLENGER, 4

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChampionRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	special DoPokemonLeagueLightingEffect
	end

ChampionRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, ChampionRoom_CloseDoor
	.2byte 0

ChampionRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	setflag FLAG_HIDE_CHAMPION_GAUNTLET_CHALLENGER
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, ChamionRoom_Movement_Enter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	release
	end

ChamionRoom_Movement_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ChampionRoom_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

PokemonLeague_ChampionsRoom_EventScript_Lance::
	lockall
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_LanceRematch
	msgbox PokemonLeague_ChampionsRoom_Text_BattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_1, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_ChampionsRoom_EventScript_LanceOnDefeatJohto

PokemonLeague_ChampionsRoom_EventScript_LanceRematch::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_2, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_ChampionsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_ChampionsRoom_EventScript_LanceOnDefeatJohto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 40
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 60
	msgbox PokemonLeague_ChampionsRoom_Text_MaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_LanceOnDefeatKanto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 40
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 60
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CHAMPION_GAUNTLET_UNLOCKED
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_GauntletEntry::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLooksAround
	waitmovement 0
	goto PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	end

PokemonLeague_ChampionsRoom_EventScript_PickChallenger::
	random 12
	switch VAR_RESULT
	case 0, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	case 1, PokemonLeague_ChampionsRoom_EventScript_TrySlotClair
	case 2, PokemonLeague_ChampionsRoom_EventScript_TrySlotWinona
	case 3, PokemonLeague_ChampionsRoom_EventScript_TrySlotNorman
	case 4, PokemonLeague_ChampionsRoom_EventScript_TrySlotCynthia
	case 5, PokemonLeague_ChampionsRoom_EventScript_TrySlotDrake
	case 6, PokemonLeague_ChampionsRoom_EventScript_TrySlotSteven
	case 7, PokemonLeague_ChampionsRoom_EventScript_TrySlotYama
	case 8, PokemonLeague_ChampionsRoom_EventScript_TrySlotBato
	case 9, PokemonLeague_ChampionsRoom_EventScript_TrySlotGiovanni
	case 10, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	case 11, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance

PokemonLeague_ChampionsRoom_EventScript_TrySlotLance::
	goto PokemonLeague_ChampionsRoom_EventScript_FightLance

PokemonLeague_ChampionsRoom_EventScript_TrySlotClair::
	goto_if_not_defeated TRAINER_CLAIR_2, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightClair

PokemonLeague_ChampionsRoom_EventScript_TrySlotWinona::
	goto_if_not_defeated TRAINER_WINONA_5, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightWinona

PokemonLeague_ChampionsRoom_EventScript_TrySlotNorman::
	goto_if_not_defeated TRAINER_NORMAN-5, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightNorman

PokemonLeague_ChampionsRoom_EventScript_TrySlotCynthia::
	goto_if_not_defeated TRAINER_CYNTHIA, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightCynthia

PokemonLeague_ChampionsRoom_EventScript_TrySlotDrake::
	goto_if_not_defeated TRAINER_CLAIR_2, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightDrake

PokemonLeague_ChampionsRoom_EventScript_TrySlotSteven::
	goto_if_not_defeated TRAINER_STEVEN2, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightSteven

PokemonLeague_ChampionsRoom_EventScript_TrySlotYama::
	goto_if_not_defeated TRAINER_MASTER_YAMA, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightYama

PokemonLeague_ChampionsRoom_EventScript_TrySlotBato::
	goto_if_not_defeated TRAINER_BATO, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightBato

PokemonLeague_ChampionsRoom_EventScript_TrySlotGiovanni::
	goto_if_not_defeated TRAINER_GIOVANNI, PokemonLeague_ChampionsRoom_EventScript_TrySlotLance
	goto PokemonLeague_ChampionsRoom_EventScript_FightGiovanni

PokemonLeague_ChampionsRoom_EventScript_FightLance::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LANCE
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_LanceGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LANCE_2, PokemonLeague_ChampionsRoom_Text_LanceGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_LanceGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightClair::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CLAIR
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_ClairGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_2, PokemonLeague_ChampionsRoom_Text_ClairGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_ClairGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightWinona::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CLAIR
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_WinonaGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WINONA_5, PokemonLeague_ChampionsRoom_Text_WinonaGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_WinonaGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightNorman::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CLAIR
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_NormanGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_5, PokemonLeague_ChampionsRoom_Text_NormanGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_NormanGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightCynthia::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CYNTHIA
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_CynthiaGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CYNTHIA, PokemonLeague_ChampionsRoom_Text_CynthiaGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_CynthiaGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightDrake::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_DrakeGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LANCE_2, PokemonLeague_ChampionsRoom_Text_DrakeGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_DrakeGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightSteven::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_StevenGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN2, PokemonLeague_ChampionsRoom_Text_StevenGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_StevenGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightYama::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_YamaGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MASTER_YAMA, PokemonLeague_ChampionsRoom_Text_YamaGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_YamaGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightBato::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_BatoGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BATO, PokemonLeague_ChampionsRoom_Text_BatoGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_BatoGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_FightGiovanni::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GIOVANNI
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_GiovanniGauntletIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GIOVANNI, PokemonLeague_ChampionsRoom_Text_GiovanniGauntletDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_GiovanniGauntletOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort
	end

PokemonLeague_ChampionsRoom_EventScript_GauntletVictoryEscort::
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakGauntletEscort, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	releaseall
	end


PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest
	waitmovement 0
	return

PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast:
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth:
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest:
	walk_down
	walk_left
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceMoveOver:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_2
	walk_in_place_fast_down
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryMoveOver:
	walk_left
	face_right
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryInterview:
	walk_fast_up
	walk_in_place_fast_right
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceAnxious:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceLeave:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLooksAround:
	emote_question_mark
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_left
	delay_16
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_ChallengerApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_player
	step_end

PokemonLeague_ChampionsRoom_Text_RematchBattleIntro:
    .string "LANCE: Welcome back!\p"
    .string "You've proven yourself in JOHTO,\p"
    .string "acquiring all 8 badges and even\n"
    .string "besting me once.\p"
    .string "But now, you're in the big\n"
    .string "leagues.\p"
    .string "The KANTO LEAGUE!\p"
    .string "A region with its own trials and\n"
    .string "champions.\p"
    .string "Here, I am the final challenge,\n"
    .string "with a team stronger than ever\l"
    .string "before.\p"
    .string "This is the true test,\p"
    .string "a battle to determine the\n"
    .string "CHAMPION of KANTO.\p"
    .string "Are you ready to rise to this new\n"
    .string "challenge?\p"
    .string "To prove yourself once more?\p"
    .string "Show me the strength that\n"
    .string "conquered JOHTO, CHAMPION.$"

PokemonLeague_ChampionsRoom_Text_BattleIntro:
    .string "LANCE: I've been waiting for you.\p"
    .string "{PLAYER}!\p"
    .string "I knew that you, with your skills,\n"
    .string "would eventually reach me here.\p"
    .string "There's no need for words now.\p"
    .string "We will battle to determine who is\n"
    .string "the stronger of the two of us.\p"
    .string "As the most powerful trainer and as\n"
    .string "the POKéMON LEAGUE CHAMPION…\p"
    .string "I, LANCE the dragon master, accept\n"
    .string "your challenge!$"

PokemonLeague_ChampionsRoom_Text_BattleWin:
    .string "…It's over.\p"
    .string "But it's an odd feeling.\p"
    .string "I'm not angry that I lost. In fact,\n"
    .string "I feel happy.\p"
    .string "Happy that I witnessed the rise\n"
    .string "of a great new CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_BattleAfter:
    .string "…Whew.\p"
    .string "You have become truly powerful,\n"
    .string "{PLAYER}.\p"
    .string "Your POKéMON have responded to your\n"
    .string "strong and upstanding nature.\p"
    .string "As a trainer, you will continue to\n"
    .string "grow strong with your POKéMON.$"

PokemonLeague_ChampionsRoom_Text_MaryOhNoOak:
    .string "MARY: Oh, no! It's all over!\p"
    .string "PROF.OAK, if you weren't so slow…$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations:
    .string "PROF.OAK: Ah, {PLAYER}!\p"
    .string "It's been a long while.\p"
    .string "You certainly look more impressive.\p"
    .string "Your conquest of the JOHTO LEAGUE\n"
    .string "is just fantastic!\p"
    .string "Your dedication, trust and love for\n"
    .string "your POKéMON made this happen.\p"
    .string "Your POKéMON were outstanding too.\p"
    .string "Because they believed in you as a\n"
    .string "trainer, they persevered.\p"
    .string "Congratulations, {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations:
    .string "PROF.OAK: Ah, {PLAYER}!\p"
    .string "I've been following your progress\n"
    .string "since PROF.ELM sent you on your\l"
    .string "way.\p"
    .string "You've certainly become more\n"
    .string "impressive.\p"
    .string "Conquering both the JOHTO and now\n"
    .string "the KANTO LEAGUE is no small feat.\p"
    .string "You've truly outdone yourself!\p"
    .string "It's clear that your POKéMON trust\n"
    .string "you immensely,\p"
    .string "and that trust has been the\n"
    .string "foundation of your success.\p"
    .string "But remember, a trainer's journey\n"
    .string "is never truly over.\p"
    .string "Congratulations on your victory,\n"
    .string "{PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_MaryInterview:
    .string "MARY: Let's interview the brand new\n"
    .string "JOHTO CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryInterview:
    .string "MARY: Let's interview the brand new\n"
    .string "KANTO CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_Noisy:
    .string "LANCE: This is getting to be a bit\n"
    .string "too noisy…\p"
    .string "{PLAYER}, could you come with me?$"

PokemonLeague_ChampionsRoom_Text_MaryNoInterview:
    .string "MARY: Oh, wait! We haven't done\n"
    .string "the interview!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview:
    .string "MARY: Come on! You can't blow off\n"
    .string "the interview AGAIN!$"

PokemonLeague_ChampionsRoom_Text_GauntletIntro:
	.string "So you've conquered the LEAGUE…\p"
	.string "But the road of a true CHAMPION\n"
	.string "doesn't end there.\p"
	.string "Beyond these doors, powerful trainers\n"
	.string "await you.\p"
	.string "Each one has stood among the world's\n"
	.string "strongest.\p"
	.string "If you wish to call yourself a CHAMPION,\n"
	.string "prove you can defeat them all!$"

PokemonLeague_ChampionsRoom_Text_LanceGauntletIntro:
	.string "LANCE: So, we meet again.\p"
	.string "You have already proven yourself\n"
	.string "worthy of the title CHAMPION.\p"
	.string "But a title is merely a title.\p"
	.string "Let us see whether your strength\n"
	.string "can withstand the power of DRAGON\n"
	.string "POKéMON once more!$"

PokemonLeague_ChampionsRoom_Text_LanceGauntletDefeat:
	.string "LANCE: Incredible!\p"
	.string "Your strength has grown beyond\n"
	.string "what I imagined.$"

PokemonLeague_ChampionsRoom_Text_LanceGauntletOutro:
	.string "LANCE: I have no doubt now.\p"
	.string "You truly belong among the world's\n"
	.string "greatest trainers.$"

PokemonLeague_ChampionsRoom_Text_ClairGauntletIntro:
	.string "CLAIR: Hmph. So you're the CHAMPION\n"
	.string "everyone keeps talking about.\p"
	.string "Don't expect me to be impressed\n"
	.string "just because you defeated me before.\p"
	.string "This time, I'll show you what a true\n"
	.string "DRAGON MASTER can do!$"

PokemonLeague_ChampionsRoom_Text_ClairGauntletDefeat:
	.string "CLAIR: What?! Again?!\p"
	.string "I refuse to believe you're this strong!$"

PokemonLeague_ChampionsRoom_Text_ClairGauntletOutro:
	.string "CLAIR: …Fine.\p"
	.string "I'll admit it.\n"
	.string "You've earned your place here.$"

PokemonLeague_ChampionsRoom_Text_WinonaGauntletIntro:
	.string "WINONA: The winds carried word of\n"
	.string "your victory to me.\p"
	.string "Yet even the strongest winds can\n"
	.string "change direction without warning.\p"
	.string "Let us take to the skies once more.\p"
	.string "Show me how high a CHAMPION can fly!$"

PokemonLeague_ChampionsRoom_Text_WinonaGauntletDefeat:
	.string "WINONA: The wind has shifted…\p"
	.string "And once again, you stand above me.$"

PokemonLeague_ChampionsRoom_Text_WinonaGauntletOutro:
	.string "WINONA: Magnificent.\p"
	.string "Your spirit soars higher than ever.$"

PokemonLeague_ChampionsRoom_Text_NormanGauntletIntro:
	.string "NORMAN: A CHAMPION should never\n"
	.string "become complacent.\p"
	.string "Strength must be tested constantly,\n"
	.string "or it will begin to fade.\p"
	.string "Come.\n"
	.string "Let us see how strong you've become.$"

PokemonLeague_ChampionsRoom_Text_NormanGauntletDefeat:
	.string "NORMAN: I see…\p"
	.string "Your training has brought you\n"
	.string "considerably farther than before.$"

PokemonLeague_ChampionsRoom_Text_NormanGauntletOutro:
	.string "NORMAN: Excellent.\p"
	.string "Continue challenging yourself.\n"
	.string "That is how true strength is built.$"

PokemonLeague_ChampionsRoom_Text_CynthiaGauntletIntro:
	.string "CYNTHIA: Oh, how wonderful!\p"
	.string "I've been hoping we'd meet again.\p"
	.string "There are few things I enjoy more\n"
	.string "than discovering what makes a\n"
	.string "great trainer truly great.\p"
	.string "Shall we discover it together?$"

PokemonLeague_ChampionsRoom_Text_CynthiaGauntletDefeat:
	.string "CYNTHIA: Ah… extraordinary.\p"
	.string "You've grown even stronger since\n"
	.string "our last battle.$"

PokemonLeague_ChampionsRoom_Text_CynthiaGauntletOutro:
	.string "CYNTHIA: What a fascinating battle.\p"
	.string "I wonder how much farther you can go.\n"
	.string "I certainly hope we meet again.$"

PokemonLeague_ChampionsRoom_Text_DrakeGauntletIntro:
	.string "DRAKE: Ahoy, CHAMPION!\p"
	.string "The sea has taught me one thing:\n"
	.string "no matter how calm it looks,\n"
	.string "a storm can rise at any moment.\p"
	.string "Let's see what kind of storm\n"
	.string "you can bring!$"

PokemonLeague_ChampionsRoom_Text_DrakeGauntletDefeat:
	.string "DRAKE: Ha! What a battle!\p"
	.string "You've got some serious power\n"
	.string "behind you, kid!$"

PokemonLeague_ChampionsRoom_Text_DrakeGauntletOutro:
	.string "DRAKE: Keep sailing forward, CHAMPION.\p"
	.string "There's always another horizon\n"
	.string "waiting beyond the last one.$"

PokemonLeague_ChampionsRoom_Text_StevenGauntletIntro:
	.string "STEVEN: I was curious when I heard\n"
	.string "that you had entered the gauntlet.\p"
	.string "A CHAMPION should never stop seeking\n"
	.string "new challenges.\p"
	.string "Let us test the strength you've\n"
	.string "gathered on your journey.$"

PokemonLeague_ChampionsRoom_Text_StevenGauntletDefeat:
	.string "STEVEN: Fascinating…\p"
	.string "Your strength continues to develop\n"
	.string "like a precious stone under pressure.$"

PokemonLeague_ChampionsRoom_Text_StevenGauntletOutro:
	.string "STEVEN: Wonderful.\p"
	.string "A battle like this reminds me why\n"
	.string "I became a trainer in the first place.$"

PokemonLeague_ChampionsRoom_Text_YamaGauntletIntro:
	.string "YAMA: So, you are the CHAMPION.\p"
	.string "I've heard enough stories about you\n"
	.string "to know that ordinary training\n"
	.string "won't be enough.\p"
	.string "Come, then.\n"
	.string "Show me what you've got.$"

PokemonLeague_ChampionsRoom_Text_YamaGauntletDefeat:
	.string "YAMA: Hah!\p"
	.string "Your strength speaks louder than\n"
	.string "any story I've heard.$"

PokemonLeague_ChampionsRoom_Text_YamaGauntletOutro:
	.string "YAMA: That's the kind of battle\n"
	.string "a warrior remembers.$"

PokemonLeague_ChampionsRoom_Text_BatoGauntletIntro:
	.string "BATO: A CHAMPION at last!\p"
	.string "But titles and trophies mean little\n"
	.string "when the battle actually begins.\p"
	.string "Let us see what lies beneath\n"
	.string "that proud title of yours!$"

PokemonLeague_ChampionsRoom_Text_BatoGauntletDefeat:
	.string "BATO: Hah! You've got more fight\n"
	.string "in you than I expected!$"

PokemonLeague_ChampionsRoom_Text_BatoGauntletOutro:
	.string "BATO: Now that's a battle worth\n"
	.string "remembering.$"

PokemonLeague_ChampionsRoom_Text_GiovanniGauntletIntro:
	.string "GIOVANNI: So… the CHAMPION has come\n"
	.string "to test himself against me.\p"
	.string "How predictable.\p"
	.string "Power is not inherited.\n"
	.string "It is seized by those capable\n"
	.string "of wielding it.\p"
	.string "Come, then.\n"
	.string "Let us see who truly possesses it.$"

PokemonLeague_ChampionsRoom_Text_GiovanniGauntletDefeat:
	.string "GIOVANNI: Hmph…\p"
	.string "It seems your reputation was not\n"
	.string "entirely undeserved.$"

PokemonLeague_ChampionsRoom_Text_GiovanniGauntletOutro:
	.string "GIOVANNI: Enjoy your victory.\p"
	.string "There will always be someone\n"
	.string "stronger waiting beyond it.$"

PokemonLeague_ChampionsRoom_Text_GauntletComplete:
	.string "You have overcome every challenger.\p"
	.string "There is no doubt now.\p"
	.string "You are truly worthy of being called\n"
	.string "a CHAMPION.$"

PokemonLeague_ChampionsRoom_Text_OakGauntletEscort:
	.string "OAK: Well done, {PLAYER}.\p"
	.string "You have successfully defended your\n"
	.string "title as POKéMON CHAMPION.\p"
	.string "But I suspect you already know that\n"
	.string "your work here is far from finished.\p"
	.string "There are trainers who have come from\n"
	.string "far and wide to test themselves\l"
	.string "against the very best.\p"
	.string "And now, they would like to test\n"
	.string "themselves against you.\p"
	.string "I will accompany you to the next\n"
	.string "room, where your next challenger\l"
	.string "will be waiting.\p"
	.string "Take a moment to prepare yourself.\n"
	.string "This will be quite an examination.$"


