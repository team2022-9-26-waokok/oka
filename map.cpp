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
		sprMap = sprite_load(L"./Data/Images/map.png");
		
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



	sprite_render(sprMap, map.pos.x + map.scroll.x - 40, map.pos.y + map.scroll.y, 1.3f, 1.3f, 0, 0, 1280, 720,100, 50);

}