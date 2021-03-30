#ifndef T1M_GAME_AI_CROCODILE_H
#define T1M_GAME_AI_CROCODILE_H

#include "global/types.h"

#include <stdint.h>

#define CROCODILE_BITE_DAMAGE 100
#define CROCODILE_BITE_RANGE SQUARE(435) // = 189225
#define CROCODILE_DIE_ANIM 11
#define CROCODILE_FASTTURN_ANGLE 0x4000
#define CROCODILE_FASTTURN_RANGE SQUARE(WALL_L * 3) // = 9437184
#define CROCODILE_FASTTURN_TURN (6 * PHD_DEGREE) // = 1092
#define CROCODILE_TOUCH 0x3FC
#define CROCODILE_TURN (3 * PHD_DEGREE) // = 546
#define CROCODILE_HITPOINTS 20
#define CROCODILE_RADIUS (WALL_L / 3) // = 341
#define CROCODILE_SMARTNESS 0x2000

typedef enum {
    CROCODILE_EMPTY = 0,
    CROCODILE_STOP = 1,
    CROCODILE_RUN = 2,
    CROCODILE_WALK = 3,
    CROCODILE_FASTTURN = 4,
    CROCODILE_ATTACK1 = 5,
    CROCODILE_ATTACK2 = 6,
    CROCODILE_DEATH = 7,
} CROCODILE_ANIM;

extern BITE_INFO CrocodileBite;

void SetupCrocodile(OBJECT_INFO *obj);
void CrocControl(int16_t item_num);

#endif