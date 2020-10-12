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

};

#endif

