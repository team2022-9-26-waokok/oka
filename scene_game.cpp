//----< インクルード >-----------------------------------------------------------
#include "all.h"
#include<sstream>
#include<iomanip>


//------< 定数 >----------------------------------------------------------------

std::stringstream ss;

//------< 変数 >----------------------------------------------------------------
int game_state = 0;     // 状態
int game_timer = 0;     // タイマー
extern int TimeLimit;
extern int fevertimer;
extern int score;
int cursor_posX, cursor_posY;


float carPosX, carPosY;
float speedX, speedY = 0;


float angle;

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


        //debug::setString("[Operation]");
        //debug::setString("Rotate : A, D");
        //debug::setString("Accel  : Up Arrow");
        //debug::setString("Brake  : Down Arrow");
        //debug::setString("");

        cursor_posX = getCursorPosX();
        cursor_posY = getCursorPosY();
        map_update();
        camera_update();
        player_update();
        fish_update();

        ss = {};
        ss << score;
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

  
    //text_out(1, ss.str().c_str(), 900, 15, 1, 1, 1.0f, 1.0f, 1.0f);

    map_render();
    fish_render();

    //primitive::line(900, 30, 1275, 30, 1, 1, 1, 0.4f, 50);
    //primitive::line(902, 30, 902 + 371 * gageB, 30, 0, 1, 1, 1.0f, 48);
    GameLib::primitive::rect(0, 0, 1280, 720, 0, 0, 0, 0.2f, 0.7f, 0.7f, 0.3f);



    text_out(1, "SCORE:", 900, 15, 1, 1, 1.0f, 1.0f, 1.0f);
    text_out(1, ss.str(), 1100, 15, 1, 1, 1.0f, 1.0f, 1.0f,1.0f);
    if (fevertimer > 0)
    {
        text_out(1, "FEVERTIME", 500, 15, 1, 1, 0.0f, 0.0f, 0.0f);
    }
    player_render();
    Frender();
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{

}

//1245r23t8iyelu fbyvoe8 bgb 9o8eb7tp08o427n@0247nbrh0-2@3nbrt032vb08ty409by420rby32y 