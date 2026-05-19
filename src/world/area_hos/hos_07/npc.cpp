#include "hos_07.h"

namespace hos_07 {

#include "world/common/npc/Lumi.inc.cpp"

NpcData NpcData_Lumi = {
    .id = NPC_Lumi,
    .settings = &NpcSettings_Lumi,
    .pos = { GEN_LUMI_VEC },
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .yaw = GEN_LUMI_DIR,
    .drops = NO_DROPS,
    .animations = LUMI_ANIMS,
};

NpcGroupList DefaultNPCs = {
    NPC_GROUP(NpcData_Lumi),
    {}
};

} // namespace hos_07
