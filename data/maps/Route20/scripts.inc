.set LOCALID_ROUTE20_DENNIS, 17
.set LOCALID_ROUTE20_HEADLOCKER, 16

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_TMChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

Route20_EventScript_TMFlameCharge::
	finditem ITEM_TM_FLAME_CHARGE
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lady_Elenore::
	trainerbattle_single TRAINER_ELENORE Route20_Text_ElenoreSeen, Route20_Text_ElenoreBeaten
	msgbox Route20_Text_ElenoreAfter, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA Route20_Text_SheilaSeen, Route20_Text_SheilaBeaten
	msgbox Route20_Text_SheilaAfter, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_SwimmerM_Tony::
	trainerbattle_single TRAINER_TONY Route20_Text_TonySeen, Route20_Text_TonyBeaten
	msgbox Route20_Text_TonyAfter, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "There's a rare POKéMON on this\n"
	.string "route.\p"
	.string "And sometimes it carries a rare\n"
	.string "evolution item.\p"
	.string "That's double rare!\p"
	.string "I need to finish my POKéDEX, so\n"
	.string "I've been fishing here for hours!$"

Route20_Text_Seel:
	.string "SEEL: Seel seel!$"

Route20_Text_Dewgong:
	.string "DEWGONG: Goooong!$"

Route20_Text_SeafoamSign:
	.string "SEAFOAM ISLANDS$"

Route20_Text_SwimmerfNicoleSeen:
	.string "I feel so much lighter in water.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh, no!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "Swimming exercises your full body.\p"
	.string "It's really good for you.$"

Route20_Text_SwimmerfLoriSeen:
	.string "What an impressive collection of\n"
	.string "GYM BADGES. We should battle!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "No!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF is no longer the only HM move\n"
	.string "you use in water.$"

Route20_Text_SwimmermCameronSeen:
	.string "I guess it's impossible to swim\n"
	.string "all the way to JOHTO.$"

Route20_Text_SwimmermCameronBeaten:
	.string "Aiyah!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "Besides the sea, I can also swim\n"
	.string "in ponds and rivers.$"

Route20_Text_ElenoreSeen:
	.string "Ahh… the sun, the sea…\n"
	.string "isn't it simply divine?\p"
	.string "I do so enjoy relaxing here.\p"
	.string "A light battle might be fun.$"

Route20_Text_ElenoreBeaten:
	.string "Oh my…\n"
	.string "How refreshing!$"

Route20_Text_ElenoreAfter:
	.string "There's nothing quite like\n"
	.string "the beach.\p"
	.string "Warm sun, gentle waves…\p"
	.string "...\p"
	.string "Even a battle feels relaxing\n"
	.string "in a place like this.\p"
	.string "You should take your time and\n"
	.string "enjoy it too.$"

Route20_Text_SheilaSeen:
	.string "Careful!\p"
	.string "The currents here can pull you\n"
	.string "off course in a second!\p"
	.string "But I've mastered them.\n"
	.string "Let's see if you can keep up!$"

Route20_Text_SheilaBeaten:
	.string "Oh!\n"
	.string "You didn't drift at all!$"

Route20_Text_SheilaAfter:
	.string "The sea's always moving.\p"
	.string "If you fight against it,\n"
	.string "you'll just wear yourself out.\p"
	.string "Go with the flow-that's the\n"
	.string "trick to both swimming and\n"
	.string "battling.$"

Route20_Text_TonySeen:
	.string "Hey!\n"
	.string "No holding back out here!\p"
	.string "...\p"
	.string "The sea's rough, and so am I!\p"
	.string "I go all out-every time!\n"
	.string "Can you handle that?$"

Route20_Text_TonyBeaten:
	.string "Grr…!\p"
	.string "You hit harder than me…$"

Route20_Text_TonyAfter:
	.string "Battles should be brutal.\p"
	.string "Push hard.\n"
	.string "Hit fast.\p"
	.string "...\p"
	.string "If you hesitate, you lose.\p"
	.string "...\p"
	.string "Heh…\n"
	.string "Guess you didn't hesitate.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "What does this sign say?\p"
	.string "CINNABAR GYM LEADER: BLAINE$"

