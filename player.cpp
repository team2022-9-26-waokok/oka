#include "all.h"
#include<math.h>

int player_state;
float blackcolor;
OBJ2D player;
int player_act;
float player_time;
float player_ber;
float battle_ber;
float memory;
bool nomal_trans_easing;

int player_updown;
int player_up_down;

float distance_x;
float distance_y;
float start_x;
float start_y;
float end_x;
float end_y;

int fever_timer; ///FEVERの継続時間(例：fever_timerが10以下ならFEVER状態)
int fever_count; /// FEVERに入るカウント(特定の数でNOMALからFEVERに変更)

int TimeLimit;

int keep_pos_x;
int keep_pos_y;

int score;
int fevercount;
int fevertimer;

struct PLAYER_DATA
{
	Sprite* spr;
	const wchar_t* filePath;
	VECTOR2 texSize;
	VECTOR2 pivot;

}player_data;

struct PLAYER_BAR {
	float	width;
	float	height;
	VECTOR4 color;
}playerBar = {
	40,4,{1,0,0,1}
};

void player_init()
{
	nomal_trans_easing = 0;
	player_state = 0;
}

void player_deinit()
{
	for (int i = 0; i < 2; i++)
	{
		
	}


}

void player_update()
{
	switch (player_state)
	{
	case 0:
		player_data.spr = sprite_load(L"./Data/Images/poi.png");
		++player_state;
		/*falltheough*/

	case 1:

		player = {};
		player.timer = 0;
		player.pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
		player.scale = { 1.5f,1.5f };
		player.texPos = { 0,0 };
		player.texSize = {64,64};
		player.pivot = {32,32};
		player.angle = ToRadian(0);
		player.color = { 1.0f,1.0f,1.0f,1.0f };

		player.level = 1;
		player.basicSpeed = 0;
		player.radius = 20;

		player.basicSpeed = 20;
<<<<<<< HEAD
		player_act = 0;
		blackcolor = 0;
=======
		player_act = NORMAL;

		player_updown = 2;
		player_up_down = 0;

		fever_timer = 0;
		fever_count = 0;

		TimeLimit = 3600;

		keep_pos_x = 0;
		keep_pos_y = 0;

		score = 0;
		fevercount = 1;
		fevertimer = 0;
		
>>>>>>> origin/washida
		++player_state;
		/*fallthrough*/

	case 2:
		
		camera_scroll(&player);
		TimeLimit--;
		fevertimer--;
		if (fevercount % 10 == 0)
		{
			fevertimer = 600;
		}
		if (fevertimer > 0)
		{
			text_out(1, "FEVERTIME", SCREEN_W / 2, SCREEN_H / 2, 5, 5, 0.0f, 0.0f, 0.0f);
		}
		
		switch (player_act)
		{
		case NORMAL:
			player.pos.x = cursor_posX;
			player.pos.y = cursor_posY;
			//camera_scroll(&player);

			if (TRG(0) & PAD_TRG3 && fish_MAX <= 55)
			{
<<<<<<< HEAD
				fish_MAX += 1;

=======
				fish_MAX += 2;
>>>>>>> origin/washida
			}
			if (TRG(0) & PAD_TRG1)
			{
				player_act = NORMAL_TRANS;
				game_timer = 0;
				memory = player.pos.y;
			
				blackcolor = 0;
				
			}
			break;
		case NORMAL_TRANS:
			if ((float)game_timer * 0.1f == 1 && nomal_trans_easing == true)
			{
				player_act = FISHING;
				nomal_trans_easing = false;
			}
			else if ((float)game_timer * 0.1f == 1.5)
			{
				nomal_trans_easing = true;
				game_timer = 0;
			}

			if (nomal_trans_easing)//落下
			{
				player.pos.y += Easing::OutBack((float)game_timer * 0.1f, 4.0f,1.0f, 3.0f, 1.0f)*4;
				player.scale -= {0.05f, 0.05f};
				//player.color.x -= 0.02f;
				//player.color.y -= 0.02f;
			}
			else
			{
				player.pos.y -= Easing::InBack((float)game_timer * 0.1f, 4.0f,1.0f, 3.0f, 1.0f)*4;
				player.scale += { 0.05f, 0.05f };
			}
			break;
		case FISHING:
			if (TRG(0) & PAD_TRG1)
			{
				player_act = NORMAL;
				player.scale = { 1.5f,1.5f };
				player.color = { 1.0f,1.0f,1.0f,1.0f };
			}
			for (int i = 0; i < fish_MAX; i++)
			{
				if ((fish[i].pos.x - player.pos.x) * (fish[i].pos.x - player.pos.x) +
					(fish[i].pos.y - player.pos.y) * (fish[i].pos.y - player.pos.y) < 75 * 75)
				{
					//fish[i].pos.x = player.pos.x;
					//fish[i].pos.y = player.pos.y;
					keep_pos_x = fish[i].pos.x;
					keep_pos_y = fish[i].pos.y;
					fish[i].hang = true;
					player_act = FISHING_BTTLE_TRANS;
					game_timer = 0;
				}
			}
<<<<<<< HEAD

=======
			if (TRG(0) & PAD_TRG2)
			{
				player_act = FISHING_BTTLE_TRANS;
				game_timer = 0;
			}
>>>>>>> origin/washida
			break;
		case FISHING_BTTLE_TRANS:
			//player.pos.y += 0.1f;
			//player.color.x += 0.02f;
			//player.color.y += 0.02f;
			if ((float)game_timer * 0.1f == 1)
			{
				player_act = FISHING_BTTLE;
				player_time = 0;
			}
			break;
		case FISHING_BTTLE:
			for (int i = 0; i < fish_MAX; i++)
			{
				if (fish[i].hang == true)
				{
					
					if (TRG(0) & PAD_TRG2)
					{
						if (fevertimer > 0)
						{
							if (player_time > 40.0f && player_time < 200.0f)
							{
								score += 250;
								fevercount++;
								fish[i].exist = false;
								fish_MAX++;
							}
							else
							{
								fish[i].hang = false;
							}
						}
						else
						{
							if (player_time > 80.0f && player_time < 160.0f)
							{
								score += 100;
								fevercount++;
								fish[i].exist = false;
								fish_MAX++;
							}
							else
							{
								fish[i].hang = false;
							}
						}
						player_act = NORMAL;
						player.scale = { 1.5f,1.5f };
						fish_MAX = 5;
						game_timer = 0;
					}
					fish[i].pos.x = keep_pos_x;
					fish[i].pos.y = keep_pos_y;
				}
			}
			player_time += 5.0f;
			player_ber = player_time;
			if (player_updown % 30 == 0)
			{
				player_up_down += 10.0f;
			}
			if (player_updown % 30 == 15)
			{
				player_up_down -= 10.0f;
			}
			player_updown++;
			if (player_time >= 240.0f)
			{
				player_time = 0.0f;
<<<<<<< HEAD

			}
			//if (TRG(0) & PAD_TRG2)
			//{
			//	player_act = NORMAL;
			//	player.scale = { 1.5f,1.5f };
			//	fish_MAX = 5;
			//	game_timer = 0;

			//}

			if (TRG(0) & PAD_TRG1)
			{
				if (player_ber >= player.battle_pos_x && player_ber <= player.battle_pos_x + (80 - 20 * player.battle_hani))
				{
					player.winbool = true;
			
					player_act = FISHUP;
					break;
				}
				player_act = FISHUP;
			}

=======
			}
			
>>>>>>> origin/washida
			battle_ber;
			break;
		case  FISHUP:
			

			if (blackcolor <= 0.5f)
			{
				blackcolor += 0.1f;
			}
			if (TRG(0) & PAD_TRG1)
			{
				player.winbool = false;
				player_act = NORMAL;
				player.scale = { 1.5f,1.5f };
				blackcolor = 0;
				game_timer = 0;
			}
			break;
		}

		/// <summary>
		/// FEVER中の処理
		/// </summary>
		//case FEVER:
		//	text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
		//	fever_timer++;
		//	player.pos.x = cursor_posX;
		//	player.pos.y = cursor_posY;
		//	//camera_scroll(&player);
		//	if (TRG(0) & PAD_TRG3 && fish_MAX <= 56)
		//	{
		//		fish_MAX += 2;
		//	}
		//	if (TRG(0) & PAD_TRG1)
		//	{
		//		player_act = FEVER_TRANS;
		//		
		//		game_timer = 0;
		//		memory = player.pos.y;
		//	}
		//	break;
		//case FEVER_TRANS:
		//	text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
		//	fever_timer++;
		//	if ((float)game_timer * 0.1f == 1 && nomal_trans_easing == true)
		//	{
		//		player_act = FEVERFISHING;
		//		
		//		nomal_trans_easing = false;
		//	}
		//	else if ((float)game_timer * 0.1f == 1.5)
		//	{
		//		nomal_trans_easing = true;
		//		game_timer = 0;
		//	}
		//	if (nomal_trans_easing)//落下
		//	{
		//		player.pos.y += Easing::OutBack((float)game_timer * 0.1f, 4.0f, 1.0f, 3.0f, 1.0f) * 4;
		//		player.scale -= {0.05f, 0.05f};
		//		//player.color.x -= 0.02f;
		//		//player.color.y -= 0.02f;
		//	}
		//	else
		//	{
		//		player.pos.y -= Easing::InBack((float)game_timer * 0.1f, 4.0f, 1.0f, 3.0f, 1.0f) * 4;
		//		player.scale += { 0.05f, 0.05f };
		//	}
		//	break;
		//case FEVERFISHING:
		//	text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
		//	fever_timer++;
		//	if (TRG(0) & PAD_TRG1)
		//	{
		//		player_act = FEVER;
		//		
		//		player.scale = { 1.5f,1.5f };
		//		player.color = { 1.0f,1.0f,1.0f,1.0f };
		//	}
		//	if (TRG(0) & PAD_TRG2)
		//	{
		//		player_act = FEVERFISHING_BTTLE_TRANS;
		//		
		//		game_timer = 0;
		//	}
		//	for (int i = 0; i < fish_MAX; i++)
		//	{
		//		if (fish[i].pos.x - player.pos.x <= 75)
		//		{
		//			if (player.pos.x - fish[i].pos.x <= 75)
		//			{
		//				if (player.pos.y <= fish[i].pos.y)
		//				{
		//					if (player.pos.y - fish[i].pos.y >= 150) 
		//					{
		//					}
		//				}
		//			}
		//			player_act = FEVERFISHING_BTTLE_TRANS;
		//			
		//		}
		//	}
		//	break;
		//case FEVERFISHING_BTTLE_TRANS:
		//	text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
		//	//fever_timer++;
		//	//player.pos.y += 0.1f;
		//	//player.color.x += 0.02f;
		//	//player.color.y += 0.02f;

		//	if ((float)game_timer * 0.1f == 1)
		//	{
		//		player_act = FEVERFISHING_BTTLE;
		//		
		//		player_time = 0;
		//	}
		//	break;
		//case FEVERFISHING_BTTLE:
		//	text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
		//	fever_timer++;
		//	player_time += 5.0f;
		//	player_ber = player_time;
		//	if (player_updown % 30 == 0)
		//	{
		//		player_up_down += 10.0f;
		//	}
		//	if (player_updown % 30 == 15)
		//	{
		//		player_up_down -= 10.0f;
		//	}
		//	player_updown++;
		//	if (player_time >= 240.0f)
		//	{
		//		player_time = 0.0f;
		//	}
		//	if (TRG(0) & PAD_TRG2)
		//	{
		//		player_act = FEVER;
		//		
		//		player.scale = { 1.5f,1.5f };
		//		fish_MAX = 5;
		//		game_timer = 0;
		//	}
		//	battle_ber;
		//	break;
	}
}

