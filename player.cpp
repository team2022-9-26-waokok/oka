#include "all.h"

int player_state;

OBJ2D player;
int player_act;
float memory;
bool nomal_trans_easing;

struct PLAYER_DATA
{
	Sprite* spr;
	const wchar_t* filePath;
	VECTOR2 texSize;
	VECTOR2 pivot;

};

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

		++player_state;
		/*falltheough*/

	case 1:

		player = {};
		player.timer = 0;
		player.pos = { (float)SCREEN_W / 2,(float)SCREEN_H / 2 };
		player.scale = { 1.0f,1.0f };
		player.texPos = { 0,0 };
		player.texSize = {32,32};
		player.pivot = {16,16};
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

			if (TRG(0) & PAD_TRG1)//バックスペースでタイトルへ戻る
			{
				player_act = NORMAL_TRANS;
				game_timer = 0;
				memory = player.pos.y;
			}
			break;
		case NORMAL_TRANS:
			if ((float)game_timer * 0.1f == 1.5 && nomal_trans_easing == true)
			{
				player_act = FISHING;
				nomal_trans_easing = false;
			}
			else if ((float)game_timer * 0.1f == 2)
			{
				nomal_trans_easing = true;
				game_timer = 0;
			}

				if (nomal_trans_easing)//落下
				{
					player.pos.y += Easing::OutBack((float)game_timer * 0.1f, 4.0f,1.0f, 3.0f, 1.0f);
					player.scale += {0.1f, 0.1f};
				}
				else
				{
					player.pos.y -= Easing::InBack((float)game_timer * 0.1f, 4.0f,1.0f, 3.0f, 1.0f);
					player.scale -= {0.1f, 0.1f};
				}
			break;
		case FISHING:
			if (TRG(0) & PAD_TRG1)//バックスペースでタイトルへ戻る
			{
				player_act = NORMAL;
			}

			break;
		}

		break;
	}


}

void player_render()
{


		switch (player_act)
		{
		case NORMAL:
			GameLib::primitive::rect(
				player.pos.x, player.pos.y,//player.scrollはマウスカーソルによって移動した座標を表す
				player.texSize.x, player.texSize.y,
				player.pivot.x, player.pivot.y,
				player.angle,
				player.color.x, player.color.y, player.color.z, player.color.w
			);
			break;		

		case NORMAL_TRANS:
			GameLib::primitive::rect(
				player.pos.x + player.scroll.x , player.pos.y + player.scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
				player.texSize.x, player.texSize.y,
				player.pivot.x, player.pivot.y,
				player.angle,
				player.color.x, player.color.y, player.color.z, player.color.w
			);
		case FISHING:
			GameLib::primitive::rect(
				player.pos.x + player.scroll.x , player.pos.y + player.scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
				player.texSize.x, player.texSize.y,
				player.pivot.x, player.pivot.y,
				player.angle,
				player.color.x, player.color.y, player.color.z, player.color.w
			);
		}

}





