#ifndef FISH_H
#define FISH_H
// �֐��̃v���g�^�C�v�錾


#define type_num 5

extern int fish_MAX;
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

enum F_angle
{
	F_UP,
	F_DAWN,
	F_LEFT,
	F_RIGHT

};
enum F_act
{
	F_NORMAL, 
	F_FISHING,

};
enum A_type
{
	STRAIGHT,//����
	LEFT,
	RIGHT,


};
#endif//FISH_H