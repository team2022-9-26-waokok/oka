#include "all.h"

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;
extern int title_state;
extern int title_timer;
extern int game_state;
extern int gatya_timer;
extern int gatya_state;



int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	// �Q�[�����C�u�����̏����ݒ�
	GameLib::init(L"�����Ńv���W�F�N�g���쐬", SCREEN_W, SCREEN_H);
	//�@�^�C�g���̏����ݒ�
	title_init();


	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// Build atlas
	unsigned char* tex_pixels = NULL;
	int tex_w, tex_h;
	io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);
	// �Q�[�����[�v
	while (GameLib::gameLoop())
	{
		// �V�[���؂�ւ�����
		if (curScene != nextScene)
		{
			// ���͂��X�V����
			//input::update();
			//// ���݂̃V�[���ɉ������X�V�E�`�揈��
			//switch (curScene)
			//{
			//case SCENE_TITLE:
			//	title_update();
			//	title_render();
			//	break;
			//case SCENE_GAME:
			//	game_update();
			//	game_render();
			//	break;
			//}
			// ���̃V�[���ɉ����������ݒ菈��
			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;
			case SCENE_GAME:
				game_init();
				break;
			case SCENE_GATYA:
				gatya_init();
				break;
			}
			// nextScene �� curScene �ɂȂ�
			curScene = nextScene;
		}
		input::update();
		// ���݂̃V�[���ɉ������X�V�E�`�揈��
		switch (curScene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;
		case SCENE_GAME:
			game_update();
			game_render();
			break;
		case SCENE_GATYA:
			gatya_update();
			gatya_render();
		}
		//�B�^�C�g���̍X�V����
		//i
		// title_update();
		//�C�^�C�g���̕`�揈��
		//title_render();
		// �f�o�b�O�p������̕\��
		debug::display(1, 1, 1, 1, 1);
		debug::setString("title_state:%d", title_state);
		debug::setString("title_timer:%d", title_timer);
		debug::setString("game_state:%d", game_state);
		debug::setString("game_timer:%d", game_timer);
		debug::setString("act:%d", player_act);




		// ��ʂ�`�悷��
		GameLib::present(1, 0);
	}
	// ���݂̃V�[���ɉ������I���������s��
	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;
	case SCENE_GAME:
		game_deinit();
		break;
	case SCENE_GATYA:
		gatya_deinit();
		break;
	}
	// �Q�[�����C�u�����̏I������
	ImGui::DestroyContext();
	GameLib::uninit();
}