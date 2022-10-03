#include"all.h"


int gatya_state;
int gatya_timer;

float text = 1.5f;

int a;







void gatya_init()
{
    gatya_state = 0;
	gatya_timer = 0;
	srand((unsigned int)time(NULL));
}

void gatya_deinit()
{

}

void gatya_update()
{
	switch (gatya_state)
	{
	case 0:

		gatya_state++;

	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);
		gatya_state++;

	case 2:
		//タイトルに戻る
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}
		cursor_posX = getCursorPosX();
		cursor_posY = getCursorPosY();

		//ガチャを引く 単発
		if (TRG(0) & PAD_UP) {
			//a = rand % 100;
		}

		//ガチャを引く １１連
		if (TRG(0) & PAD_DOWN) {
			for (int i = 0; i < 12; i++) {
				//a = rand % 100;
			}
		}
		debug::setString("%d",a);
		debug::setString("cursor_posX:%d", cursor_posX);
		debug::setString("cursor_posY:%d", cursor_posY);

		//単発
		
		

		break;
	}
	gatya_timer++;
}

void gatya_render()
{
	GameLib::clear(0.4549f, 0.3569f, 0.1020f);
	primitive::line(150, 500, 550, 500, 1, 1, 1, 0.4f, 50);
	primitive::line(SCREEN_W-550, 500, SCREEN_W-150, 500, 1, 1, 1, 0.4f, 50);

	font::textOut(4, "tanpatu A", 230, 485, text, text, 1, 1, 1);
	font::textOut(4, "11 ren! S", 830, 485, text, text, 1, 1, 1);
}