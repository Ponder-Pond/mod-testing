#include "hos_07.h"

namespace hos_07 {

#include "../common/FallingStars.inc.c"

#include "world/common/todo/GetFloorCollider.inc.c"

EntryList Entrances = { GEN_ENTRY_LIST };

EvtScript EVS_Main = {
    Set(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    Call(SetSpriteShading, SHADING_HOS_01)
    EVT_SETUP_CAMERA_NO_LEAD(0, 0, 0)
    Call(MakeNpcs, false, Ref(DefaultNPCs))
    Exec(EVS_SetupModelFX)
    Exec(N(EVS_Starfall_Random))
    Exec(EVS_SetupMusic)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_01_ENTRY_0)
            Exec(EVS_LumiViolin_Scene)
            Wait(1)
    EndSwitch
    Return
    End
};

} // namespace hos_07

MapSettings hos_07_settings = {
    .main = &hos_07::EVS_Main,
    .entryList = &hos_07::Entrances,
    .entryCount = ENTRY_COUNT(hos_07::Entrances),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_hos_01 },
};
