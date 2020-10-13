#ifndef ENEMY_H_
#define ENEMY_H_

/**
* @file Enemy.h
* @brief Enemyクラスのヘッダ
*/

#include "CharacterBase.h"

class Enemy : public CharacterBase
{
public:
	Enemy();
	~Enemy()override;


private:
	/**
	* @brief 移動先選択関数
	* 移動可能先をランダムで決める
	*/
	void SelectMoveDirection()override;


};

#endif

