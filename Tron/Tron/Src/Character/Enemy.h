#ifndef ENEMY_H_
#define ENEMY_H_

/**
* @file Enemy.h
* @brief Enemy�N���X�̃w�b�_
*/

#include "CharacterBase.h"

class Enemy : public CharacterBase
{
public:
	Enemy();
	~Enemy()override;


private:
	/**
	* @brief �ړ���I���֐�
	* �ړ��\��������_���Ō��߂�
	*/
	void SelectMoveDirection()override;


};

#endif

