#ifndef ENEMY_H_
#define ENEMY_H_

#include "Definition.h"

/**
* @file Enemy.h
* @brief Enemy�N���X�̃w�b�_
*/


/**
* @class Enemy
* @brief Enemy�֌W�̏������s���N���X
*/
class Enemy
{
public:
	Enemy();
	~Enemy();

	/**
	* Enemy�N���X�������֐�
	* Step_Initialize�����ŌĂяo��
	*/
	void Init();

	/**
	* �X�e�b�v�X�V�֐�
	* �X�e�b�v���X�V���A�e�X�e�b�v���Ƃ̏������Ăяo��
	*/
	void Update();

	/**
	* ���͍��W�I���֐�
	* Map�N���X����󂫃}�X�̏������炢�A
	* ���̒����烉���_���œ��͂���ꏊ��I������
	*
	* @return �I���������W
	*/
	Vec2 SelectInputPos();

private:
	//! ���݂̏����X�e�b�v
	Step m_step;
	//! �`��^�C�v
	DrawType m_draw_type;
};

#endif

