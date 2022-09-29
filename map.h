#pragma once
#ifndef MAP_H
#define MAP_H

#define MAP_TIP_X 100
#define MAP_TIP_Y 60

#define MAP_X 24//実際に描画するチップ数
#define MAP_Y 16

void map_init();
void map_deinit();
void map_update();
void map_render();

#endif // !STAGE_H

