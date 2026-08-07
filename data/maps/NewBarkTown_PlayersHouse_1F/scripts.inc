.set LOCALID_MOM, 1
.set LOCALID_MOMS_FRIEND, 2

NewBarkTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_OnTransition
	.byte 0

NewBarkTown_PlayersHouse_1F_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	end

NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_VISITED, NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular
	goto_if_set FLAG_ADVENTURE_STARTED, NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MovementFaceLeft
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, NewBarkTown_PlayersHouse_1F_MovementFaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck::
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	release
	end


NewBarkTown_PlayersHouse_1F_EventScript_Mom_Regular::
	call PlayersHouse_1F_EventScript_MomHealsParty
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomSavings
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomSavings::
	lock
	faceplayer
	special BufferMomSavingsAmount
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomCurrentlyHolding, MSGBOX_DEFAULT
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomWithdrawPrompt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomWithdraw
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomStartSaving
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomWithdraw::
	special WithdrawMomSavings
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomWithdrawDone, MSGBOX_DEFAULT
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomToggleSaving

NewBarkTown_PlayersHouse_1F_EventScript_MomToggleSaving::
	goto_if_set FLAG_MOM_IS_SAVING, NewBarkTown_PlayersHouse_1F_EventScript_MomAskStopSaving
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomAskStartSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomStartSaving
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomStartSaving::
	setflag FLAG_MOM_IS_SAVING
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomSavingsConfirm, MSGBOX_DEFAULT
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomAskStopSaving::
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomStopSavingPrompt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_PlayersHouse_1F_EventScript_MomStopSaving
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomStopSaving::
	clearflag FLAG_MOM_IS_SAVING
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomStoppedSaving, MSGBOX_DEFAULT
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro::
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_1
	waitmovement 0
	msgbox NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear
	call NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@former flagheap location

	releaseall
	end



NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear::
	playfanfare MUS_OBTAIN_ITEM
	message NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return
	
NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::
	msgbox NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_1:
	face_right
	walk_right
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceRight:
	face_right
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceLeft:
	face_left
	step_end

NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou:
	.string "Oh, {PLAYER}…! Our neighbor,\n"
	.string "PROF.ELM, was looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh! I almost forgot! Your POKéGEAR\n"
	.string "is back from the repair shop.\p"
	.string "Here you go!$"

NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear:
	.string "{PLAYER} obtained the POKéGEAR.$"

NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear:
	.string "MOM: Phone numbers are stored\n"
	.string "in memory.\p"
	.string "Just choose a name you want to call.\p"
	.string "Gee, isn't that convenient?$"

NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
	.string "Oh, and don't forget your\n"
	.string "RUNNING SHOES!$"

NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, press the B Button\n"
	.string "while wearing these to run fast!$"

NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting:
	.string "MOM: PROF.ELM is waiting for you.\p"
	.string "Hurry up, baby!$"

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
	.string "Hi, {PLAYER}!\p"
	.string "I'm visiting!\p"
	.string "Have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!$"

NewBarkTown_PlayersHouse_1F_Text_MomLeaving:
	.string "MOM: Wow, that's a cute POKéMON.\n"
	.string "Where did you get it?\p"
	.string "…\p"
	.string "So, you're leaving on an adventure...\n"
	.string "That does sound challenging...\p"
	.string "Just be careful.\p"
	.string "POKéMON are your friends.\n"
	.string "You need to work as a team.\p"
	.string "Now, go on!\n"
	.string "I'm behind you all the way!$"

NewBarkTown_PlayersHouse_1F_Text_MomCurrentlyHolding:
	.string "MOM: Hi, {PLAYER}!\p"
	.string "By the way, I've saved\n"
	.string "{STR_VAR_1} for you.$"

NewBarkTown_PlayersHouse_1F_Text_MomWithdrawPrompt:
	.string "Would you like to take\n"
	.string "your savings?$"

NewBarkTown_PlayersHouse_1F_Text_MomWithdrawDone:
	.string "There you go!\p"
	.string "I transferred everything\n"
	.string "back to you.$"

NewBarkTown_PlayersHouse_1F_Text_MomAskStartSaving:
	.string "Would you like me to keep\n"
	.string "saving your prize money?$"

NewBarkTown_PlayersHouse_1F_Text_MomSavingsConfirm:
	.string "OK!\p"
	.string "I'll put away a little money\n"
	.string "from every battle.\p"
	.string "You can ask me for it\n"
	.string "whenever you come home.$"

NewBarkTown_PlayersHouse_1F_Text_MomStopSavingPrompt:
	.string "You want me to stop\n"
	.string "saving your money?$"

NewBarkTown_PlayersHouse_1F_Text_MomStoppedSaving:
	.string "All right.\p"
	.string "I'll leave your prize money\n"
	.string "with you from now on.$"