void player_render()
{
<<<<<<< HEAD

	debug::setString("player_ber:%f", player_ber);
	debug::setString("player_battle:%f", player.battle_pos_x);
	debug::setString("player_battle -hani:%f", ((80 - 20 * player.battle_hani) / 2));
=======
>>>>>>> origin/washida
		switch (player_act)
		{
		case NORMAL:
		
				sprite_render(
				player_data.spr,
				player.pos.x, player.pos.y,//player.scrollはマウスカーソルによって移動した座標を表す
				player.scale.x,player.scale.y,
				player.texPos.x,player.texPos.y,
				player.texSize.x, player.texSize.y,
				player.pivot.x, player.pivot.y,
				player.angle,
				player.color.x, player.color.y, player.color.z, player.color.w
			);
			break;		
		case NORMAL_TRANS:
			plrender();
			break;
		case FISHING:
			plrender();
			break;
		case FISHING_TRANS:
			plrender();
			break;
		case FISHING_BTTLE:
			plrender();
			battle_render();
			break;
		case FISHING_BTTLE_TRANS:
			plrender();
			break;
<<<<<<< HEAD
		case FISHUP:
=======
		case FEVER:
			sprite_render(
				player_data.spr,
				player.pos.x, player.pos.y,//player.scrollはマウスカーソルによって移動した座標を表す
				player.scale.x, player.scale.y,
				player.texPos.x, player.texPos.y,
				player.texSize.x, player.texSize.y,
				player.pivot.x, player.pivot.y,
				player.angle,
				player.color.x, player.color.y, player.color.z, player.color.w
			);
			break;
		case FEVER_TRANS:
			plrender();
			break;
		case FEVERFISHING:
			plrender();
			break;
		case FEVERFISHING_TRANS:
			plrender();
			break;
		case FEVERFISHING_BTTLE:
			plrender();
			battle_render();
			break;
		case FEVERFISHING_BTTLE_TRANS:
>>>>>>> origin/washida
			plrender();
			break;
		}
}


