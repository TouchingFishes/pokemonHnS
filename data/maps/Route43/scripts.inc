Route43_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Koji::
    trainerbattle_single TRAINER_KOJI, Route43_Text_BugManiacKojiSeen, Route43_Text_BugManiacKojiBeaten, Route43_EventScript_TryRegisterKoji
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchKoji
    msgbox Route43_Text_BugManiacKojiAfter, MSGBOX_AUTOCLOSE
    end

Route43_EventScript_RematchKoji::
    trainerbattle_rematch TRAINER_KOJI, Route43_Text_KojiRematchIntro, Route43_Text_KojiRematchDefeat
    msgbox Route43_Text_KojiPostRematch, MSGBOX_AUTOCLOSE
    end

Route43_EventScript_TryRegisterKoji::
    msgbox Route43_Text_KojiRegisterPrompt, MSGBOX_DEFAULT
    register_matchcall TRAINER_KOJI
    release
    end

Route43_EventScript_Brent::
    trainerbattle_single TRAINER_BRENT, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_TryRegisterBrent
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
    msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
    end

Route43_EventScript_RematchBrent::
    trainerbattle_rematch TRAINER_BRENT, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
    msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
    end

Route43_EventScript_TryRegisterBrent::
    msgbox Route43_Text_BrentRegisterPrompt, MSGBOX_DEFAULT
    register_matchcall TRAINER_BRENT
    release
    end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE Route43_Text_PokeRangerFJulieSeen, Route43_Text_PokeRangerFJulieBeaten
	msgbox Route43_Text_PokeRangerFJulieAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_BugManiacKojiSeen:
    .string "Amazing!\p"
    .string "Have you ever seen BUG POKéMON\n"
    .string "with such beautiful colors?$"

Route43_Text_BugManiacKojiBeaten:
    .string "Incredible!\p"
    .string "Your POKéMON shine brighter than\n"
    .string "the rarest BUG POKéMON!$"

Route43_Text_BugManiacKojiAfter:
    .string "Every BUG POKéMON has its own\n"
    .string "unique colors and patterns.\p"
    .string "That's what makes studying them\n"
    .string "so fascinating!$"

Route43_Text_KojiRegisterPrompt:
    .string "Your POKéMON have something\n"
    .string "special about them.\p"
    .string "I'd love to study their strength\n"
    .string "in another battle.\p"
    .string "Can I get your number?$"

Route43_Text_KojiRematchIntro:
    .string "There you are!\p"
    .string "Since our last battle, I've been\n"
    .string "searching for even more unusual\n"
    .string "BUG POKéMON!\p"
    .string "Now let me show you what I found!$"

Route43_Text_KojiRematchDefeat:
    .string "Wonderful!\p"
    .string "Your POKéMON are just as\n"
    .string "remarkable as rare BUG POKéMON!$"

Route43_Text_KojiPostRematch:
    .string "Strength isn't the only thing that\n"
    .string "makes a POKéMON special.\p"
    .string "Their colors, their habits, and\n"
    .string "their personalities all matter.\p"
    .string "That's why BUG POKéMON are amazing!$"

Route43_Text_PokemaniacBrentSeen:
    .string "Hey! Do you like unusual\n"
    .string "POKéMON?\p"
    .string "I've been studying Pokémon with\n"
    .string "the strangest habits!$"

Route43_Text_PokemaniacBrentBeaten:
    .string "Oh, my poor POKéMON!\p"
    .string "They tried their best!$"

Route43_Text_PokemaniacBrentAfter:
    .string "Some POKéMON are amazing because\n"
    .string "of their strength.\p"
    .string "Others are amazing because of\n"
    .string "their strange personalities.\p"
    .string "That's what makes them special!$"

Route43_Text_BrentRegisterPrompt:
    .string "Your POKéMON are fascinating!\p"
    .string "I'd love to test some of my\n"
    .string "unusual POKéMON against you.\p"
    .string "Can I get your number?$"

Route43_Text_BrentRematchIntro:
    .string "Ah! It's you!\p"
    .string "I've discovered even more rare\n"
    .string "and unusual POKéMON since we met!\p"
    .string "Their abilities might surprise you!$"

Route43_Text_BrentRematchDefeat:
    .string "Amazing!\p"
    .string "My rare POKéMON were wonderful,\n"
    .string "but yours were better!$"

Route43_Text_BrentPostRematch:
    .string "A POKéMON doesn't have to be\n"
    .string "powerful to be incredible.\p"
    .string "The little things that make them\n"
    .string "different are what I love most!$"

Route43_Text_PokemaniacRonSeen:
    .string "Would you get this?\p"
    .string "Some {RIVAL} guy made fun of my\n"
    .string "POKéMON!\p"
    .string "Darn it! My POKéMON's great!$"

Route43_Text_PokemaniacRonBeaten:
    .string "My NIDOKING did pretty right on!$"

Route43_Text_PokemaniacRonAfter:
    .string "It's okay for people to like\n"
    .string "different types of POKéMON.\p"
    .string "POKéMON isn't just about having the\n"
    .string "most powerful one.$"

Route43_Text_FisherMarvinSeen:
    .string "I'm in a slump.\p"
    .string "Maybe it's the gear I'm using.\p"
    .string "Let's battle for a change of pace!$"

Route43_Text_FisherMarvinBeaten:
    .string "I lost, but I feel better anyway.$"

Route43_Text_FisherMarvinAfter:
    .string "KURT's LURE BALL is the best for\n"
    .string "catching hooked POKéMON.\p"
    .string "It's much more effective than a\n"
    .string "ULTRA BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "I can do so much with my\n"
    .string "POKéMON--it's super-fun!$"

Route43_Text_CamperSpencerBeaten:
    .string "Losing isn't fun at all…$"

Route43_Text_CamperSpencerAfter:
    .string "What is going on at LAKE OF RAGE?\p"
    .string "We were planning to camp there.$"

Route43_Text_PokeRangerFJulieSeen:
    .string "Are you heading toward the\n"
    .string "LAKE OF RAGE too?\p"
    .string "I’m surveying the area.\n"
    .string "Let me test your strength!$"

Route43_Text_PokeRangerFJulieBeaten:
    .string "Hmm… I misjudged you.$"

Route43_Text_PokeRangerFJulieAfter:
    .string "I’m observing the Pokémon\n"
    .string "in this region.\p"
    .string "Battling helps me understand\n"
    .string "how they and their Trainers\n"
    .string "work together.$"

Route43_Sign1:
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"

Route43_Sign2:
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"

Route43_TrainerTips:
    .string "TRAINER TIPS\p"
    .string "All POKéMON have pros and cons\n"
    .string "depending on their types.\p"
    .string "If their types differ, a higher-\n"
    .string "level POKéMON may lose in battle.\p"
    .string "Learn which types are strong and\n"
    .string "weak against your POKéMON's type.$"
