#include "all.h"

int player_state;

OBJ2D player;



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

		++player_state;
		/*fallthrough*/

	case 2:


		camera_scroll(&player);
		break;
	}


}

void player_render()
{
	GameLib::primitive::rect(
		player.pos.x + player.scroll.x, player.pos.y + player.scroll.y,//player.scrollはマウスカーソルによって移動した座標を表す
		player.texSize.x, player.texSize.y,
		player.pivot.x, player.pivot.y,
		player.angle,
		player.color.x, player.color.y, player.color.z, player.color.w
	);


}





