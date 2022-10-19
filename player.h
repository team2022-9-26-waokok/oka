#ifndef PLAYER_H
#define PLAYER_H
// 関数のプロトタイプ宣言
extern OBJ2D player;//all.hをインクルードしているすべてのファイルで使用可能になる
extern OBJ2D fishR;//all.hをインクルードしているすべてのファイルで使用可能になる

void player_init();
void player_deinit();
void player_update();
void player_render();
void plrender();
void battle_render();
void Frender();
enum playeract
{
	
	NORMAL,
	NORMAL_TRANS,
	FISHING,
	FISHING_TRANS,
	FISHING_BTTLE,
	FISHING_BTTLE_TRANS,
	FISHUP,
	FEVER,
	FEVER_TRANS,
	FEVERFISHING,
	FEVERFISHING_TRANS,
	FEVERFISHING_BTTLE,
	FEVERFISHING_BTTLE_TRANS,
	GACHA,
	COLLECTION
};
extern int player_act;

#endif//PLAYER_H