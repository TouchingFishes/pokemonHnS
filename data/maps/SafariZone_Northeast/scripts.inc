SafariZone_Northeast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SafariZone_Northeast_DecibelleEvo::
	msgbox SafariZone_Northeast_DecibelleEvo_Text, MSGBOX_NPC
	end

SafariZone_Northeast_DecibelleEvo_Text:
	.string "I love the POKéMON AIPOM!\n"
	.string "They are so cute!\l"
	.string "But did you know that they can evolve?\p"
	.string "If you use a move that makes\n"
	.string "everyone laugh, it will evolve!\p"
	.string "And it's still lovely!$"

@ Event scripts for SafariZone_Northeast are in SafariZone_South/scripts.inc
