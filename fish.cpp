#include "all.h"

int fish_state;
int fish_MAX = 5;
int i = 0;
int direction = 0;

Sprite* sprfish;

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
	srand((unsigned int)time(NULL));

	switch (fish_state)
	{
	case 0:
		sprfish = sprite_load(L"./Data/Images/fish.png");

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
			if (fish[i].exist)continue;
			fish[i].exist = true;
			direction = rand() % 2;
			if (direction == 0)
			{
				fish[i].direc = 0;
				fish[i].pos.x = rand() % 960 + 480;
				fish[i].pos.y = 0;
			}
			if (direction == 1)
			{
				fish[i].direc = 1;
				fish[i].pos.x = 0;
				fish[i].pos.y = rand() % 360 + 180;
			}
			
		}
		
		for (int i = 0; i < fish_MAX; i++)
		{
			if (fish[i].direc == 0)
			{
				fish[i].pos.y += 1;
			}
			if (fish[i].direc == 1)
			{
				fish[i].pos.x += 1;
			}
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
		if (fish[i].direc == 0)
		{
			sprite_render(sprfish, fish[i].pos.x, fish[i].pos.y, 1, 1, 0, 0, 128, 128, 64, 64, ToRadian(180));
		}
		if (fish[i].direc == 1)
		{
			sprite_render(sprfish, fish[i].pos.x, fish[i].pos.y, 1, 1, 0, 0, 128, 128, 64, 64, ToRadian(90));
		}
	}

}