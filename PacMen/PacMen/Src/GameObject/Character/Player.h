#ifndef PALYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief Playerクラスのヘッダ
*/

#include "CharacterBase.h"

/**
* @class Player
* @brief プレイヤーの処理クラス
*/
class Player : public CharacterBase
{
public:
	Player();
	~Player();

	/**
	* @brief 移動座標選択関数
	* 入力情報に従って移動座標を選択する
	*
	* @return 選択した座標
	*/
	void SelectMovePos()override;

	bool CheckHit()override;
};

#endif
