#pragma once
#ifndef CAMERA_H
#define CAMERA_H
//��ʃX�N���[���ɂ������֐�


#define CAMERA_SCROLL_X 50 
#define CAMERA_SCROLL_Y 50 //�v���C���[�����S����ړ��ł��鋗���i�}�b�v�̒[�܂ŗ����ꍇ�͗�O�j
							//����𒴂���Ɖ�ʂ��X�N���[������v���C���[�̍��W�͓����Ȃ�

void camera_init();
void camera_update();

void camera_scroll(OBJ2D* obj);//�I�u�W�F�N�g�̍��W����ʃX�N���[����̍��W�ɓ���ւ���
void camera_move(OBJ2D* obj);

#endif // !CAMERA_H

