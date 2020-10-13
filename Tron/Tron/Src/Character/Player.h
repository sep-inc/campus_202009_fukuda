#ifndef PLAYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief Playerクラスのヘッダ
*/

#include "CharacterBase.h"

/**
* @class Player
* @brief Player処理クラス
*/
class Player : public CharacterBase
{
public:
	Player();
	~Player()override;

private:
	/**
	* @brief 移動先選択関数
	* 入力に応じて、移動先を選択する
	*/
	void SelectMoveDirection()override;

};

#endif

