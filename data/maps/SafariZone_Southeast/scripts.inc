.set LOCALID_VOLCARONAMAN, 7

SafariZone_Southeast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

SafariZone_Southeast_GliscorEvo::
	msgbox SafariZone_Southeast_GliscorEvo_Text, MSGBOX_NPC
	end

SafariZone_Southeast_GliscorEvo_Text:
	.string "I love SINNOH POKéMON!\p"
	.string "I need to catch a GLIGAR, so then\n"
	.string "I can get a GLISCOR!\p"
	.string "They evolve only at night,\n"
	.string "just like SNEASEL and MURKROW.$"

SafariZone_Southeast_VolcaronaEvo::
	msgbox SafariZone_Southeast_VolcaronaEvo_Text, MSGBOX_SIGN
	waitmessage
	msgbox SafariZone_Southeast_VolcaronaEvo_Text2, MSGBOX_NPC
	applymovement LOCALID_VOLCARONAMAN, SafariZone_Southeast_VolcaronaEvoMoves
	waitmovement 0
	end

SafariZone_Southeast_VolcaronaEvoMoves:
	face_right
	step_end

SafariZone_Southeast_VolcaronaEvo_Text:
	.string "OH!$"

SafariZone_Southeast_VolcaronaEvo_Text2:
	.string "HAVE YOU SEEN THAT?\p"
	.string "That VOLCARONA was trying to evolve,\n"
	.string "so it was using WATER PULSE!\l"
	.string "Nature is beautiful!$"

@ Event scripts for SafariZone_Southeast are in SafariZone_South/scripts.inc
