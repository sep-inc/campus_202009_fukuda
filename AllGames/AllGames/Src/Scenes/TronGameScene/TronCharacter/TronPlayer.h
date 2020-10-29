#ifndef TRON_PLAYER_H_
#define TRON_PLAYER_H_

#include "TronCharacterBase.h"

/**
* @class Player
* @brief Player処理クラス
*/
class TronPlayer : public TronCharacterBase
{
public:
	TronPlayer();
	~TronPlayer()override;

	void Init(TronGameMap* map_)override;

private:
	/**
	* @brief 移動先選択関数
	* 入力に応じて、移動先を選択する
	*/
	void SelectMoveDirection()override;

};

#endif
