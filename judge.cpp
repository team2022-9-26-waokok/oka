#include "all.h"



bool hitCheckCircle(VECTOR2 pos1, float r1, VECTOR2 pos2, float r2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r = r1 + r2;

    if (dx * dx + dy * dy <= r * r)
    {
        return true;
    }

    return false;
}

//--------------------------------------
//  OBJ2D“¯Žm‚Ì‚ ‚½‚è”»’è
//--------------------------------------
bool hitCheck(OBJ2D* obj1, OBJ2D* obj2)
{
    return hitCheckCircle(
        obj1->pos, obj1->radius,
        obj2->pos, obj2->radius
    );
}