Route21_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Sailor_Arturo::
	trainerbattle_single TRAINER_ARTURO Route21_Text_ArturoSeen, Route21_Text_ArturoBeaten
	msgbox Route21_Text_ArturoAfter, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_SwimmerM_Dillon::
	trainerbattle_single TRAINER_DILLON Route21_Text_DillonSeen, Route21_Text_DillonBeaten
	msgbox Route21_Text_DillonAfter, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "Land ho! Gotta keep going!$"

Route21_Text_SwimmermSethBeaten:
	.string "Glug…$"

Route21_Text_SwimmermSethAfterBattle:
	.string "This arrogant guy was at CINNABAR's\n"
	.string "volcano.$"

Route21_Text_SwimmerfNikkiSeen:
	.string "If I win, you have to help me with\n"
	.string "my suntan lotion!$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "I'm worried about sunburn…$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "I have to watch out for blemishes\n"
	.string "caused by the sun.$"

Route21_Text_FisherArnoldSeen:
	.string "I'm bored by fishing. Let's battle!$"

Route21_Text_FisherArnoldBeaten:
	.string "Utter failure…$"

Route21_Text_FisherArnoldAfterBattle:
	.string "I'll just go back to fishing…$"

Route21_Text_ArturoSeen:
	.string "Ho! The sea's rough out here!\p"
	.string "Only tough trainers make it\n"
	.string "this far!\p"
	.string "Let's see if you've got what\n"
	.string "it takes!$"

Route21_Text_ArturoBeaten:
	.string "Gah! You're tougher than\n"
	.string "a storm at sea!$"

Route21_Text_ArturoAfter:
	.string "Out here, there's no room\n"
	.string "for weakness.\p"
	.string "The waves don't care how strong\n"
	.string "you think you are.\p"
	.string "...\p"
	.string "You held your own.\n"
	.string "That's worth respect.$"

Route21_Text_DillonSeen:
	.string "Man, this route just keeps going!\p"
	.string "Perfect for building stamina!\p"
	.string "Hey, you look like you've come\n"
	.string "a long way too.\p"
	.string "Let's test our endurance!$"

Route21_Text_DillonBeaten:
	.string "Whew…!\n"
	.string "I couldn't keep up…$"

Route21_Text_DillonAfter:
	.string "Out here, it's all about\n"
	.string "lasting longer.\p"
	.string "The waves don't stop,\n"
	.string "and neither can you.\p"
	.string "...\p"
	.string "You've got serious endurance.\n"
	.string "I respect that.$"
