NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_SIGNAL_BEAM, NewBarkTown_House1_EventScript_DaughterAfter
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	goto_if_unset FLAG_DEFEATED_BLACKTHORN_GYM, NewBarkTown_House1_EventScript_DaughterEnd
	msgbox NewBarkTown_House1_Text_OfferSignalBeam, MSGBOX_DEFAULT
	giveitem ITEM_TM_SIGNAL_BEAM
	setflag FLAG_GOT_TM_SIGNAL_BEAM
	msgbox NewBarkTown_House1_Text_ReceivedSignalBeam, MSGBOX_DEFAULT
	release
	end

NewBarkTown_House1_EventScript_DaughterEnd::
	release
	end

NewBarkTown_House1_EventScript_DaughterAfter::
	msgbox NewBarkTown_House1_Text_After, MSGBOX_DEFAULT
	release
	end

NewBarkTown_House1_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox NewBarkTown_House1_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "My BUTTERFREE is amazing…\p"
	.string "It started out as a tiny CATERPIE,\n"
	.string "barely able to do anything.\p"
	.string "Then it became METAPOD…\n"
	.string "just waiting and waiting…\p"
	.string "And now look at it!\n"
	.string "Graceful, strong, and so reliable.\p"
	.string "PROF.ELM says evolution brings out\n"
	.string "a POKéMON's hidden potential.\p"
	.string "…sigh…\p"
	.string "I wish I could study POKéMON\n"
	.string "like he does…$"

NewBarkTown_House1_Text_OfferSignalBeam:
	.string "Oh! You've come so far already!\p"
	.string "If my BUTTERFREE were with you,\n"
	.string "it would want to help.\p"
	.string "Here… this move is something it\n"
	.string "learned along the way.\p"
	.string "It might help your POKéMON too.$"

NewBarkTown_House1_Text_ReceivedSignalBeam:
	.string "That move is SIGNAL BEAM.\p"
	.string "It may look gentle…\n"
	.string "but it can confuse your foes and\l"
	.string "turn battles around.\p"
	.string "Please use it well!$"

NewBarkTown_House1_Text_After:
	.string "BUTTERFREE always believed in\n"
	.string "growing stronger, step by step.\p"
	.string "I'm sure your POKéMON will too.$"


NewBarkTown_House1_Text_Neighbor:
	.string "My daughter is adamant about\n"
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!\p"
	.string "But then, so do I!$"

NewBarkTown_House1_Text_Butterfree:
	.string "BUTTERFREE: Freeh!$"

