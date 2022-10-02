#pragma once
#ifndef OBJ2D_H
#define OBJ2D_H

struct OBJ2D
{
	typedef void(*FUNC_PTR)(OBJ2D*);
	FUNC_PTR			moveAlg; //移動アルゴリズム（ゲープロと同じ）

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


	float				radius;		//当たり判定の半径

	float				FSpeed; 
	float				basicSpeed;
	float				anglememoy;
	int				Out_of_range;//範囲外かどうか判断用
	int				Out_of_judge;//範囲外かどうか判断用
	int				Out_of_range_count; //でない場合の角度保持用
	bool			    exist;		//現在生成されているか
	int                 hit_ef; //ヒットエフェクト用
	int					act_type; //行動種類;

	float sun_color;
	OBJ2D* hitObj;		//前回攻撃がヒットした敵用ポインタ
};

#endif // !OBJ2D_H

