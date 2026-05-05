Gate_IlexForest_Route34_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_SweetScentGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SWEET_SCENT, Route34IlexForestGate_EventScript_ReceivedSweetScent

	msgbox Route34IlexForestGate_Text_SweetFragranceTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SWEET_SCENT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull

	setflag FLAG_RECEIVED_TM_SWEET_SCENT
	release
	end

Route34IlexForestGate_EventScript_ReceivedSweetScent::
	goto_if_set FLAG_FINITE_TMS, Route34IlexForestGate_EventScript_ReceivedSweetScentFinite
	msgbox Route34IlexForestGate_Text_TMsCanBeReused, MSGBOX_DEFAULT
	release
	end

Route34IlexForestGate_EventScript_ReceivedSweetScentFinite::
	msgbox Route34IlexForestGate_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_SweetFragranceTakeThis:
	.string "The air near the forest feels\n"
	.string "alive, doesn't it?\p"
	.string "A gentle, sweet scent can draw\n"
	.string "Pokémon out from hiding.\p"
	.string "Take this, and try it for\n"
	.string "yourself.$"

Route34IlexForestGate_Text_TMsCanBeReused:
	.string "TMs can be used as many times\n"
	.string "as you like.$"

Route34IlexForestGate_Text_TMsAreOneTimeUse:
	.string "TMs can only be used once,\n"
	.string "so choose wisely.$"

Route34IlexForestGate_Text_Lass:
	.string "Did you see the shrine honoring\n"
	.string "the protector?\p"
	.string "It watches over the FOREST from\n"
	.string "across time.\p"
	.string "I think that it must be a\n"
	.string "GRASS-type POKéMON.$"

Route34IlexForestGate_Text_Butterfree:
	.string "BUTTERFREE: Freeh!$"
