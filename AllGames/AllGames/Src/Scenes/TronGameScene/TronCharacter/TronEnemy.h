#ifndef TRON_ENEMY_H_
#define TRON_ENEMY_H_

#include "TronCharacterBase.h"

class TronEnemy : public TronCharacterBase
{
public:
	TronEnemy();
	~TronEnemy()override;

	void Init(TronGameMap* map_)override;


private:
	/**
	* @brief 移動先選択関数
	* 移動可能先をランダムで決める
	*/
	void SelectMoveDirection()override;


};

#endif
