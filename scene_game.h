#ifndef SCENE_GAME_H 
#define SCENE_GAME_H 

extern int cursor_posX;
extern int cursor_posY;//all.h���C���N���[�h���Ă��邷�ׂẴt�@�C���Ŏg�p�\�ɂȂ�

extern int game_score;
extern int game_state;
// �֐��̃v���g�^�C�v�錾 
void game_init();
void game_deinit();
void game_update();
void game_render();

#endif//SCENE_TITLE_H

