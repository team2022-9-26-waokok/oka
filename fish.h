#ifndef FISH_H
#define FISH_H
// �֐��̃v���g�^�C�v�錾
extern OBJ2D player;//all.h���C���N���[�h���Ă��邷�ׂẴt�@�C���Ŏg�p�\�ɂȂ�
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