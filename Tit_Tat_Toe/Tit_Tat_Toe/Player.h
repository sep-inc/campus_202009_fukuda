#ifndef PLAYER_H_
#define PLAYER_H_

#include "Definition.h"

/**
* @file Player.h
* @brief Player�N���X�̃w�b�_
*/


/**
* @class Player
* @brief Player�֌W�̏������s���N���X
*/
class Player{
public:
	Player();
	~Player();

	/**
	* Player�N���X�������֐�
	* Step_Initialize���ɌĂяo�����
	*/
	void Init();

	/**
	* �X�e�b�v�����X�V�֐�
	* �X�e�b�v���Ƃɏ������Ăяo��
	*/
	void Update();

private:
	//! ���݂̏����X�e�b�v
	Step m_step;
	//! �`��^�C�v
	DrawType m_draw_type;
	//! ���͂������W�ۑ��ϐ�
	Vec2 m_input_pos;

};

#endif

