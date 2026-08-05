Route35_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_PokerangerMIvan::
	trainerbattle_single TRAINER_IVAN Route35_Text_PokerangerMIvanSeen, Route35_Text_PokerangerMIvanBeaten
	msgbox Route35_Text_PokerangerMIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_AromaLadyHana::
	trainerbattle_single TRAINER_KIM Route35_Text_AromaLadyHanaSeen, Route35_Text_AromaLadyHanaBeaten
	msgbox Route35_Text_AromaLadyHanaAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_TryRegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_TryRegisterArnie::
	msgbox Route35_Text_ArnieRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE
	release
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_GuitaristSu::
	trainerbattle_single TRAINER_SU, Route35_Text_SuSeenText, Route35_Text_SuBeatenText, Route35_EventScript_TryRegisterSu
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchSu
	msgbox Route35_Text_SuAfterBattleText, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RematchSu::
	trainerbattle_rematch TRAINER_SU, Route35_Text_SuRematchIntro, Route35_Text_SuRematchDefeat
	msgbox Route35_Text_SuPostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_TryRegisterSu::
	msgbox Route35_Text_SuRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_SU
	release
	end

Route35_EventScript_BreederM_Cory::
	trainerbattle_single TRAINER_CORY, Route35_Text_CoryIntro, Route35_Text_CoryDefeat
	msgbox Route35_Text_CoryPostBattle, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_PokerangerMIvanSeen:
	.string "I've been getting POKéMON data off\n"
	.string "my radio. I think I'm good.$"

Route35_Text_PokerangerMIvanBeaten:
	.string "I give!$"

Route35_Text_PokerangerMIvanAfter:
	.string "Music on the radio changes the\n"
	.string "moods of wild POKéMON.$"

Route35_Text_CamperElliotSeen:
	.string "I'm gonna show my girlfriend I'm\n"
	.string "hot stuff!$"

Route35_Text_CamperElliotBeaten:
	.string "I wish you would have lost for me…$"

Route35_Text_CamperElliotAfter:
	.string "I was humiliated in front of my\n"
	.string "girlfriend…$"

Route35_Text_PicnickerBrookeSeen:
	.string "My boyfriend's weak, so I can't rely\n"
	.string "on him.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "Oh, my! You're so strong!$"

Route35_Text_PicnickerBrookeAfter:
	.string "I can count on my POKéMON more than\n"
	.string "my boyfriend.$"

Route35_Text_AromaLadyHanaSeen:
	.string "Mmm, the fragrance of my\n"
    .string "CHIKORITA is divine!$"

Route35_Text_AromaLadyHanaBeaten:
	.string "Oh no! My sweet CHIKORITA...$"

Route35_Text_AromaLadyHanaAfter:
	.string "Remember, a gentle heart and\n"
    .string "a lovely fragrance can calm all.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "What kinds of BALLS do you use?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "Yikes! Not fast enough!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Some POKéMON flee right away.\p"
	.string "Try catching them with KURT's\n"
	.string "FAST BALL.\p"
	.string "Whenever I find a ASPEAR BERRY, I\n"
	.string "take it to KURT.\p"
	.string "He turns it into a custom BALL.$"

Route35_Text_JugglerIrwinSeen:
	.string "Behold my graceful BALL dexterity!$"

Route35_Text_JugglerIrwinBeaten:
	.string "Whew! That was a jolt!$"

Route35_Text_JugglerIrwinAfter:
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"

Route35_Text_BugCatcherArnieSeen:
	.string "I'll go anywhere if BUG POKéMON\n"
	.string "appear there.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "Huh? I shouldn't have lost that…$"

Route35_Text_BugCatcherArnieAfter:
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Wow… Look at all those YANMA!\p"
	.string "I'm so blown away, I can't move.$"

Route35_Text_ArnieRegisterPrompt:
	.string "You're a pretty interesting trainer!\p"
	.string "I'd like to see how my BUG POKéMON\n"
	.string "match up against you again.\p"
	.string "Can I get your number?$"

Route35_Text_ArnieRematchIntro:
	.string "I've been traveling all over\n"
	.string "looking for rare BUG POKéMON!\p"
	.string "I've learned a lot since our last\n"
	.string "battle.\p"
	.string "Let's see how my POKéMON have grown!$"

Route35_Text_ArnieRematchDefeat:
	.string "Huh? I shouldn't have lost that\n"
	.string "again…$"

Route35_Text_ArniePostRematch:
	.string "Every battle teaches me something\n"
	.string "new about raising BUG POKéMON.\p"
	.string "I'll keep searching for stronger\n"
	.string "bugs wherever I go!$"

Route35_Text_FirebreatherWaltSeen:
	.string "I'm practicing my fire breathing.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "Ow! I scorched the tip of my nose!$"

Route35_Text_FirebreatherWaltAfter:
	.string "The POKéMON March on the radio\n"
	.string "lures wild POKéMON.$"

Route35_Text_OfficerDirkSeen:
	.string "Danger lurks in the night!$"

Route35_Text_OfficerDirkBeaten:
	.string "Whoops!$"

Route35_Text_OfficerDirkAfter:
	.string "You know, night time is fun in its\n"
	.string "own ways.\p"
	.string "But don't overdo it, OK?$"

Route35_Text_OfficerDirkTough:
	.string "Your POKéMON look pretty tough.\p"
	.string "You could go anywhere safely.$"

Route35_Text_SuSeenText:
    .string "Ah... I just want to relax\n"
    .string "by the berry trees...$"

Route35_Text_SuBeatenText:
    .string "Hmm... even music can't save me now.$"

Route35_Text_SuAfterBattleText:
    .string "Sometimes, escaping the city\n"
    .string "is the best way to find your rhythm.$"

Route35_Text_SuRegisterPrompt:
	.string "You're pretty good!\p"
	.string "I'd like to battle you again\n"
	.string "sometime.\p"
	.string "Can I get your number?$"

Route35_Text_SuRematchIntro:
	.string "Ah... there you are.\p"
	.string "I've been relaxing by the berry\n"
	.string "trees and practicing my music.\p"
	.string "Let's see if I can find my rhythm\n"
	.string "in battle, too.$"

Route35_Text_SuRematchDefeat:
	.string "Hmm... I still couldn't find\n"
	.string "the right rhythm.$"

Route35_Text_SuPostRematch:
	.string "That battle gave me a new idea\n"
	.string "for a song…\p"
	.string "I'd like to battle you again when\n"
	.string "I've found the right rhythm.\p"
	.string "Can I get your number?$"

Route35_Text_CoryIntro:
	.string "I just picked up my POKéMON from\n"
	.string "the DAY-CARE!\p"
	.string "They're still little, but they've\n"
	.string "got a lot of energy!$"

Route35_Text_CoryDefeat:
	.string "Whoa, you're way ahead of me!\n"
	.string "My POKéMON are still babies…$"

Route35_Text_CoryPostBattle:
	.string "Raising baby POKéMON takes time,\n"
	.string "but it's worth every moment.\p"
	.string "The DAY-CARE helps them grow,\n"
	.string "even when I'm not around!$"

Route35_Text_Sign:
	.string "ROUTE 35$"

Route35_Text_Sign2:
	.string "NATIONAL PARK GATE$"
