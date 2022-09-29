#include "all.h"

int fish_state;

OBJ2D fish;



struct fish_DATA
{
	Sprite* spr;
	const wchar_t* filePath;
	VECTOR2 texSize;
	VECTOR2 pivot;

};


void fish_init()
{
	fish_state = 0;
}

void fish_deinit()
{
	for (int i = 0; i < 2; i++)
	{

	}


}

void fish_update()
{
	switch (fish_state)
	{
	case 0:

		++fish_state;
		/*falltheough*/

	case 1:

		fish = {};
		fish.timer = 0;
		fish.pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
		fish.scale = { 1.0f,1.0f };
		fish.texPos = { 0,0 };
		fish.texSize = { 32,64 };
		fish.pivot = { 16,16 };
		fish.angle = ToRadian(0);
		fish.color = { 0.2f,0.4f,1.0f,1.0f };

		fish.level = 1;
		fish.basicSpeed = 0;
		fish.radius = 20;
	
		fish.basicSpeed = 20;

		++fish_state;
		/*fallthrough*/

	case 2:
		// = rand() % 2;

		camera_scroll(&fish);
		break;
	}


}

void fish_render()
{
	GameLib::primitive::rect(
		fish.pos.x + fish.scroll.x, fish.pos.y + fish.scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
		fish.texSize.x, fish.texSize.y,
		fish.pivot.x, fish.pivot.y,
		fish.angle,
		fish.color.x, fish.color.y, fish.color.z, fish.color.w
	);


}