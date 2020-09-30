#ifndef PLAYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief �v���C���[�N���X�̃w�b�_
*/


#include "Definition.h"

/**
* @class Player
* @brief Player�̏������܂Ƃ߂��N���X
*/
class Player 
{
public:
	Player();
	~Player();

	/**
	* @brief �X�e�b�v�����֐�
	* �X�e�b�v���Ƃ̏������s���A���̊֐������C���ŌĂяo��
	*/
	void UpdateStep();

	/**
	* @brief ���͏����֐�
	* Input�N���X������͊֐����Ăяo��
	*/
	void Input();
	

private:
	Step m_step;				// ���݂̃X�e�b�v
	int m_source_pile_num;		// �ړ�������~�Ղ̂���Y�̔ԍ�
	int m_destination_pile_num;	// �ړ���̍Y�̔ԍ�

};

#endif
