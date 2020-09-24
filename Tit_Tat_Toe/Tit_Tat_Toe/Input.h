#ifndef INPUT_H_
#define INPUT_H_

#include "Definition.h"

/**
* @file Input.h
* @brief Inputクラスのヘッダ
*/


/**
* @class Input
* @brief 入力関係の処理をするクラス
*/
class Input {
public:
	Input();
	~Input();

	/**
	* プレイヤーの入力関数
	* プレイヤーが入力するX、Y座標の情報を取得する
	* Playerクラスから呼び出される
	*
	* @return 入力されたXY座標
	*/
	Vec2 InputPlayer();

private:

};

#endif

