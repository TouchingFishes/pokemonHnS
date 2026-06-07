Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fisher_Evan::
	trainerbattle_single TRAINER_EVAN Route19_Text_EvanSeen, Route19_Text_EvanBeaten
	msgbox Route19_Text_EvanAfter, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Guitarist_Oscar::
	trainerbattle_single TRAINER_OSCAR Route19_Text_GuitaristOscarSeen, Route19_Text_GuitaristOscarBeaten
	msgbox Route19_Text_GuitaristOscarAfter, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_SwimmerF_Aubree::
	trainerbattle_single TRAINER_AUBREE Route19_Text_AubreeSeen, Route19_Text_AubreeBeaten
	msgbox Route19_Text_AubreeAfter, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Engineer::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_EngineerBefore
	msgbox Route19_Text_Engineer_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_EngineerBefore::
	msgbox Route19_Text_Engineer, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "Have you ever gone swimming in the\n"
	.string "sea at night?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glub…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "At night, the sea turns black. It\n"
	.string "feels like it will swallow you up.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Pant, pant… Just… a little…\p"
	.string "farther… to… FUCHSIA…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "I'm drowning!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "I… asked my girlfriend to swim to\n"
	.string "FUCHSIA… Gasp…$"

Route19_Text_SwimmerfDawnSeen:
	.string "I'm disgusted by wimpy people!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "I could beat you at swimming…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "It's a quick swim between FUCHSIA\n"
	.string "and SEAFOAM ISLANDS…\p"
	.string "Sheesh, some big man my boyfriend\n"
	.string "is! What a wimp!$"

Route19_Text_SwimmermJeromeSeen:
	.string "Swimming? I'm lousy at it.\p"
	.string "I'm just splashing around in these\n"
	.string "shallow waters.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "I thought I could win.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "I might be bad at swimming, but I\n"
	.string "love the sea.$"

Route19_Text_EvanSeen:
	.string "Heh! You're just in time!\p"
	.string "My CRAWDAUNT's about to haul\n"
	.string "in a big one!\p"
	.string "...\p"
	.string "SHELLDER hide tough, but\n"
	.string "nothing gets past its claws!\p"
	.string "...\p"
	.string "Let's see if you can handle\n"
	.string "a real catch!$"

Route19_Text_EvanBeaten:
	.string "What?!\n"
	.string "You reeled me in…$"

Route19_Text_EvanAfter:
	.string "CRAWDAUNT's the best partner\n"
	.string "a fisherman could ask for.\p"
	.string "Strong claws, sharp instincts…\p"
	.string "...\p"
	.string "It drags up the biggest\n"
	.string "SHELLDER from the depths.\p"
	.string "...\p"
	.string "Heh… makes my job easy.$"

Route19_Text_GuitaristOscarSeen:
	.string "Heh! You picked the right spot!\p"
	.string "Out here, the waves crash like\n"
	.string "a live concert!\p"
	.string "...\p"
	.string "And I'm the headliner!\p"
	.string "Let's turn this battle up loud!$"

Route19_Text_GuitaristOscarBeaten:
	.string "No way…!\n"
	.string "I got outplayed on my own stage…$"

Route19_Text_GuitaristOscarAfter:
	.string "A real performer knows when\n"
	.string "they've been outshined.\p"
	.string "...\p"
	.string "You've got presence.\n"
	.string "The kind that draws a crowd.\p"
	.string "...\p"
	.string "Keep that energy.\n"
	.string "It'll take you far.$"

Route19_Text_AubreeSeen:
	.string "Hey! Over here!\p"
	.string "The water's perfect today!\p"
	.string "I've been swimming all day,\n"
	.string "so I'm all warmed up!\p"
	.string "Think you can keep up with me?$"

Route19_Text_AubreeBeaten:
	.string "Aww…!\n"
	.string "You're faster than me…$"

Route19_Text_AubreeAfter:
	.string "Swimming out here feels amazing.\p"
	.string "The waves, the sun… it's the best!\p"
	.string "Battling's more fun when you're\n"
	.string "enjoying yourself too.$"

Route19_Text_Engineer:
	.string "Sorry. This road is closed for\n"
	.string "construction.\p"
	.string "If you want to get to CINNABAR,\n"
	.string "you'd better go south from PALLET\n"
	.string "TOWN.$"

Route19_Text_Kingler:
	.string "KINGLER: KEEEEEEEEEEEE$"

Route19_Text_Engineer_RocksCleared:
	.string "I'm all sweaty. Time for a swim!$"

Route19_Text_FisherBefore:
	.string "No fishing until these KINGLER\n"
	.string "clear out.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Those KINGLER finally left!\p"
	.string "Now I can go fishing again.$"

Route19_Text_Sign:
	.string "ROUTE 19\p"
	.string "FUCHSIA CITY - SEAFOAM ISLANDS$"

Route19_Text_CarefulSwimmingSign:
	.string "Please be careful if you are\n"
	.string "swimming to SEAFOAM ISLANDS.\p"
	.string "FUCHSIA POLICE$"

