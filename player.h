#ifndef PLAYER_H
#define PLAYER_H
// �֐��̃v���g�^�C�v�錾
extern OBJ2D player;//all.h���C���N���[�h���Ă��邷�ׂẴt�@�C���Ŏg�p�\�ɂȂ�

void player_init();
void player_deinit();
void player_update();
void player_render();

enum playeract
{
	
	NORMAL,
	NORMAL_TRANS,
	FISHING,
	FISHING_TRANS,
	FEVER,
	FEVER_TRANS,
	FEVERFISHING,
	FEVERFISHING_TRANS,
	GACHA,
	COLLECTION
};

#endif//PLAYER_H