void battle_render()
{
	if (player.pos.y >= 720 / 2)
	{
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2, player.pos.y + player.scroll.y - 60, 250, 20, 0, 0, ToRadian(0), 0.2f, 0.2f, 0.2f, 0.5f);
		primitive::rect(player.pos.x + player.scroll.x + player.battle_pos_x - 250/2, player.pos.y + player.scroll.y - 60, 80-20 * player.battle_hani, 20,0,0, ToRadian(0), 0.7f, 0.7f, 0.4f, 0.4f);
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2 + player_ber, player.pos.y + player.scroll.y - 60, 2, 20, 0, 0, ToRadian(0), 1.0f, 1.0f, 0.2f, 1.0f);

	}
	else
	{
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2, player.pos.y + player.scroll.y + 60, 250, 20, 0, 0, ToRadian(0), 0.2f, 0.2f, 0.2f, 0.5f);
		primitive::rect(player.pos.x + player.scroll.x + player.battle_pos_x - 250/2, player.pos.y + player.scroll.y + 60, 80-20 * player.battle_hani, 20, 0, 0, ToRadian(0), 0.7f, 0.7f, 0.4f, 0.4f);
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2 + player_ber, player.pos.y + player.scroll.y + 60, 2, 20, 0, 0, ToRadian(0), 1.0f, 1.0f, 0.2f, 1.0f);


	}

}

void plrender()
{
	sprite_render(
		player_data.spr,
		player.pos.x + player.scroll.x, player.pos.y + player.scroll.y + player_up_down,//player.scrollはマウスカーソルによって移動した座標を表す
		player.scale.x, player.scale.y,
		player.texPos.x, player.texPos.y,
		player.texSize.x, player.texSize.y,
		player.pivot.x, player.pivot.y,
		player.angle,
		player.color.x, player.color.y, player.color.z, player.color.w);
	if (player.winbool)
	{
		GameLib::primitive::rect(0, 0, 1280, 720, 0, 0, 0, 0.1f, 0.1f, 0.1f, blackcolor);
	}
}


