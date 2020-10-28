#ifndef PACMEN_PLAYER_H_
#define PACMEN_PLAYER_H_

#include "PacMenCharacter.h"

/**
* @class Player
* @brief プレイヤーの処理クラス
*/
class PacMenPlayer : public PacMenCharacterBase
{
public:
	PacMenPlayer();
	~PacMenPlayer();

	/**
	* @brief 移動座標選択関数
	* 入力情報に従って移動座標を選択する
	*
	* @return 選択した座標
	*/
	void SelectMovePos()override;

	/**
	* @brief 当たり判定処理関数
	* @ return bool モンスターと当たっていたらtrue
	*/
	bool CheckHit()override;
};

#endif

