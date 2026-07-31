Kiwame_House_MapScripts::
	.byte 0

KiwameHouse_EventScript_UltimateKiwameHouse::
	lock
	faceplayer
	msgbox KiwameHouse_Text_UltimateTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KiwameHouse_EventScript_UltimateDeclined
	multichoice 20, 0, MULTI_ULTIMATE_MOVE_CHOICE, FALSE
	switch VAR_RESULT
	case 0, KiwameHouse_EventScript_GrassChosen
	case 1, KiwameHouse_EventScript_FireChosen
	case 2, KiwameHouse_EventScript_WaterChosen
	case 3, KiwameHouse_EventScript_UltimateDeclined
	case MULTI_B_PRESSED, NewBarkTown_Lab_EventScript_JohtoChosen

KiwameHouse_EventScript_GrassChosen:
	msgbox KiwameHouse_Text_UltimateWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FRENZY_PLANT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, KiwameHouse_EventScript_UltimateDeclined
	msgbox KiwameHouse_Text_UltimateTaught_Grass, MSGBOX_DEFAULT
	release
	end

KiwameHouse_EventScript_FireChosen:
	msgbox KiwameHouse_Text_UltimateWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_BLAST_BURN
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, KiwameHouse_EventScript_UltimateDeclined
	msgbox KiwameHouse_Text_UltimateTaught_Fire, MSGBOX_DEFAULT
	release
	end

KiwameHouse_EventScript_WaterChosen:
	msgbox KiwameHouse_Text_UltimateWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_HYDRO_CANNON
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, KiwameHouse_EventScript_UltimateDeclined
	msgbox KiwameHouse_Text_UltimateTaught_Water, MSGBOX_DEFAULT
	release
	end

KiwameHouse_EventScript_UltimateDeclined::
	msgbox KiwameHouse_Text_UltimateDeclined, MSGBOX_DEFAULT
	release
	end

KiwameHouse_Text_UltimateTeach:
	.string "Long before trainers walked\n"
	.string "this world… the elements raged\n"
	.string "unchecked.\p"
	.string "From that chaos were forged\n"
	.string "three forbidden arts…\p"
	.string "Grass. Fire. Water.\n"
	.string "Power enough to shatter even\n"
	.string "the strongest foes.\p"
	.string "Few remain who can teach them.\n"
	.string "Fewer still who survive them.\p"
	.string "Tell me… will you claim this\n"
	.string "power, and bear its burden?$"

KiwameHouse_Text_UltimateWhichMon:
	.string "Do not choose lightly.\p"
	.string "The one you select will carry\n"
	.string "a force beyond restraint…\p"
	.string "Which Pokémon will stand at\n"
	.string "the edge of true greatness?$"

KiwameHouse_Text_UltimateDeclined:
	.string "A wise hesitation…\p"
	.string "Power like this is not meant\n"
	.string "for the unprepared.\p"
	.string "Return when your resolve no\n"
	.string "longer falters.$"

KiwameHouse_Text_UltimateTaught_Grass:
	.string "The forest stirs…\p"
	.string "Roots coil beneath the earth,\n"
	.string "ancient and unyielding.\p"
	.string "Frenzy Plant does not simply\n"
	.string "strike… it buries.\p"
	.string "Let your foe be swallowed by\n"
	.string "nature's wrath…\p"
	.string "But remember-once awakened,\n"
	.string "it does not easily rest.$"

KiwameHouse_Text_UltimateTaught_Fire:
	.string "The flames answer…\p"
	.string "A fire born not of warmth,\n"
	.string "but of mastery.\p"
	.string "Blast Burn scorches all in its\n"
	.string "path-leaving nothing behind.\p"
	.string "Wield it, and even victory may\n"
	.string "taste of ash…\p"
	.string "For such flames care not who\n"
	.string "they consume.$"

KiwameHouse_Text_UltimateTaught_Water:
	.string "The tides rise…\p"
	.string "A crushing force, deep as the\n"
	.string "endless abyss.\p"
	.string "Hydro Cannon strikes like the\n"
	.string "roar of the ocean itself.\p"
	.string "Nothing withstands its fury…\n"
	.string "nothing escapes its pull.\p"
	.string "Yet even the sea demands\n"
	.string "tribute from those who command it.$"

KiwameHouse_Text_UltimateTaught:
	.string "The element answers your call…\p"
	.string "But heed this-such power\n"
	.string "demands a heavy cost.\p"
	.string "Strike at the perfect moment,\n"
	.string "and victory will be yours.$"

