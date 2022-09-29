#include "all.h"

int fish_state;
int fish_MAX = 5;
int i = 0;

OBJ2D fish[50];



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
		for (int i = 0; i < 50; i++)
		{
			fish[i] = {};
			fish[i].timer = 0;
			fish[i].pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
			fish[i].scale = { 1.0f,1.0f };
			fish[i].texPos = { 0,0 };
			fish[i].texSize = { 32,64 };
			fish[i].pivot = { 16,16 };
			fish[i].angle = ToRadian(0);
			fish[i].color = { 0.2f,0.4f,1.0f,1.0f };

			fish[i].level = 1;
			fish[i].basicSpeed = 0;
			fish[i].radius = 20;

			fish[i].basicSpeed = 20;
		}

		++fish_state;
		/*fallthrough*/

	case 2:
		// = rand() % 2;
		
		camera_scroll(&fish[i]);

		for (int i = 0; i < fish_MAX; i++)
		{
			fish[i].exist = true;
			fish[i].pos.x = 100, fish[i].pos.y = 100;
		}

		break;
	}


}

void fish_render()
{
	//GameLib::primitive::rect(
	//	fish[i].pos.x + fish[i].scroll.x, fish[i].pos.y + fish[i].scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
	//	fish[i].texSize.x, fish[i].texSize.y,
	//	fish[i].pivot.x, fish[i].pivot.y,
	//	fish[i].angle,
	//	fish[i].color.x, fish[i].color.y, fish[i].color.z, fish[i].color.w
	//);
	for (int i = 0; i < fish_MAX; i++)
	{
		sprite_render()
	}

}