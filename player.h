#ifndef PLAYER_H
#define PLAYER_H
// 関数のプロトタイプ宣言
extern OBJ2D player;//all.hをインクルードしているすべてのファイルで使用可能になる

void player_init();
void player_deinit();
void player_update();
void player_render();

enum playeract
{
	
	NORMAL,
	NORMAL_TRANS,
	FISHING,
	FISHING_TRANS,
	FISHING_BTTLE,
	FISHING_BTTLE_TRANS,
	FEVER,
	FEVER_TRANS,
	FEVERFISHING,
	FEVERFISHING_TRANS,
	FEVERFISHING_BTTLE,
	FEVERFISHING_BTTLE_TRANS,
	GACHA,
	COLLECTION
};

#endif//PLAYER_H