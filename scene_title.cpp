#include "all.h"
//�@
int title_state;
int title_timer;
extern int  curScene;
extern int nextScene;
//�D
Sprite* sprCar2;
void title_init()
{
	//�A
	title_state = 0;
	title_timer = 0;
}
void title_deinit()
{
	//�G

}
void title_update()
{
	//�C
	switch (title_state)
	{
	case 0:
		//////// �����ݒ� ////////
		//�F
		
		title_state++;
		/*fallthrough*/
	case 1:
		//////// �p�����[�^�̐ݒ� ////////
		//�J
		GameLib::setBlendMode(Blender::BS_ALPHA);
		title_state++;
		/*fallthrough*/
	case 2:
		//////// �ʏ펞 ////////
		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_GAME;
			break;
		}
		else if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_GATYA;
			break;
		}
		break;
	}
	//�B
	title_timer++;
}
void title_render()
{
	//�H
	GameLib::clear(0, 0.3f, 0.3f);
	//�I

	if ((title_timer / 20) % 2 == 0)
	{
		font::textOut(1, "start:enter", SCREEN_W/2-200,650, 1, 1, 1, 1, 1);
	}
}