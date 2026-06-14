StormyBeach_MapScripts::
	.byte 0

StormyBeach_EventScript_HexManiacTammy::
	trainerbattle_single TRAINER_TAMMY, StormyBeach_Text_TammyIntro, StormyBeach_Text_TammyDefeat
	msgbox StormyBeach_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
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

