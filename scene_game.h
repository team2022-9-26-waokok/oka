#ifndef SCENE_GAME_H 
#define SCENE_GAME_H 

extern int cursor_posX;
extern int cursor_posY;//all.hをインクルードしているすべてのファイルで使用可能になる

extern int game_score;
extern int game_state;
// 関数のプロトタイプ宣言 
void game_init();
void game_deinit();
void game_update();
void game_render();

#endif//SCENE_TITLE_H

