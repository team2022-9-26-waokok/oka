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


	//デバック用
	/*for (int y = 0; y < 14; y++)
	{
		primitive::line(0,y * 64 + map.pos.y + map.scroll.y,
			SCREEN_W,y * 64 + map.pos.y + map.scroll.y, 0, 1, 0, 1, 1);
	}

	for (int x = 0; x < 22; x++)
	{
		primitive::line(x * 64 + map.pos.x + map.scroll.x, 0,
			x * 64 + map.pos.x + map.scroll.x, SCREEN_H, 0, 1, 0, 1, 1);
	}*/
}