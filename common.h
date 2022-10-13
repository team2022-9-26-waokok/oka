#ifndef COMMON_H
#define COMMON_H

#include "../GameLib/game_lib.h"
using namespace GameLib;

// シーンのラベル
#define SCENE_NONE -1
#define SCENE_TITLE 0
#define SCENE_GAME 1
#define SCENE_GATYA 2
//  定数
extern const FLOAT PI;
extern const LONG SCREEN_W;
extern const LONG SCREEN_H;
extern const BOOL FULLSCREEN;
extern const LPCWSTR APPLICATION_NAME;
// 変数の宣言
extern int curScene;
extern int nextScene;


//  関数ポインタ
extern float(* const ToRadian)(float);// 角度をラジアンに
extern float(* const ToDegree)(float);// ラジアンを角度に
extern int uniform_int(int n);
extern bool InArea(const VECTOR2& leftTop, const float& areaSizeW, const float& areaSizeT, const VECTOR2 point_);

#endif // !COMMON_H
