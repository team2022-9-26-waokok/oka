//----< インクルード >-----------------------------------------------------------
#include "all.h"

//------< 定数 >----------------------------------------------------------------


//------< 変数 >----------------------------------------------------------------
int game_state = 0;     // 状態
int game_timer = 0;     // タイマー

int cursor_posX, cursor_posY;

#if 1
//******************************************************************************
// TODO:01 スプライトの用意
//------------------------------------------------------------------------------
/*
課題）
    □ 車とコースのスプライトを用意します。

手順）
    1. 下記にSprite*型の sprCar と sprCourse を定義します。

    2. game_update()のcase 0:初期設定のところで画像を読み込みます。
        sprCar      L"./Data/Images/up.png"
        sprCourse   L"./Data/Images/course.png"

    3. game_deinit()でスプライトを破棄します。
        safe_delete関数
*/
//******************************************************************************
#endif
//TODO_01


#if 3
//******************************************************************************
// TODO:03 位置用の変数を用意
//------------------------------------------------------------------------------
/*
課題）
    □ 車の位置用の変数を用意しましょう。

手順）
    1. 下記にfloat型の carPosX と carPosY を定義します。

    2. game_update()のcase 1:パラメータの設定のところで初期値を入れておきます。
        carPosX     SCREEN_W / 2
        carPosY     SCREEN_H / 2
*/
//******************************************************************************
#endif
//TODO_03
float carPosX, carPosY;
float speedX, speedY = 0;

#if 5
//******************************************************************************
// TODO:05 角度用の変数を用意
//------------------------------------------------------------------------------
/*
課題）
    □ 車の向き用の変数angleを定義しましょう。

手順）
    1. 下記でfloat型の angle を定義する。

    2. game_update()のcase 1:パラメータの設定のところで初期値を入れておきます。
        angle       ToRadian(0)

    3. TODO_04で車を描画している箇所で、角度のところを angle にする。
*/
//******************************************************************************
#endif
//TODO_05
float angle;

#if 8
//******************************************************************************
// TODO:08 速度用の変数を用意
//------------------------------------------------------------------------------
/*
課題）
    □ 速度を表す変数を用意しましょう。

手順）
    1. 下記で、float型の speed を定義します。

    2. game_update()のcase 1:パラメータの設定のところで初期値を入れておきます。
        speed       0
*/
//******************************************************************************
#endif
//TODO_08
float speed;
float gageB = speed / 25;
int carPosY2;
int carPosX2;

//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
}

//--------------------------------------
//  更新処理
//--------------------------------------
void game_update()
{
    using namespace input;

    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        game_state++;
        /*fallthrough*/
    case 1:
        //////// パラメータの設定 ////////


        // ブレンドモードの設定（後日学習予定）
        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        /*fallthrough*/
    case 2:
        //////// 通常時 ////////

<<<<<<< HEAD
        debug::setString("[Operation]");
        debug::setString("Accel  : Up Arrow");
        debug::setString("Brake  : Down Arrow");
        debug::setString("");
=======
        //debug::setString("[Operation]");
        //debug::setString("Rotate : A, D");
        //debug::setString("Accel  : Up Arrow");
        //debug::setString("Brake  : Down Arrow");
        //debug::setString("");
>>>>>>> origin/washida

        cursor_posX = getCursorPosX();
        cursor_posY = getCursorPosY();
        map_update();
        camera_update();
        player_update();
        fish_update();
        break;

    }

    game_timer++;
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
    // 画面をクリアする
    GameLib::clear(0.2549f, 0.5569f, 0.1020f);
 
 
    map_render();
    fish_render();

    //primitive::line(900, 30, 1275, 30, 1, 1, 1, 0.4f, 50);
    //primitive::line(902, 30, 902 + 371 * gageB, 30, 0, 1, 1, 1.0f, 48);
    GameLib::primitive::rect(0, 0, 1280, 720, 0, 0, 0, 0.2f, 0.7f, 0.7f, 0.3f);
    player_render();
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{

}
