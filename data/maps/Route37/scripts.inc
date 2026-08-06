Route37_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_BreederFAmala::
	trainerbattle_single TRAINER_AMALA, Route37_Text_BreederFAmala_Seen, Route37_Text_BreederFAmala_Beaten, Route37_EventScript_TryRegisterAmala
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route37_EventScript_RematchAmala
	msgbox Route37_Text_BreederFAmala_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_RematchAmala::
	trainerbattle_rematch TRAINER_AMALA, Route37_Text_AmalaRematchIntro, Route37_Text_AmalaRematchDefeat
	msgbox Route37_Text_AmalaPostRematch, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_TryRegisterAmala::
	msgbox Route37_Text_AmalaRegisterPrompt, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMALA
	release
	end

Route37_EventScript_ChannelerMercy::
	trainerbattle_single TRAINER_MERCY, Route37_Text_ChannelerMercy_Seen, Route37_Text_ChannelerMercy_Beaten
	msgbox Route37_Text_ChannelerMercy_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_BugManiacValery::
	trainerbattle_single TRAINER_VALERY, Route37_Text_BugManiacValery_Seen, Route37_Text_BugManiacValery_Beaten
	msgbox Route37_Text_BugManiacValery_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_CamperJordan::
	trainerbattle_single TRAINER_JORDAN, Route37_Text_CamperJordan_Seen, Route37_Text_CamperJordan_Beaten
	msgbox Route37_Text_CamperJordan_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_BugCatcherMicky::
	trainerbattle_single TRAINER_MICKY, Route37_Text_BugCatcherMicky_Seen, Route37_Text_BugCatcherMicky_Beaten
	msgbox Route37_Text_BugCatcherMicky_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_Item_GrassKnot::
	finditem ITEM_TM_GRASS_KNOT
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANN: ANNE and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANN: I can tell what my sister and\n"
	.string "my POKéMON are thinking.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANNE: ANN and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANNE: We share the same feelings as\n"
	.string "our POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "POKéMON can't do a thing if they are\n"
	.string "asleep.\p"
	.string "I'll show you how scary that is!$"

Route37_Text_PsychicGreg_Beaten:
	.string "I lost. That's pretty sad…$"

Route37_Text_PsychicGreg_After:
	.string "Putting POKéMON to sleep or paralyz-\n"
	.string "ing them are good battle techniques.$"

Route37_Text_BreederFAmala_Seen:
	.string "A well-raised POKéMON is a happy\n"
	.string "POKéMON!\p"
	.string "Come on, let's see how our\n"
	.string "partners have grown!$"

Route37_Text_BreederFAmala_Beaten:
	.string "You and your POKéMON have\n"
	.string "grown wonderfully together!$"

Route37_Text_BreederFAmala_After:
	.string "Raising POKéMON isn't just about\n"
	.string "making them stronger.\p"
	.string "The trust you build together is\n"
	.string "what wins the toughest battles.$"

Route37_Text_AmalaRegisterPrompt:
	.string "Your POKéMON seem very happy\n"
	.string "with you.\p"
	.string "I'd love to see how your bond\n"
	.string "continues to grow.\p"
	.string "Can I get your number?$"

Route37_Text_AmalaRematchIntro:
	.string "It's wonderful to see you again!\p"
	.string "I've spent time caring for my\n"
	.string "POKéMON and learning more about\n"
	.string "what they need.\p"
	.string "Let's see how our partners have\n"
	.string "grown!$"

Route37_Text_AmalaRematchDefeat:
	.string "What a beautiful battle.\p"
	.string "Your POKéMON trust you completely.$"

Route37_Text_AmalaPostRematch:
	.string "A strong trainer isn't someone who\n"
	.string "only gives commands.\p"
	.string "A strong trainer understands their\n"
	.string "POKéMON and grows with them.$"

Route37_Text_ChannelerMercy_Seen:
	.string "Can you feel it?\p"
	.string "The forest whispers to believers.\n"
	.string "Even SHUPPET is listening.\p"
	.string "Come. Let the spirits judge\n"
	.string "our battle.$"

Route37_Text_ChannelerMercy_Beaten:
	.string "The forest has spoken...\n"
	.string "Today, it favored you.$"

Route37_Text_ChannelerMercy_After:
	.string "When the wind stirs the leaves,\n"
	.string "SHUPPET always looks up.\p"
	.string "Perhaps it hears voices that\n"
	.string "we've long forgotten.$"

Route37_Text_BugManiacValery_Seen:
	.string "Shh! Keep your voice down!\p"
	.string "I'm waiting for a rare BUG\n"
	.string "POKéMON to fall out of a tree.\p"
	.string "Since you're here anyway,\n"
	.string "let's battle while we wait!$"

Route37_Text_BugManiacValery_Beaten:
	.string "Aw, now I've scared them all\n"
	.string "away...$"

Route37_Text_BugManiacValery_After:
	.string "Headbutting trees is an art.\p"
	.string "You never know whether a common\n"
	.string "BUG or something truly rare will\l"
	.string "come tumbling down.$"

Route37_Text_CamperJordan_Seen:
	.string "Isn't this forest awesome?\p"
	.string "I could spend all day looking\n"
	.string "at these colorful trees!\p"
	.string "A battle's even more fun with\n"
	.string "a view like this!$"

Route37_Text_CamperJordan_Beaten:
	.string "Whoa! That was as bright as\n"
	.string "the leaves overhead!$"

Route37_Text_CamperJordan_After:
	.string "Every season gives these trees\n"
	.string "new colors.\p"
	.string "No wonder so many POKéMON\n"
	.string "choose to live here.$"

Route37_Text_BugCatcherMicky_Seen:
	.string "BUG POKéMON are the best!\p"
	.string "They're always hiding somewhere,\n"
	.string "just waiting to surprise you!\p"
	.string "Let's see if mine surprise you!$"

Route37_Text_BugCatcherMicky_Beaten:
	.string "Aw... I guess my bugs weren't\n"
	.string "sneaky enough.$"

Route37_Text_BugCatcherMicky_After:
	.string "People walk right past BUG\n"
	.string "POKéMON all the time.\p"
	.string "If you slow down and really look,\n"
	.string "they're everywhere!$"

Route37_Text_Sunny_Meet:
	.string "SUNNY: Hi!\p"
	.string "I'm SUNNY of the WEEKDAY family!\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route37_Text_Sunny_GiveGift1:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GiveGift2:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GaveGift:
	.string "SUNNY: That thing…\p"
	.string "Um…\p"
	.string "… What was it now…\p"
	.string "…\p"
	.string "Oh! I remember now!\p"
	.string "A POKéMON that knows electric\n"
	.string "moves should hold it.\p"
	.string "My sis MONICA said it powers up\n"
	.string "electric moves!$"

Route37_Text_Sunny_Sunday:
	.string "SUNNY: My sisters and brothers are\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA and SANTOS.\p"
	.string "They're all older than me!$"

Route37_Text_Sunny_NotSunday:
	.string "SUNNY: Isn't today Sunday?\n"
	.string "Um… I forgot!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"
