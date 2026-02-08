Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Rufflet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RUFFLET, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Rufflet, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "I heard about a cave called the CAVE\n"
	.string "OF ORIGIN.\p"
	.string "People rumor that the spirits of\n"
	.string "POKéMON are revived there. Could\l"
	.string "something like that really happen?$"

Route119_House_Text_Rufflet:
	.string "RUFFLET: Pihyoh!$"

