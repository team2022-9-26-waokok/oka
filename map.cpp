#include "all.h"

int map_state;

OBJ2D map;


Sprite* sprMap;

void map_init()
{
	map_state = 0;
}

void map_deinit()
{
	safe_delete(sprMap);
}

void map_update()
{
	switch (map_state)
	{
	case 0:
		sprMap = sprite_load(L"./Data/Images/map.PNG");
		
		++map_state;
		/*fallthrogh*/
	case 1:
		map = {};
		map.pos = { 0,0 };
		map.scale = { 1,1 };
		map.texPos = { 0,0 };
		map.texSize = { 64,64 };
		map.pivot = { 0,0 };

		++map_state;
		/*fallthrough*/
	case 2:
		camera_scroll(&map);
		camera_move(&map);

		/*debug::setString("map.pos:%f,%f", map.pos.x, map.pos.y);*/
		break;
	}
}

void map_render()
{


	GameLib::primitive::rect(0, 0, 1280, 720, 0, 0, 0, 0.66f, 0.78f, 0.86f);
}