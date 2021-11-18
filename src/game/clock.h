#ifndef T1M_GAME_CLOCK_H
#define T1M_GAME_CLOCK_H

#include <stdbool.h>
#include <stdint.h>

bool Clock_Init();
int32_t Clock_GetMS();
int32_t Clock_Sync();
int32_t Clock_SyncTicks(int32_t target);

#endif