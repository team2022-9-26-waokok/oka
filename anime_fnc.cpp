#include "all.h"


void animeInit(OBJ2D* obj,int animeNo, float anime_start)
{
	obj->anime = obj->animeTimer = 0;
	obj->texPos = { anime_start * obj->texSize.x, animeNo * obj->texSize.y };
}

bool anime(OBJ2D* obj, int total, int frame, float anime_start, bool loop)
{
	obj->anime = obj->animeTimer / frame + anime_start;
	if (loop)
	{
		if (obj->anime >= total)
		{
			obj->anime = anime_start;
			obj->animeTimer = 0;
		}
	}
	else
	{
		if (obj->anime >= total)
		{
			obj->anime = total - 1;
			return true;
		}
	}
	obj->texPos.x = obj->anime * obj->texSize.x;
	++obj->animeTimer;

	return false;

}