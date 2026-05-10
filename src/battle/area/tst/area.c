#include "area.h"

#include "battle/common/newstage/isk_bt01.inc.c"

// // using namespace battle::actor;
// extern "C" {

// namespace battle::area::tst {

extern ActorBlueprint A(goomba);
extern ActorBlueprint A(spiked_goomba);
extern ActorBlueprint A(koopa_troopa);
extern ActorBlueprint A(bob_omb);
extern ActorBlueprint A(cleft);
extern ActorBlueprint A(bandit);
extern ActorBlueprint A(pokey);
extern ActorBlueprint A(buzzy_beetle);
extern ActorBlueprint A(piranha_plant);
extern ActorBlueprint A(clubba);
extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(spear_guy);
extern ActorBlueprint A(spike_top);
extern ActorBlueprint A(bony_beetle);
extern ActorBlueprint A(hammer_bro);

Formation A(Formation_Goomba) = { // Formation 0
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_SpikedGoomba) = { // Formation 1
    ACTOR_BY_IDX(A(spiked_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_KoopaTroopa) = { // Formation 2
    ACTOR_BY_IDX(A(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_Bobomb) = { // Formation 3
    ACTOR_BY_IDX(A(bob_omb), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_Cleft) = { // Formation 4
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_Bandit) = { // Formation 5
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_Pokey) = { // Formation 6
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_BuzzyBeetle) = { // Formation 7
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_PiranhaPlant) = { // Formation 8
    ACTOR_BY_IDX(A(piranha_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_Clubba) = { // Formation 9
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_ShyGuy) = { // Formation 10
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_SpearGuy) = { // Formation 11
    ACTOR_BY_IDX(A(spear_guy), BTL_POS_GROUND_B, 10, .var0 = 1),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_SpikeTop) = { // Formation 12
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_BonyBeetle) = { // Formation 13
    ACTOR_BY_IDX(A(bony_beetle), BTL_POS_GROUND_B, 10, .var0 = 1),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_HammerBros) = { // Formation 14
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_Goomba), A(DryDryRuins), "Goomba"), // Formation 0
    BATTLE(A(Formation_SpikedGoomba), A(DryDryRuins), "Spiked Goomba"), // Formation 1
    BATTLE(A(Formation_KoopaTroopa), A(DryDryRuins), "Koopa Troopa"), // Formation 2
    BATTLE(A(Formation_Bobomb), A(DryDryRuins), "Bob-omb"), // Formation 3
    BATTLE(A(Formation_Cleft), A(DryDryRuins), "Cleft"), // Formation 4
    BATTLE(A(Formation_Bandit), A(DryDryRuins), "Bandit"), // Formation 5
    BATTLE(A(Formation_Pokey), A(DryDryRuins), "Pokey"), // Formation 6
    BATTLE(A(Formation_BuzzyBeetle), A(DryDryRuins), "Buzzy Beetle"), // Formation 7
    BATTLE(A(Formation_PiranhaPlant), A(DryDryRuins), "Piranha Plant"), // Formation 8
    BATTLE(A(Formation_Clubba), A(DryDryRuins), "Clubba"), // Formation 9
    BATTLE(A(Formation_ShyGuy), A(DryDryRuins), "Shy Guy"), // Formation 10
    BATTLE(A(Formation_SpearGuy), A(DryDryRuins), "Spear Guy"), // Formation 11
    BATTLE(A(Formation_SpikeTop), A(DryDryRuins), "Spike Top"), // Formation 12
    BATTLE(A(Formation_BonyBeetle), A(DryDryRuins), "Bony Beetle"), // Formation 13
    BATTLE(A(Formation_HammerBros), A(DryDryRuins), "Hammer Bros"), // Formation 14
    {},
};

StageList A(Stages) = {
    STAGE("Dry Dry Ruins", A(DryDryRuins)), // Stage 0
    {},
};

// } // namespace battle::area::tst

// } // extern "C"
