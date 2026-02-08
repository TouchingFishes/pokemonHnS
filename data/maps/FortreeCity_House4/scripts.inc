.set LOCALID_RUFFLET, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_RUFFLET_DELIVERED_MAIL, FortreeCity_House4_EventScript_RuffletReturned
	goto_if_set FLAG_RUFFLET_SENT_ON_ERRAND, FortreeCity_House4_EventScript_RuffletOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RUFFLET_SENT_ON_ERRAND
	clearflag FLAG_GARBAGEFLAG
	applymovement LOCALID_RUFFLET, FortreeCity_House4_Movement_RuffletExit
	waitmovement 0
	removeobject LOCALID_RUFFLET
	releaseall
	end

FortreeCity_House4_EventScript_RuffletOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedRuffletToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_RuffletReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeRuffletTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToRufflet, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_RuffletExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Rufflet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RUFFLET, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Rufflet, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "By being together with POKéMON,\n"
	.string "people make more and more friends.\p"
	.string "And that brings the world closer\n"
	.string "together. I think it's wonderful!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "There!\n"
	.string "Go, BIRD POKéMON!$"

FortreeCity_House4_Text_AskedRuffletToRunErrand:
	.string "Heheh, I asked my RUFFLET to run\n"
	.string "an errand for me.$"

FortreeCity_House4_Text_WelcomeRuffletTakeMentalHerb:
	.string "Good!\n"
	.string "Welcome back, RUFFLET!\p"
	.string "Huh? What is this?\n"
	.string "What is it holding?\p"
	.string "A MENTAL HERB?\n"
	.string "It must have picked it up somewhere.\p"
	.string "But I'm not a TRAINER, so you can\n"
	.string "have it.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToRufflet:
	.string "Thanks to my RUFFLET, I have friends\n"
	.string "who live far away.$"

FortreeCity_House4_Text_Rufflet:
	.string "RUFFLET: Pihyoh!$"

