#ifndef ALL_H
#define ALL_H
// システムやライブラリのヘッダーファイルは上の方へ
#include "../GameLib/game_lib.h"
#include "../GameLib/input_manager.h"
#include "../GameLib/obj2d_data.h"

// 共通で使われるようなヘッダー
#include "common.h"
#include "obj2d.h"
#include "camera.h"
#include "player.h"


// 個々のファイルは下のほうへ
#include "scene_game.h"
#include "scene_title.h"
using namespace GameLib;
using namespace input;
#endif//ALL_H