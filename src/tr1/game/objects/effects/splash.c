#include "game/objects/effects/splash.h"

#include "game/effects.h"
#include "game/random.h"
#include "game/room.h"
#include "game/sound.h"
#include "global/const.h"
#include "global/vars.h"
#include "math/math.h"

void Splash_Setup(OBJECT *obj)
{
    obj->control = Splash_Control;
}

void Splash_Control(int16_t fx_num)
{
    FX *fx = &g_Effects[fx_num];
    fx->frame_num--;
    if (fx->frame_num <= g_Objects[fx->object_id].nmeshes) {
        Effect_Kill(fx_num);
        return;
    }

    fx->pos.z += (Math_Cos(fx->rot.y) * fx->speed) >> W2V_SHIFT;
    fx->pos.x += (Math_Sin(fx->rot.y) * fx->speed) >> W2V_SHIFT;
}

void Splash_Spawn(ITEM *item)
{
    int16_t wh = Room_GetWaterHeight(
        item->pos.x, item->pos.y, item->pos.z, item->room_num);
    int16_t room_num = item->room_num;
    Room_GetSector(item->pos.x, item->pos.y, item->pos.z, &room_num);

    Sound_Effect(SFX_LARA_SPLASH, &item->pos, SPM_NORMAL);

    for (int i = 0; i < 10; i++) {
        int16_t fx_num = Effect_Create(room_num);
        if (fx_num != NO_ITEM) {
            FX *fx = &g_Effects[fx_num];
            fx->pos.x = item->pos.x;
            fx->pos.y = wh;
            fx->pos.z = item->pos.z;
            fx->rot.y = PHD_180 + 2 * Random_GetDraw();
            fx->object_id = O_SPLASH_1;
            fx->frame_num = 0;
            fx->speed = Random_GetDraw() / 256;
        }
    }
}
