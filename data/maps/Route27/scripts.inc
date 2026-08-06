.set LOCALID_ROUTE27_FATMAN, 1

Route27_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_SolarBeam::
    finditem ITEM_TM_SOLAR_BEAM
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
    trainerbattle_single TRAINER_REENA, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_TryRegisterReena
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
    msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
    end

Route27_EventScript_RematchReena::
    trainerbattle_rematch TRAINER_REENA, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
    msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
    end

Route27_EventScript_TryRegisterReena::
    msgbox Route27_Text_ReenaRegisterPrompt, MSGBOX_DEFAULT
    register_matchcall TRAINER_REENA
    release
    end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
    trainerbattle_single TRAINER_JOSE, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_TryRegisterJose
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
    msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
    end

Route27_EventScript_RematchJose::
    trainerbattle_rematch TRAINER_JOSE, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
    msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
    end

Route27_EventScript_TryRegisterJose::
    msgbox Route27_Text_JoseRegisterPrompt, MSGBOX_DEFAULT
    register_matchcall TRAINER_JOSE
    release
    end

Route27_EventScript_Monika::
	trainerbattle_single TRAINER_MONIKA Route27_Text_MonikaSeen, Route27_Text_MonikaBeaten
	msgbox Route27_Text_MonikaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "Hey!$"

Route27_Text_FisherMessage:
    .string "Do you know what you just did?\p"
    .string "You've taken your first step into\n"
    .string "KANTO.\p"
    .string "Check your POKéGEAR MAP and see.$"

Route27_Text_CooltrainermBlakeSeen:
    .string "You look pretty strong.\n"
    .string "Let me battle you!$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "Yow!$"

Route27_Text_CooltrainermBlakeAfter:
    .string "If you prevail on this harsh trek,\n"
    .string "the truth will be revealed!\p"
    .string "Heh, sorry, I just wanted to say\n"
    .string "something cool.$"

Route27_Text_CooltrainermBrianSeen:
    .string "Hm? You're good, aren't you?$"

Route27_Text_CooltrainermBrianBeaten:
    .string "Just as I thought!$"

Route27_Text_CooltrainermBrianAfter:
    .string "A good trainer can recognize other\n"
    .string "good trainers.$"

Route27_Text_CooltrainerfReenaSeen:
    .string "You shouldn't underestimate the\n"
    .string "wild POKéMON in these parts.$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "Oh! You're much too strong!$"

Route27_Text_CooltrainerfReenaAfter:
    .string "You're just a kid, but you're not\n"
    .string "to be underestimated either.$"

Route27_Text_ReenaRegisterPrompt:
    .string "You have a lot of talent for a\n"
    .string "young trainer.\p"
    .string "I'd like to battle you again and\n"
    .string "see how much you've grown.\p"
    .string "Can I get your number?$"

Route27_Text_ReenaRematchIntro:
    .string "I knew we'd meet again.\p"
    .string "I've continued training in these\n"
    .string "wild areas.\p"
    .string "Let's see if I've improved since\n"
    .string "our last battle.$"

Route27_Text_ReenaRematchDefeat:
    .string "You're still ahead of me.\p"
    .string "I won't underestimate you again.$"

Route27_Text_ReenaPostRematch:
    .string "Strength isn't just about power.\p"
    .string "It's about knowing your Pokémon\n"
    .string "and trusting their abilities.\p"
    .string "I'll remember that.$"

Route27_Text_CooltrainerfMeganSeen:
    .string "It's rare to see anyone come here.\p"
    .string "Are you training on your own?$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "Oh! You're really strong!$"

Route27_Text_CooltrainerfMeganAfter:
    .string "I'm checking out pre- and post-\n"
    .string "evolution POKéMON.\p"
    .string "Evolution really does make\n"
    .string "POKéMON stronger.\p"
    .string "But evolved forms also learn\n"
    .string "moves later on.$"

Route27_Text_PsychicGilbertSeen:
    .string "Don't say a thing!\p"
    .string "Let me guess what you're thinking.\p"
    .string "Mmmmmmm…\p"
    .string "I got it! You're on the POKéMON\n"
    .string "LEAGUE challenge!$"

Route27_Text_PsychicGilbertBeaten:
    .string "You're too much!$"

Route27_Text_PsychicGilbertAfter:
    .string "With your skills, you'll do well at\n"
    .string "the LEAGUE.\p"
    .string "That's what my premonition says.$"

Route27_Text_BirdKeeperJoseSeen:
    .string "Tweet! Tweet! Tetweet!$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "Tweet!$"

Route27_Text_BirdKeeperJoseAfter:
    .string "BIRD KEEPERS like me mimic bird\n"
    .string "whistles to command POKéMON.$"

Route27_Text_JoseRegisterPrompt:
    .string "Tweet! Tweet!\p"
    .string "Your POKéMON and you seem to\n"
    .string "understand each other well.\p"
    .string "I'd like to learn from another\n"
    .string "battle.\p"
    .string "Can I get your number?$"

Route27_Text_JoseRematchIntro:
    .string "Tweet! Tweet! Tetweet!\p"
    .string "My birds and I have practiced new\n"
    .string "calls since we last met.\p"
    .string "Let's see if we can communicate\n"
    .string "better in battle!$"

Route27_Text_JoseRematchDefeat:
    .string "Tweet...\p"
    .string "I suppose my birds still have more\n"
    .string "to learn.$"

Route27_Text_JosePostRematch:
    .string "A trainer and POKéMON become\n"
    .string "stronger by understanding each\n"
    .string "other.\p"
    .string "I'll keep listening to my birds!$"

Route27_Text_MonikaSeen:
	.string "You there.\p"
	.string "I've been searching for someone\n"
	.string "worth my time.\p"
	.string "Show me your strength.$"

Route27_Text_MonikaBeaten:
	.string "Good...\p"
	.string "You didn't disappoint.$"

Route27_Text_MonikaAfter:
	.string "Most trainers crumble under\n"
	.string "pressure.\p"
	.string "You stood your ground.\p"
	.string "...\p"
	.string "If you keep training like that,\n"
	.string "you might go far.\p"
	.string "Don't get complacent.$"

TohjoFalls_Text_Sign:
    .string "TOHJO FALLS\p"
    .string "THE LINK BETWEEN KANTO AND JOHTO$"

Route27_Text_FisherScottSeen:
    .string "I'm feeling great today!\p"
    .string "I feel like I could boot even the\n"
    .string "LEAGUE CHAMP!$"

Route27_Text_FisherScottBeaten:
    .string "No! Not in this battle!$"

Route27_Text_FisherScottAfter:
    .string "Just like in fishing, it's all over\n"
    .string "in POKéMON if you give up.$"
