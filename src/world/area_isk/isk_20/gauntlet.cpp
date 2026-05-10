#include "isk_20.h"

namespace isk_20 {

#define TOTAL_ARENA_NPCS 15
#define MAX_GAUNTLET_BATTLES 5

s32 gGauntletRemaining = 5;
s32 gLastArenaNPC = -1;

API_CALLABLE(ResetArenaGauntlet) {
    gGauntletRemaining = 5;
    gLastArenaNPC = -1;

    return ApiStatus_DONE2;
}

typedef struct {
    s32 npcID;
    b32 used;
} ArenaNPC;

NpcGroupList* gArenaNpcGroups[] = {
    &GoombaNPC,
    &SpikedGoombaNPC,
    &KoopaTroopaNPC,
    &BobombNPC,
    &CleftNPC,
    &BanditNPC,
    &PokeyNPC,
    &BuzzyBeetleNPC,
    &PiranhaPlantNPC,
    &ClubbaNPC,
    &ShyGuyNPC,
    &SpearGuyNPC,
    &SpikeTopNPC,
    &BonyBeetleNPC,
    &HammerBrosNPC,
};

ArenaNPC gArenaNPCs[TOTAL_ARENA_NPCS] = {
    { NPC_Goomba, false },
    { NPC_SpikedGoomba, false },
    { NPC_KoopaTroopa, false },
    { NPC_Bobomb, false },
    { NPC_Cleft, false },
    { NPC_Bandit, false },
    { NPC_Pokey, false },
    { NPC_BuzzyBeetle, false },
    { NPC_PiranhaPlant, false },
    { NPC_Clubba, false },
    { NPC_ShyGuy, false },
    { NPC_SpearGuy, false },
    { NPC_SpikeTop, false },
    { NPC_BonyBeetle, false },
    { NPC_HammerBros, false },
};

API_CALLABLE(GetRandomArenaIndex) {
    s32 index;

    if (gGauntletRemaining <= 0) {
        evt_set_variable(script, LVar0, -1);
        return ApiStatus_DONE2;
    }

    while (true) {
        index = rand_int(14);

        if (index == gLastArenaNPC) {
            continue;
        }

        gLastArenaNPC = index;

        gGauntletRemaining--;

        evt_set_variable(script, LVar0, index);

        break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetRandomArenaNPC) {
    s32 index;

    if (gGauntletRemaining <= 0) {
        evt_set_variable(script, LVar0, -1);
        return ApiStatus_DONE2;
    }

    while (true) {
        index = rand_int(14);

        // prevent immediate repeat only (optional)
        if (gArenaNPCs[index].npcID == gLastArenaNPC) {
            continue;
        }

        gLastArenaNPC = gArenaNPCs[index].npcID;

        gGauntletRemaining--;

        evt_set_variable(script, LVar0,
            gArenaNPCs[index].npcID);

        break;
    }

    return ApiStatus_DONE2;
}

EvtScript EVS_GauntletRandomizer = {

    // Finished all rounds?
    IfEq(MF_GauntletDefeated, true)
        Return
    EndIf

    Call(GetRandomArenaIndex)

    IfEq(LVar0, -1)
        Set(MF_GauntletDefeated, true)
        Return
    EndIf

    Switch(LVar0)
    CaseEq(0)
        Call(MakeNpcs, false, Ref(GoombaNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Goomba, 0, true)
    CaseEq(1)
        Call(MakeNpcs, false, Ref(SpikedGoombaNPC))
        Wait(1)
        Call(SetNpcVar, NPC_SpikedGoomba, 0, true)
    CaseEq(2)
        Call(MakeNpcs, false, Ref(KoopaTroopaNPC))
        Wait(1)
        Call(SetNpcVar, NPC_KoopaTroopa, 0, true)
    CaseEq(3)
        Call(MakeNpcs, false, Ref(BobombNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Bobomb, 0, true)
    CaseEq(4)
        Call(MakeNpcs, false, Ref(CleftNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Cleft, 0, true)
    CaseEq(5)
        Call(MakeNpcs, false, Ref(BanditNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Bandit, 0, true)
    CaseEq(6)
        Call(MakeNpcs, false, Ref(PokeyNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Pokey, 0, true)
    CaseEq(7)
        Call(MakeNpcs, false, Ref(BuzzyBeetleNPC))
        Wait(1)
        Call(SetNpcVar, NPC_BuzzyBeetle, 0, true)
    CaseEq(8)
        Call(MakeNpcs, false, Ref(PiranhaPlantNPC))
        Wait(1)
        Call(SetNpcVar, NPC_PiranhaPlant, 0, true)
    CaseEq(9)
        Call(MakeNpcs, false, Ref(ClubbaNPC))
        Wait(1)
        Call(SetNpcVar, NPC_Clubba, 0, true)
    CaseEq(10)
        Call(MakeNpcs, false, Ref(ShyGuyNPC))
        Wait(1)
        Call(SetNpcVar, NPC_ShyGuy, 0, true)
    CaseEq(11)
        Call(MakeNpcs, false, Ref(SpearGuyNPC))
        Wait(1)
        Call(SetNpcVar, NPC_SpearGuy, 0, true)
    CaseEq(12)
        Call(MakeNpcs, false, Ref(SpikeTopNPC))
        Wait(1)
        Call(SetNpcVar, NPC_SpikeTop, 0, true)
    CaseEq(13)
        Call(MakeNpcs, false, Ref(BonyBeetleNPC))
        Wait(1)
        Call(SetNpcVar, NPC_BonyBeetle, 0, true)
    CaseEq(14)
        Call(MakeNpcs, false, Ref(HammerBrosNPC))
        Wait(1)
        Call(SetNpcVar, NPC_HammerBros, 0, true)
    EndSwitch

    Return
    End
};

} // namespace isk_20
