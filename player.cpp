#include "all.h"

int player_state;

OBJ2D player;
int player_act;
float player_time;
float player_ber;
float battle_ber;
float memory;
bool nomal_trans_easing;

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

			if (TRG(0) & PAD_TRG3 && fish_MAX <= 55)
			{
				fish_MAX += 1;

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
					player.color.x -= 0.02f;
					player.color.y -= 0.02f;

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

			break;
		case FISHING_BTTLE_TRANS:
			player.pos.y += 0.1f;
			player.color.x += 0.02f;
			player.color.y += 0.02f;

			if ((float)game_timer * 0.1f == 1)
			{
				player_act = FISHING_BTTLE;
				player_time = 0;
			}
			break;
		case FISHING_BTTLE:
			

			player_time += 5.0f;
			player_ber = player_time;
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
		player.pos.x + player.scroll.x, player.pos.y + player.scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
		player.scale.x, player.scale.y,
		player.texPos.x, player.texPos.y,
		player.texSize.x, player.texSize.y,
		player.pivot.x, player.pivot.y,
		player.angle,
		player.color.x, player.color.y, player.color.z, player.color.w);

}


