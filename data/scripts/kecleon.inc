Route120_EventScript_Psychu1::
	lock
	faceplayer
	setvar VAR_0x8009, 1
	goto EventScript_Psychu
	end

Route120_EventScript_Psychu2::
	lock
	faceplayer
	setvar VAR_0x8009, 2
	goto EventScript_Psychu
	end

Route120_EventScript_Psychu3::
	lock
	faceplayer
	setvar VAR_0x8009, 3
	goto EventScript_Psychu
	end

Route120_EventScript_Psychu4::
	lock
	faceplayer
	setvar VAR_0x8009, 4
	goto EventScript_Psychu
	end

Route120_EventScript_Psychu5::
	lock
	faceplayer
	setvar VAR_0x8009, 5
	goto EventScript_Psychu
	end

Route119_EventScript_Psychu1::
	lock
	faceplayer
	setvar VAR_0x8009, 6
	goto EventScript_Psychu
	end

Route119_EventScript_Psychu2::
	lock
	faceplayer
	setvar VAR_0x8009, 7
	goto EventScript_Psychu
	end

EventScript_Psychu::
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, EventScript_AskUseDevonScope
	msgbox Psychu_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

EventScript_AskUseDevonScope::
	msgbox Psychu_Text_WantToUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BattlePsychu
	release
	end

EventScript_BattlePsychu::
	msgbox Psychu_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Movement_PsychuAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_PSYCHU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_PSYCHU, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemovePsychu
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EventScript_RemovePsychu
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, EventScript_RemovePsychu
	release
	end

EventScript_RemovePsychu::
	goto Common_EventScript_RemoveStaticPokemon
	end

Movement_PsychuAppears:
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end
