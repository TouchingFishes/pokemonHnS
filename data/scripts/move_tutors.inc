SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
	removemoney 2500, 0
	goto MoveTutor_EventScript_SwaggerTaught
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	removemoney 2500, 0
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
	removemoney 3500, 0
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

SaffronCity_PokemonCenter_EventScript_TriAttackTutor::
	lock
	faceplayer
	msgbox MoveTutor_TriAttackTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_TriAttackDeclined
	msgbox MoveTutor_Text_TriAttackWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_TRI_ATTACK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_TriAttackDeclined
	removemoney 3333, 0
	goto MoveTutor_EventScript_TriAttackTaught
	end

MoveTutor_EventScript_TriAttackDeclined::
	msgbox MoveTutor_TriAttackDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_TriAttackTaught::
	msgbox MoveTutor_Text_TriAttackTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
	removemoney 2500, 0
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_AcrobaticsTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_AcrobaticsTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_AcrobaticsDeclined
	msgbox MoveTutor_Text_AcrobaticsWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ACROBATICS
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_AcrobaticsDeclined
	removemoney 5000, 0
	goto MoveTutor_EventScript_AcrobaticsTaught
	end

MoveTutor_EventScript_AcrobaticsDeclined::
	msgbox MoveTutor_Text_AcrobaticsDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AcrobaticsTaught::
	msgbox MoveTutor_Text_AcrobaticsTaught, MSGBOX_DEFAULT
	release
	end

Gate_Route40_TrainerHill_Courtyard_EventScript_SubstituteTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
	removemoney 12500, 0
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

KameHouse_EventScript_FocusPunchTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FocusPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FocusPunchDeclined
	msgbox MoveTutor_Text_FocusPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FOCUS_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FocusPunchDeclined
	removemoney 5000, 0
	goto MoveTutor_EventScript_FocusPunchTaught
	end

MoveTutor_EventScript_FocusPunchDeclined::
	msgbox MoveTutor_Text_FocusPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FocusPunchTaught::
	msgbox MoveTutor_Text_FocusPunchTaught, MSGBOX_DEFAULT
	release
	end

ViridianCity_Mart_City_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
	removemoney 15000, 0
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
	removemoney 15000, 0
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

EventScript_SoftboiledTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_SoftboiledTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SoftboiledDeclined
	msgbox MoveTutor_Text_SoftboiledWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SOFT_BOILED
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_SoftboiledDeclined
	removemoney 1000, 0
	goto EventScript_SoftboiledTaught
	end

EventScript_SoftboiledDeclined::
	msgbox MoveTutor_Text_SoftboiledDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_SoftboiledTaught::
	msgbox MoveTutor_Text_SoftboiledTaught, MSGBOX_DEFAULT
	release
	end

EventScript_HeatWaveTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_HeatWaveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_HeatWaveDeclined
	msgbox MoveTutor_Text_HeatWaveWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_HEAT_WAVE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_HeatWaveDeclined
	removemoney 10000, 0
	goto EventScript_HeatWaveTaught
	end

EventScript_HeatWaveDeclined::
	msgbox MoveTutor_Text_HeatWaveDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_HeatWaveTaught::
	msgbox MoveTutor_Text_HeatWaveTaught, MSGBOX_DEFAULT
	release
	end

EventScript_ThunderWaveTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_ThunderWaveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ThunderWaveDeclined
	msgbox MoveTutor_Text_ThunderWaveWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_THUNDER_WAVE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_ThunderWaveDeclined
	removemoney 7500, 0
	goto EventScript_ThunderWaveTaught
	end

EventScript_ThunderWaveDeclined::
	msgbox MoveTutor_Text_ThunderWaveDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_ThunderWaveTaught::
	msgbox MoveTutor_Text_ThunderWaveTaught, MSGBOX_DEFAULT
	release
	end

EventScript_MetalClawTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetalClawTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MetalClawDeclined
	msgbox MoveTutor_Text_MetalClawWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METAL_CLAW
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_MetalClawDeclined
	removemoney 2500, 0
	goto EventScript_MetalClawTaught
	end

EventScript_MetalClawDeclined::
	msgbox MoveTutor_Text_MetalClawDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_MetalClawTaught::
	msgbox MoveTutor_Text_MetalClawTaught, MSGBOX_DEFAULT
	release
	end

EventScript_FissureTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FissureTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_FissureDeclined
	msgbox MoveTutor_Text_FissureWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FISSURE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_FissureDeclined
	removemoney 25000, 0
	goto EventScript_FissureTaught
	end

EventScript_FissureDeclined::
	msgbox MoveTutor_Text_FissureDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_FissureTaught::
	msgbox MoveTutor_Text_FissureTaught, MSGBOX_DEFAULT
	release
	end

Route4_EventScript_MegaPunchTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaPunchDeclined
	msgbox MoveTutor_Text_MegaPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaPunchDeclined
	removemoney 5000, 0
	goto MoveTutor_EventScript_MegaPunchTaught
	end

MoveTutor_EventScript_MegaPunchDeclined::
	msgbox MoveTutor_Text_MegaPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MegaPunchTaught::
	msgbox MoveTutor_Text_MegaPunchTaught, MSGBOX_DEFAULT
	release
	end

Route4_EventScript_MegaKickTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaKickTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaKickDeclined
	msgbox MoveTutor_Text_MegaKickWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_KICK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaKickDeclined
	removemoney 5000, 0
	goto MoveTutor_EventScript_MegaKickTaught
	end

MoveTutor_EventScript_MegaKickDeclined::
	msgbox MoveTutor_Text_MegaKickDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MegaKickTaught::
	msgbox MoveTutor_Text_MegaKickTaught, MSGBOX_DEFAULT
	release
	end

RockTunnel_EventScript_RockSlideTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_RockSlideTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RockSlideDeclined
	msgbox MoveTutor_Text_RockSlideWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROCK_SLIDE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, EventScript_RockSlideDeclined
	removemoney 7500, 0
	goto EventScript_RockSlideTaught
	end

EventScript_RockSlideDeclined::
	msgbox MoveTutor_Text_RockSlideDeclined, MSGBOX_DEFAULT
	release
	end

EventScript_RockSlideTaught::
	msgbox MoveTutor_Text_RockSlideTaught, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_IcyWindTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_IcyWindTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_IcyWindDeclined
	msgbox MoveTutor_Text_IcyWindWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ICY_WIND
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_IcyWindDeclined
	removemoney 5000, 0
	goto MoveTutor_EventScript_IcyWindTaught
	end

MoveTutor_EventScript_IcyWindDeclined::
	msgbox MoveTutor_Text_IcyWindDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_IcyWindTaught::
	msgbox MoveTutor_Text_IcyWindTaught, MSGBOX_DEFAULT
	release
	end

CeruleanCape_EventScript_FocusBlastTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_FocusBlastTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FocusBlastDeclined
	msgbox MoveTutor_Text_FocusBlastWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FOCUS_BLAST
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FocusBlastDeclined
	removemoney 20000, 0
	goto MoveTutor_EventScript_FocusBlastTaught
	end

MoveTutor_EventScript_FocusBlastDeclined::
	msgbox MoveTutor_Text_FocusBlastDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FocusBlastTaught::
	msgbox MoveTutor_Text_FocusBlastTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnceFinite::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnceFinite, MSGBOX_YESNO
	return
