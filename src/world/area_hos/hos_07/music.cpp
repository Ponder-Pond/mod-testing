#include "hos_07.h"

namespace hos_07 {

EvtScript EVS_SetupMusic = {
    Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
    Return
    End
};

} // namespace hos_07
