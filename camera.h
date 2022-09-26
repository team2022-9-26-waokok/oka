#pragma once
#ifndef CAMERA_H
#define CAMERA_H
//画面スクロールにかかわる関数


#define CAMERA_SCROLL_X 50 
#define CAMERA_SCROLL_Y 50 //プレイヤーが中心から移動できる距離（マップの端まで来た場合は例外）
							//これを超えると画面がスクロールされプレイヤーの座標は動かない

void camera_init();
void camera_update();

void camera_scroll(OBJ2D* obj);//オブジェクトの座標を画面スクロール後の座標に入れ替える
void camera_move(OBJ2D* obj);

#endif // !CAMERA_H

