#ifndef ALL_H
#define ALL_H
// システムやライブラリのヘッダーファイルは上の方へ
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "../GameLib/obj2d_data.h"

// 共通で使われるようなヘッダー
#include "common.h"

#include "obj2d.h"
#include "anime_fnc.h"
#include "camera.h"
#include "player.h"
#include "fish.h"

#include "easing.h"





// 個々のファイルは下のほうへ
#include "scene_game.h"
#include "scene_title.h"
#include "scene_gatya.h"
using namespace GameLib;
using namespace input;
extern int game_timer;

#endif//ALL_H