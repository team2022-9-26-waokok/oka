#pragma once
#ifndef OBJ2D_H
#define OBJ2D_H

struct OBJ2D
{
	typedef void(*FUNC_PTR)(OBJ2D*);
	FUNC_PTR			moveAlg; //�ړ��A���S���Y���i�Q�[�v���Ɠ����j

	int					state;
	int					timer;

	GameLib::Sprite* spr;

	VECTOR2				pos;
	VECTOR2				Memoypos;
	VECTOR2				scale;
	VECTOR2				texPos;
	VECTOR2				texSize;
	VECTOR2				pivot;
	VECTOR4				color;
	VECTOR2				size;

	VECTOR2				speed;
	int					act;
	int					anime;
	int					animeTimer;

	float				angle;


	VECTOR2				scroll;

	int					level;
	int					direc;


	float				radius;		//�����蔻��̔��a

	float				FSpeed; 
	float				basicSpeed;
	float				anglememoy;
	int				Out_of_range;//�͈͊O���ǂ������f�p
	int				Out_of_judge;//�͈͊O���ǂ������f�p
	int				Out_of_range_count; //�łȂ��ꍇ�̊p�x�ێ��p
	bool			    exist;		//���ݐ�������Ă��邩
	int                 hit_ef; //�q�b�g�G�t�F�N�g�p
	int					act_type; //�s�����;

	float sun_color;
	OBJ2D* hitObj;		//�O��U�����q�b�g�����G�p�|�C���^
};

#endif // !OBJ2D_H

