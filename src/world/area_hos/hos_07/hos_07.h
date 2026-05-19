/// Shooting Star Summit - Shooting Star Summit

#include "common.h"
#include "generated.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_07_shape.h"
#include "mapfs/hos_07_hit.h"

#include "dx/debug_menu.h"

#include "sprite/npc/Lumi.h"

namespace hos_07 {

enum {
    NPC_Lumi,
};

enum {
    MV_AlphaAmt_Eldstar = MapVar(0),
    MV_AlphaAmt_Others  = MapVar(1),
    MV_StarBeamFXPtr    = MapVar(10),
    MV_StarBeamState    = MapVar(11),
};

enum {
    MF_SpiritsGone      = MapFlag(0),
};

#define NAMESPACE hos_01

extern EvtScript EVS_Main;
extern EvtScript EVS_SetupMusic;
extern EvtScript EVS_SetupModelFX;
extern NpcGroupList DefaultNPCs;
extern EvtScript EVS_LumiViolin_Scene;

API_CALLABLE(func_80240AAC_A1132C);
API_CALLABLE(func_80240B10_A11390);
API_CALLABLE(SetStarBeamMasterAlpha);

} // namespace hos_07
