#ifndef ANIME_FUN_H
#define ANIME_FUN_H
//変数anime_startは何枚目からアニメーションを始めるかを示す
//アニメーション関連のシステムをポインタを使って直接動かす関数
//毎回アニメ関数を作るのが面倒というだけ
void animeInit(OBJ2D* obj, int animeNo, float anime_start);
bool anime(OBJ2D* obj, int total, int frame, float anime_start, bool loop);

#endif // !ANIME_FUN