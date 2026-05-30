SafariZone_Southwest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

SafariZone_Southwest_EventScript_Woman::
	msgbox SafariZone_Southwest_Text_Woman, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_RestHouseSign::
	msgbox SafariZone_Southwest_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_Southwest_EventScript_Chansey::
	msgbox SafariZone_Southwest_EventScript_Chansey_Text, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_Chansey_Text:
	.string "CHANSEY evolves by FRIENDSHIP to\n"
	.string "BLISSEY. You would first need\l"
	.string "to find one of course.\p"
	.string "CHANSEY is incredibly rare!$"
