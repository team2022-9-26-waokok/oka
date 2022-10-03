#include "all.h"

int fish_state;
int fish_MAX;
int i = 0;
int direction = 0;
int randMemory = 0;
int FRandMemory = 0;

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

		fish_MAX = 5;
		srand(time(0));
		for (int i = 0; i < 50; i++)
		{
			fish[i] = {};
			fish[i].timer = 0;
			fish[i].pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
			fish[i].scale = { 1.0f,1.0f };
			fish[i].texPos = { 0,0 };
			fish[i].texSize = { 128, 128};
			fish[i].pivot = { 16,16 };
			fish[i].angle = ToRadian(0);
			fish[i].color = { 1.0f,1.0f,1.0f,1.0f };

			fish[i].level = 1;
			fish[i].basicSpeed = 0;
			fish[i].radius = 20;

			fish[i].basicSpeed = 20;
		}

		++fish_state;
		/*fallthrough*/

	case 2:
		// = rand() % 2;
		


		for (int i = 0; i < fish_MAX; i++)
		{
			if (fish[i].exist)continue;
			//色んな情報付け

			fish[i].exist = true;

			fish[i].FSpeed = (rand() % 5* 0.1) + (rand() % 5 * 0.1 )+ 0.5f;
			direction = rand() % 3 + rand() % 2;
			FRandMemory = rand() % 95 - 44;
			fish[i].size.x = rand() % 100 * 0.01 + 0.5;
			fish[i].size.y = fish[i].size.x;
			fish[i].timer = 0;
			



			if (direction == F_UP)
			{
				fish[i].direc = 0;
				fish[i].angle = ToRadian(180 + FRandMemory);
				fish[i].pos.x = (rand() % 960/2)+(rand() % 960 / 2) + 480;
				fish[i].pos.y = 0-25;
			}
			if (direction == F_LEFT)
			{
				fish[i].direc = 1;
				fish[i].angle = ToRadian(90 + FRandMemory);
				fish[i].pos.x = 0-25;
				fish[i].pos.y = (rand() % 360 / 2) + (rand() % 360 / 2) + 180;
			}

			if (direction == F_DAWN)
			{
				fish[i].direc = 2;
				fish[i].angle = ToRadian(0 + FRandMemory);
				fish[i].pos.x = (rand() % 960/2)+ (rand() % 960 / 2) + 480;
				fish[i].pos.y = SCREEN_H+25;
			}

			if (direction == F_RIGHT)
			{
				fish[i].direc = 3;
				fish[i].angle = ToRadian(-90 + FRandMemory);
				fish[i].pos.x = SCREEN_W+25;
				fish[i].pos.y = (rand() % 360/2)+ (rand() % 360 / 2) + 180;
			}
			

		}
		

		//基本動作-------------------------------------------------------------------------------------------

		for (int i = 0; i < fish_MAX; i++)
		{
			
			if(fish[i].exist == true);
			{
				anime(&fish[i], 8, 4, 0, true);
				if (i > 10)
				{
					if (i % 10 != 0)
					{
						if (fish[i].timer % (30 + (i % 10) * 3) == 0)
						{
							fish[i].act_type = rand() % 3;
						}
					}

				}
				else if (fish[i].timer % (30 + i*3) == 0)
				{
					fish[i].act_type = rand() % 3;
				}
				

				switch (fish[i].act_type)
				{
				case A_type::STRAIGHT:

					fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
					fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
					break;
				case A_type::LEFT:

					fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
					fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
					fish[i].angle -= ToRadian(0.5);
					break;
				case A_type::RIGHT:
					fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
					fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
					fish[i].angle += ToRadian(0.5);
						break;
				}
				
				camera_scroll(&fish[i]);
				fish[i].timer++;
			}






			//ここから範囲外から出るかどうかとか～動きをもっと良くする用-------------------------------------------

			if ((fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * 200 >= 1288 || fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * 200 <= -8 ||
				fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * 200 <= -8 || fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * 200 >= 728)&& fish[i].Out_of_range == 0)
			{
				//fish[i].color.x = 3.0f;
				//fish[i].color.y = 2.0f;
				//fish[i].color.z = 2.0f;
				fish[i].Out_of_range = 1;
				//fish_MAX += 1;
			}
			else
			{
				fish[i].color.x =1.0f;
				fish[i].color.y =1.0f;
				fish[i].color.z =1.0f;

			}


			if (fish[i].Out_of_range == 1 )
			{
				fish[i].Out_of_judge = rand() % 100;
				if (fish[i].Out_of_judge >= 60)
				{
					fish[i].Out_of_range = 2;
				}
				if (fish[i].Out_of_judge <= 30)
				{
					fish[i].Out_of_range = 4;
				}
				else
				{
					fish[i].Out_of_range = 2;
				}
			}

			if (fish[i].Out_of_range == 2)
			{
				fish[i].Out_of_range_count += 2;
				fish[i].angle += ToRadian(2);
				if (fish[i].Out_of_range_count >= 85)
				{
					fish[i].Out_of_range = 0;
				}

			}




			if (fish[i].pos.x + fish[i].scroll.x >= 1360 || fish[i].pos.x + fish[i].scroll.x <= -40 ||
				fish[i].pos.y + fish[i].scroll.y <= -40|| fish[i].pos.y + fish[i].scroll.y >= 780)
			{
				fish[i].exist = false;
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
//	FdrawImgui();
	for (int i = 0; i < fish_MAX; i++)
	{

		if (fish[i].exist == true)
		{
			sprite_render(sprfish, fish[i].pos.x + fish[i].scroll.x, fish[i].pos.y + fish[i].scroll.y,
				fish[i].size.x, fish[i].size.y, 0, 0, 128, 128, 64, 64, fish[i].angle, fish[i].color.x, fish[i].color.y, fish[i].color.z, fish[i].color.w);
			//GameLib::primitive::rect(fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) *200, fish[i].pos.y + fish[i].scroll.y- cosf(fish[i].angle)*200, 10, 10,fish[i].angle);
		}


	}

}


void FdrawImgui()
{
#ifdef USE_IMGUI

	ImGui::SliderFloat("x", &fish[1].pos.x, 0, 1280);
	
	ImGui::End();
#endif	
}