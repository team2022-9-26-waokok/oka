#ifndef ANIME_FUN_H
#define ANIME_FUN_H
//�ϐ�anime_start�͉����ڂ���A�j���[�V�������n�߂邩������
//�A�j���[�V�����֘A�̃V�X�e�����|�C���^���g���Ē��ړ������֐�
//����A�j���֐������̂��ʓ|�Ƃ�������
void animeInit(OBJ2D* obj, int animeNo, float anime_start);
bool anime(OBJ2D* obj, int total, int frame, float anime_start, bool loop);

#endif // !ANIME_FUN