#ifndef PLAYER_H
#define PLAYER_H
// 関数のプロトタイプ宣言
extern OBJ2D player;//all.hをインクルードしているすべてのファイルで使用可能になる

void player_init();
void player_deinit();
void player_update();
void player_render();

#endif//PLAYER_H