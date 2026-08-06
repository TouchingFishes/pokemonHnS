StormyBeach_MapScripts::
	.byte 0

StormyBeach_EventScript_HexManiacTammy::
	trainerbattle_single TRAINER_TAMMY, StormyBeach_Text_TammyIntro, StormyBeach_Text_TammyDefeat, StormyBeach_EventScript_TryRegisterTammy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, StormyBeach_EventScript_RematchTammy
	msgbox StormyBeach_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

StormyBeach_EventScript_RematchTammy::
	trainerbattle_rematch TRAINER_TAMMY, StormyBeach_Text_TammyRematchIntro, StormyBeach_Text_TammyRematchDefeat
	msgbox StormyBeach_Text_TammyPostRematch, MSGBOX_AUTOCLOSE
	end

StormyBeach_EventScript_TryRegisterTammy::
	msgbox StormyBeach_Text_TammyRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_TAMMY
	release
	end

StormyBeach_EventScript_Item_TM_Beat_Up::
	finditem ITEM_TM_BEAT_UP
	end

StormyBeach_Text_TammyIntro:
	.string "The storm whispers… can you\n"
	.string "hear it?\p"
	.string "The waves carry voices from\n"
	.string "far beyond.\p"
	.string "Come… let them watch us\n"
	.string "battle…$"

StormyBeach_Text_TammyDefeat:
	.string "The voices… fell silent…$"

StormyBeach_Text_TammyPostBattle:
	.string "When the thunder fades, the\n"
	.string "spirits drift away.\p"
	.string "But the sea remembers… it\n"
	.string "always remembers…$"

StormyBeach_Text_TammyRegisterPrompt:
	.string "The storm spoke of you before\n"
	.string "you arrived.\p"
	.string "I wish to hear what the waves\n"
	.string "say after another battle.\p"
	.string "May I have your number?$"

StormyBeach_Text_TammyRematchIntro:
	.string "The storm returns…\p"
	.string "The waves have carried your name\n"
	.string "across the endless sea.\p"
	.string "Let us see what the spirits have\n"
	.string "foreseen.$"

StormyBeach_Text_TammyRematchDefeat:
	.string "The voices tremble…\p"
	.string "They knew you would come.$"

StormyBeach_Text_TammyPostRematch:
	.string "The storm does not speak of\n"
	.string "victory or defeat.\p"
	.string "It speaks of change.\p"
	.string "Your bond with your POKéMON is\n"
	.string "stronger than any wave.$"

