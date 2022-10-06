#include "collisition detection.h"
#include "obj2d.h"

bool batoljudge(OBJ2D* player, OBJ2D* fish)
{
    if (player->pos.x - fish->pos.x > -75)
    {
        if (player->pos.x - fish->pos.x < 75)
        {
            if (player->pos.y > fish->pos.y)
            {
                if (player->pos.y - fish->pos.y < 150)
                {
                    return true;
                }
            }
        }
    }
    return false;
}