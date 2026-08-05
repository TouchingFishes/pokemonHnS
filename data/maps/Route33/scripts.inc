Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_TryRegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_TryRegisterAnthony::
	msgbox Route33_Text_AnthonyRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY
	release
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "I came through the tunnel,\n"
	.string "but I still have plenty\l"
	.string "of energy left.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! You've got more zip\n"
	.string "than me!$"

Route33_Text_HikerAnthony2After:
	.string "We HIKERS are at our best\n"
	.string "in the mountains.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hey, did you get a DUNSPARCE?\p"
	.string "I caught one too.\p"
	.string "Take a look at it in the light.\n"
	.string "It's got a funny face!$"

Route33_Text_AnthonyRegisterPrompt:
	.string "You're a tough trainer!\p"
	.string "I'd like to test my strength\n"
	.string "against you again sometime.\p"
	.string "Can I get your number?$"

Route33_Text_AnthonyRematchIntro:
	.string "There you are!\p"
	.string "I've spent my time climbing these\n"
	.string "mountains and building my strength.\p"
	.string "Let's see if you've gotten stronger,\n"
	.string "too!$"

Route33_Text_AnthonyRematchDefeat:
	.string "Whew! You're strong!\p"
	.string "Looks like I've still got more\n"
	.string "mountains to climb.$"

Route33_Text_AnthonyPostRematch:
	.string "That was a powerful battle!\p"
	.string "I'll keep climbing and training.\n"
	.string "I'll get even stronger!$"


Route33_Text_Lass:
	.string "Pant, pant…\p"
	.string "That cave was bigger than\n"
	.string "I'd expected.\p"
	.string "I got too tired exploring\n"
	.string "for MARILL, so I came outside.$"
