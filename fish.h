#ifndef FISH_H
#define FISH_H
// 関数のプロトタイプ宣言
extern OBJ2D player;//all.hをインクルードしているすべてのファイルで使用可能になる
#define type_num 5


void fish_init();
void fish_deinit();
void fish_update();
void fish_render();
void plrender();

struct Fdata
{
	int power;
	int range;

};

#endif//FISH_H