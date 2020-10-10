#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief Inputクラスのヘッダ
*/

#include  "../Definition.h"

//! 入力キー
#define LEFT_KEY	0x4b
#define RIGHT_KEY	0x4d
#define UP_KEY		0x48
#define DOWN_KEY	0x50

/**
* @class Input
* @brief 入力処理クラス
*/
class Input 
{
public:
	static Input* Instance();

	/**
	* @brief 方向入力処理関数
	* @return 入力された方向に合わせた移動量
	*/
	Vec2 InputDirection();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif
