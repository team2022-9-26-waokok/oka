#include "all.h"
#include<math.h>

int player_state;

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
		player_act = 0;

		player_updown = 2;
		player_up_down = 0;

		fever_timer = 0;
		fever_count = 0;
		
		++player_state;
		/*fallthrough*/

	case 2:
		
		camera_scroll(&player);
		switch (player_act)
		{
		case NORMAL:
			player.pos.x = cursor_posX;
			player.pos.y = cursor_posY;
			//camera_scroll(&player);

			if (TRG(0) & PAD_TRG3 && fish_MAX <= 56)
			{
				fish_MAX += 2;

			}


			if (TRG(0) & PAD_TRG1)
			{
				player_act = NORMAL_TRANS;
				game_timer = 0;
				memory = player.pos.y;
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
			if (TRG(0) & PAD_TRG2)
			{
				player_act = FISHING_BTTLE_TRANS;
				
				game_timer = 0;
			}
			for (int i = 0; i < fish_MAX; i++)
			{
				if (fish[i].pos.x - player.pos.x <= 75)
				{
					if (player.pos.x - fish[i].pos.x <= 75)
					{
						if (player.pos.y <= fish[i].pos.y)
						{
							if (player.pos.y - fish[i].pos.y >= 150) {

							}
						}
					}
					player_act = FISHING_BTTLE_TRANS;
					
				}
					
			}
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

			}
			if (TRG(0) & PAD_TRG2)
			{
				player_act = NORMAL;
				
				player.scale = { 1.5f,1.5f };
				fish_MAX = 5;
				game_timer = 0;

			}
			battle_ber;

			break;
		}

		/// <summary>
		/// FEVER中の処理
		/// </summary>
		case FEVER:
			text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
			fever_timer++;
			player.pos.x = cursor_posX;
			player.pos.y = cursor_posY;
			//camera_scroll(&player);
			if (TRG(0) & PAD_TRG3 && fish_MAX <= 56)
			{
				fish_MAX += 2;
			}
			if (TRG(0) & PAD_TRG1)
			{
				player_act = FEVER_TRANS;
				
				game_timer = 0;
				memory = player.pos.y;
			}
			break;
		case FEVER_TRANS:
			text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
			fever_timer++;
			if ((float)game_timer * 0.1f == 1 && nomal_trans_easing == true)
			{
				player_act = FEVERFISHING;
				
				nomal_trans_easing = false;
			}
			else if ((float)game_timer * 0.1f == 1.5)
			{
				nomal_trans_easing = true;
				game_timer = 0;
			}
			if (nomal_trans_easing)//落下
			{
				player.pos.y += Easing::OutBack((float)game_timer * 0.1f, 4.0f, 1.0f, 3.0f, 1.0f) * 4;
				player.scale -= {0.05f, 0.05f};
				//player.color.x -= 0.02f;
				//player.color.y -= 0.02f;
			}
			else
			{
				player.pos.y -= Easing::InBack((float)game_timer * 0.1f, 4.0f, 1.0f, 3.0f, 1.0f) * 4;
				player.scale += { 0.05f, 0.05f };
			}
			break;
		case FEVERFISHING:
			text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
			fever_timer++;
			if (TRG(0) & PAD_TRG1)
			{
				player_act = FEVER;
				
				player.scale = { 1.5f,1.5f };
				player.color = { 1.0f,1.0f,1.0f,1.0f };
			}
			if (TRG(0) & PAD_TRG2)
			{
				player_act = FEVERFISHING_BTTLE_TRANS;
				
				game_timer = 0;
			}
			for (int i = 0; i < fish_MAX; i++)
			{
				if (fish[i].pos.x - player.pos.x <= 75)
				{
					if (player.pos.x - fish[i].pos.x <= 75)
					{
						if (player.pos.y <= fish[i].pos.y)
						{
							if (player.pos.y - fish[i].pos.y >= 150) 
							{
							}
						}
					}
					player_act = FEVERFISHING_BTTLE_TRANS;
					
				}
			}
			break;
		case FEVERFISHING_BTTLE_TRANS:
			text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
			//fever_timer++;
			//player.pos.y += 0.1f;
			//player.color.x += 0.02f;
			//player.color.y += 0.02f;

			if ((float)game_timer * 0.1f == 1)
			{
				player_act = FEVERFISHING_BTTLE;
				
				player_time = 0;
			}
			break;
		case FEVERFISHING_BTTLE:
			text_out(1, "FEVER TIME", SCREEN_W / 2, SCREEN_H / 2, 10, 10, 1.0f, 1.0f, 1.0f);
			fever_timer++;
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
			}
			if (TRG(0) & PAD_TRG2)
			{
				player_act = FEVER;
				
				player.scale = { 1.5f,1.5f };
				fish_MAX = 5;
				game_timer = 0;
			}
			battle_ber;
			break;
	}
}

void player_render()
{
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
			plrender();
			break;
		}
}


void battle_render()
{
	if (player.pos.y >= 720 / 2)
	{
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2, player.pos.y + player.scroll.y - 60, 250, 20, 0, 0, ToRadian(0), 0.2f, 0.2f, 0.2f, 0.5f);
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2 + player_ber, player.pos.y + player.scroll.y - 60, 2, 20, 0, 0, ToRadian(0), 1.0f, 1.0f, 0.2f, 1.0f);
	}
	else
	{
		primitive::rect(player.pos.x + player.scroll.x - 250 / 2, player.pos.y + player.scroll.y + 60, 250, 20, 0, 0, ToRadian(0), 0.2f, 0.2f, 0.2f, 0.5f);
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

}


