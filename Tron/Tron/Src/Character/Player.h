#ifndef PLAYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief Player�N���X�̃w�b�_
*/

#include "CharacterBase.h"

/**
* @class Player
* @brief Player�����N���X
*/
class Player : public CharacterBase
{
public:
	Player();
	~Player()override;

};

#endif

