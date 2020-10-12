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

};

#endif

