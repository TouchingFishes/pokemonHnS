KameHouse_MapScripts::
	.byte 0

KameHouse_EventScript_Torterra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TORTERRA, CRY_MODE_NORMAL
	msgbox KameHouse_Text_Torterra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

KameHouse_EventScript_Torkoal::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
	msgbox KameHouse_Text_Torkoal, MSGBOX_DEFAULT
	waitmoncry
	release
	end

KameHouse_Text_Torterra:
	.string "TORTERRA: Torr-Torr!$"

KameHouse_Text_Torkoal:
	.string "TORKOAL: Tssss-Tssss$"
