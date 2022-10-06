#include "common.h"

//  �萔
const FLOAT PI{ DirectX::XM_PI };
//const LONG SCREEN_W{ 1280 };
const LONG SCREEN_W{ 1280 };
const LONG SCREEN_H{ 720 };
const BOOL FULLSCREEN{ FALSE };
const LPCWSTR APPLICATION_NAME{ L"C++ project template" };

//  �֐��|�C���^
float(* const ToRadian)(float) = DirectX::XMConvertToRadians;  // �p�x�����W�A����
float(* const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ���W�A�����p�x��



bool InArea(const VECTOR2& leftTop, const float& areaSizeW, const float& areaSizeT ,const VECTOR2 point_)
{
	const bool check_x = (static_cast<float>(point_.x) >= leftTop.x &&
		static_cast<float>(point_.x) <= leftTop.x + areaSizeW);

	const bool check_y = (static_cast<float>(point_.y) >= leftTop.y &&
		static_cast<float>(point_.y) <= leftTop.y + areaSizeT);

	if (check_x && check_y)
		return true;
	else
		return false;
}