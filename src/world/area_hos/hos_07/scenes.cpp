#include "hos_07.h"

namespace hos_07 {

EvtScript EVS_LumiViolin_Scene = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerPos, 0, -1000, 0)
    Call(SetNpcPos, NPC_Lumi, GEN_LUMI_VEC)
    Call(UseSettingsFrom, CAM_DEFAULT, GEN_LUMI_VEC)
    Call(SetPanTarget, CAM_DEFAULT, GEN_LUMI_VEC)
    Call(SetCamSpeed, CAM_DEFAULT, 90)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_Lumi, ANIM_Lumi_Violin)
    Return
    End
};

} // namespace hos_07
