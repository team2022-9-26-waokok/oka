#include "all.h"
#include <math.h>

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


	switch (fish_state)
	{
	case 0:
		sprfish = sprite_load(L"./Data/Images/fish.png");

		++fish_state;
		/*falltheough*/

	case 1:

		fish_MAX = 5;
		
		for (int i = 0; i < 50; i++)
		{
			fish[i] = {};
			fish[i].act = 0;
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
		if (fish[i].exist == false)
		{
			// = rand() % 2;
			fish[i] = {};
			fish[i].timer = 0;
			fish[i].pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
			fish[i].scale = { 1.0f,1.0f };
			fish[i].texPos = { 0,0 };
			fish[i].texSize = { 128, 128 };
			fish[i].pivot = { 16,16 };
			fish[i].angle = ToRadian(0);
			fish[i].color = { 1.0f,1.0f,1.0f,1.0f };

			fish[i].level = 1;
			fish[i].basicSpeed = 0;
			fish[i].radius = 20;

			fish[i].basicSpeed = 20;
		}

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
			fish[i].color = {0.9f,1.0f,1.4f,1.0f};
			fish[i].pivot = {64,64};

			fish[i].rea = rand() % 100;
			if (fish[i].rea <= 14)
			{
				fish[i].rea = 1;

			}
			else
			{
				fish[i].rea = 0;
			}

			if (fish[i].rea == 1)
			{
				fish[i].color.x = 2.0f;
				fish[i].color.y = 2.0f;
				fish[i].color.z = 1.0f;
			}

			animeInit(&fish[i], 0, 0);
			



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
				switch (fish[i].act)
				{
				case 0:


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
					else if (fish[i].timer % (30 + i * 3) == 0)
					{
						fish[i].act_type = rand() % 3;
					}


					if (player_act != FISHING || hitCheckCircle({ fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (120 * fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (120 * fish[i].size.x) }, 80, { player.pos.x + player.scroll.x, player.pos.y + player.scroll.y }, 3) == false)
					{
						switch (fish[i].act_type)
						{
						case A_type::STRAIGHT:

							fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
							fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
							fish[i].act_num = 0;
							fish[i].texPos.x = fish[i].texSize.x * 0;

							break;
						case A_type::LEFT:

							fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
							fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
							fish[i].angle -= ToRadian(0.5);
							fish[i].act_num = 2;
							fish[i].texPos.x = fish[i].texSize.x * 2;
							break;
						case A_type::RIGHT:
							fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
							fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
							fish[i].angle += ToRadian(0.5);
							fish[i].act_num = 4;

							fish[i].texPos.x = fish[i].texSize.x * 4;
							break;
						}
					}
					camera_scroll(&fish[i]);
					fish[i].timer++;


				




					//ここから範囲外から出るかどうかとか～動きをもっと良くする用-------------------------------------------

					if ((fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * 200 >= 1288 || fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * 200 <= -8 ||
						fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * 200 <= -8 || fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * 200 >= 728) && fish[i].Out_of_range == 0)
					{
						//fish[i].color.x = 3.0f;
						//fish[i].color.y = 2.0f;
						//fish[i].color.z = 2.0f;
						fish[i].Out_of_range = 1;
						//fish_MAX += 1;
					}
					else
					{
						//fish[i].color.x = 1.0f;
						//fish[i].color.y = 1.0f;
						//fish[i].color.z = 1.0f;

					}


					if (fish[i].Out_of_range == 1)
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

					if (fish[i].Out_of_range == 2 && hitCheckCircle({ fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (120 * fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (120 * fish[i].size.x) }, 80, { player.pos.x + player.scroll.x, player.pos.y + player.scroll.y }, 3) == false)
					{
						fish[i].Out_of_range_count += 2;
						fish[i].angle += ToRadian(2);
						if (fish[i].Out_of_range_count >= 85)
						{
							fish[i].Out_of_range = 0;
						}

					}



				if (player_act == FISHING)
				{
					if (hitCheckCircle({ fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (120 * fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (120 * fish[i].size.x) },100, { player.pos.x + player.scroll.x, player.pos.y + player.scroll.y }, 3))
					{
		
					fish[i].memoy.x = (player.pos.x) - (fish[i].pos.x);

					fish[i].memoy.y = (player.pos.y) - (fish[i].pos.y);


				
						fish[i].angle = atan2(fish[i].memoy.x * -1, fish[i].memoy.y) + ToRadian(180);
						fish[i].pos.y -= cosf(fish[i].angle) * fish[i].FSpeed;
						fish[i].pos.x += sinf(fish[i].angle) * fish[i].FSpeed;
						if (hitCheckCircle({ fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (60 * fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (60 * fish[i].size.x)},
							10 * fish[i].size.x, { player.pos.x + player.scroll.x, player.pos.y + player.scroll.y }, 3))
						{
							player_act = FISHING_BTTLE_TRANS;
							fish[i].act = 1;
							game_timer = 0;

						}
					}

					
				}

			
					break;
				case 1:
					camera_scroll(&fish[i]);
					fish[i].timer++;

					fish[i].battle_hani = fish[i].size.x* fish[i].size.x;
					player.battle_hani = fish[i].battle_hani;
				

					player.battle_pos_x = rand() % (250 - (int)(80 - 20 * player.battle_hani));
					
					fish[i].act = 2;
					break;
				case 2:
					if (player_act == FISHUP)
					{
						if (TRG(0) & PAD_TRG1)
						{
							fish[i].exist = false;
							fish[i].act = 0;
						}
					}
					camera_scroll(&fish[i]);
					fish[i].timer++;
					
					break;
				}



				if (fish[i].pos.x + fish[i].scroll.x >= 1360 || fish[i].pos.x + fish[i].scroll.x <= -40 ||
					fish[i].pos.y + fish[i].scroll.y <= -40 || fish[i].pos.y + fish[i].scroll.y >= 780)
				{
					fish[i].exist = false;
				}
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
				fish[i].size.x, fish[i].size.y, fish[i].texPos.x, fish[i].texPos.y, fish[i].texSize.x, fish[i].texSize.y, fish[i].pivot.x, fish[i].pivot.y, fish[i].angle, fish[i].color.x, fish[i].color.y, fish[i].color.z, fish[i].color.w);
			//GameLib::primitive::rect(fish[i].pos.x + fish[i].scroll.x - sinf(fish[i].angle+ToRadian(45)) *200, fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle - ToRadian(45)) * 200, 10, 10,fish[i].angle);
			//primitive::circle(fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (120*fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (120 * fish[i].size.x), 80, 1, 1, ToRadian(0), 1, 0, 0);
			//primitive::circle(fish[i].pos.x + fish[i].scroll.x + sinf(fish[i].angle) * (60*fish[i].size.x), fish[i].pos.y + fish[i].scroll.y - cosf(fish[i].angle) * (60 * fish[i].size.x), 10* fish[i].size.x, 1, 1, ToRadian(0), 1, 1, 1);
		}
	}
}

