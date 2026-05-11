#include "isk_20.h"
#include "sprite/player.h"

namespace isk_20 {

EntryList Entrances = { GEN_ENTRY_LIST };

EvtScript EVS_ExitWalk_isk_19_1 = EVT_EXIT_WALK(40, isk_16_ENTRY_0, "isk_19", isk_19_ENTRY_1);

EvtScript EVS_BindExitTriggers = {
    BindTrigger(Ref(EVS_ExitWalk_isk_19_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript EVS_EnterMap = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Exec(EVS_GauntletIdle)
            Exec(EVS_OpenLeftGate)
    EndSwitch
    Return
    End
};

EvtScript EVS_GauntletIdle = {
    Loop(0)
        // End controller after gauntlet finishes
        IfEq(MF_GauntletDefeated, true)
            DebugPrint("Gauntlet defeated")
            BreakLoop
        EndIf
        // Initial gauntlet start
        IfEq(MF_StartedGauntlet, false)
            DebugPrint("Gauntlet started")
            Set(MF_GauntletDefeated, false)
            Set(MF_StartNextGauntletRound, false)
            Set(MF_StartedGauntlet, true)
            ExecWait(EVS_StartGauntlet)
        Else
            // Continue next round
            IfEq(MF_StartNextGauntletRound, true)
                IfEq(MF_GauntletDefeated, false)
                    Set(MF_StartNextGauntletRound, false)
                    Exec(EVS_StartGauntlet)
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript EVS_Main = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_16)
    EVT_SETUP_CAMERA_NO_LEAD(0, 0, 0)
    ExecWait(EVS_SetupFlames)
    Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
    Set(MF_StartedGauntlet, true)
    Exec(EVS_EnterMap)
    Return
    End
};

} // namespace isk_20

MapSettings isk_20_settings = {
    .main = &isk_20::EVS_Main,
    .entryList = &isk_20::Entrances,
    .entryCount = ENTRY_COUNT(isk_20::Entrances),
    .tattle = { MSG_MapTattle_isk_16 },
};
