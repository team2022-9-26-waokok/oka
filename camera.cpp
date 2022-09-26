#include "all.h"

struct CAMERA
{
	VECTOR2 pos;
	VECTOR2 power;
	VECTOR2 speed;
};

CAMERA camera;

void camera_init()
{
	camera = {};
}

void camera_update()
{
	//マウスカーソルによってスクロールする座標を出すために必要
	camera.power = { -1 * (cursor_posX - player.pos.x) / (SCREEN_W / 2),
					-1 * (cursor_posY - player.pos.y) / (SCREEN_H / 2) };

	camera.pos = { camera.power.x * CAMERA_SCROLL_X,camera.power.y * CAMERA_SCROLL_Y };

	if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT))
	{
		camera.speed.x = player.basicSpeed;
	}
	else if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT))
	{
		camera.speed.x = -player.basicSpeed;
	}
	else
	{
		camera.speed.x = 0;
	}

	if (STATE(0) & PAD_DOWN && !(STATE(0) & PAD_UP))
	{
		camera.speed.y = -player.basicSpeed;
	}
	else if (STATE(0) & PAD_UP && !(STATE(0) & PAD_DOWN))
	{
		camera.speed.y = player.basicSpeed;
	}
	else
	{
		camera.speed.y = 0;
	}




#if 1//消すのが辛いのでコメントアウトで残してるだけ

	/*if ( CURSOR_SCROLL_X >= fabsf(player.scroll.x))
	{
		camera_cursor.pos.x -= camera_cursor.power.x * CAMERA_SPEED;
		player.scroll.x += camera_cursor.pos.x;
	}
	else if (CURSOR_SCROLL_X < fabsf(player.scroll.x))
	{
		if (player.scroll.x > 0)
		{
			player.scroll.x = CURSOR_SCROLL_X;
			camera_cursor.pos.x = 0;
		}
		else if (player.scroll.x < 0)
		{
			player.scroll.x = -CURSOR_SCROLL_X;
			camera_cursor.pos.x = 0;
		}
	}

	if (CURSOR_SCROLL_Y >= fabsf(player.scroll.y))
	{
		camera_cursor.pos.y -= camera_cursor.power.y * CAMERA_SPEED;
		player.scroll.y += camera_cursor.pos.y;
	}
	else if (CURSOR_SCROLL_Y < fabsf(player.scroll.y))
	{
		if (player.scroll.y > 0)
		{
			player.scroll.y = CURSOR_SCROLL_Y;
			camera_cursor.pos.y = 0;
		}
		else if (player.scroll.y < 0)
		{
			player.scroll.y = -CURSOR_SCROLL_Y;
			camera_cursor.pos.y = 0;
		}
	}*/

	/*if (player.pos.x < SCREEN_W/2 - CAMERA_SCROLL_X + camera_cursor.pos.x)
	{
		camera.pos.x += fabsf(player.pos.x - (SCREEN_W / 2 - CAMERA_SCROLL_X));
		player.pos.x = SCREEN_W / 2 - CAMERA_SCROLL_X;
	}
	else if (player.pos.x > SCREEN_W / 2 + CAMERA_SCROLL_X + camera_cursor.pos.x)
	{
		camera.pos.x -= fabsf(player.pos.x - (SCREEN_W / 2 + CAMERA_SCROLL_X));
		player.pos.x = SCREEN_W / 2 + CAMERA_SCROLL_X;
	}

	if (player.pos.y < SCREEN_H / 2 - CAMERA_SCROLL_Y + camera_cursor.pos.y)
	{
		camera.pos.y += fabsf(player.pos.y - (SCREEN_H / 2 - CAMERA_SCROLL_Y));
		player.pos.y = SCREEN_H / 2 - CAMERA_SCROLL_Y;
	}
	else if (player.pos.y > SCREEN_H / 2 + CAMERA_SCROLL_Y + camera_cursor.pos.y)
	{
		camera.pos.y -= fabsf(player.pos.y - (SCREEN_H / 2 + CAMERA_SCROLL_Y));
		player.pos.y = SCREEN_H / 2 + CAMERA_SCROLL_Y;
	}*/

#endif // //消すのが辛いのでコメントアウトで残してるだけ

	/*debug::setString("camera.pos:%f %f", camera.pos.x,camera.pos.y);*/
}

void camera_scroll(OBJ2D* obj)//マウスカーソルによる視点移動が反映される
{
	obj->scroll.x = camera.pos.x;
	obj->scroll.y = camera.pos.y;
}

void camera_move(OBJ2D* obj)//マップの移動が反映される（プレイヤーには使わない！）
{
	obj->pos.x += camera.speed.x;
	obj->pos.y += camera.speed.y;
}