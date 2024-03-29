#include "all.h"
int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;
extern int title_state;
extern int title_timer;
extern int game_state;
extern int game_timer;


int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	// ゲームライブラリの初期設定
	GameLib::init(L"自分でプロジェクトを作成", SCREEN_W, SCREEN_H);
	//�@タイトルの初期設定
	title_init();
	// ゲームループ
	while (GameLib::gameLoop())
	{
		// シーン切り替え処理
		if (curScene != nextScene)
		{
			// 入力を更新する
			//input::update();
			//// 現在のシーンに応じた更新・描画処理
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
			// 次のシーンに応じた初期設定処理
			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;
			case SCENE_GAME:
				game_init();
				break;
			}
			// nextScene が curScene になる
			curScene = nextScene;
		}
		input::update();
		// 現在のシーンに応じた更新・描画処理
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
		}
		//�Bタイトルの更新処理
		//i
		// title_update();
		//�Cタイトルの描画処理
		//title_render();
		// デバッグ用文字列の表示
		debug::display(1, 1, 1, 1, 1);
		debug::setString("title_state:%d", title_state);
		debug::setString("title_timer:%d", title_timer);
		debug::setString("game_state:%d", game_state);
		debug::setString("game_timer:%d", game_timer);
		// 画面を描画する
		GameLib::present(1, 0);
	}
	// 現在のシーンに応じた終了処理を行う
	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;
	case SCENE_GAME:
		game_deinit();
		break;
	}
	// ゲームライブラリの終了処理
	GameLib::uninit();
}