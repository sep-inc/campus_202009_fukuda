#ifndef PLAYER_BASE_H_
#define PLAYER_BASE_H_

/**
* @file PlayerBase.h
* @brief PlayerBase�N���X�̃w�b�_
*/

#include "../Definition.h"

/**
* @class PlayerBase
* @brief Player�̊��N���X
*/
class PlayerBase {
public:
	PlayerBase();
	~PlayerBase();

	//! �����X�V
	virtual void Update();
	//! �������֐�
	virtual void Init() = 0;

	/**
	* @brief �ǂ̋���ړ������邩�̑I�������֐�
	* @brief �I�񂾍��W
	*/
	virtual Vec2 SelectPiece();

	/**
	* @brief �ǂ̃}�X�ֈړ������邩�̑I�������֐�
	* @brief �I�񂾍��W
	*/
	virtual Vec2 SelectMoveSquares();

	/**
	* @brief ����ړ�������֐�
	* �����Ղ̃Z�b�g�֐����Ăяo��
	*/
	void MovePiece();

	/**
	* @brief ���̋������Ă��邩��Ԃ��֐�
	* @return ��������Ă�����true
	*/
	bool IsTakeKing();

protected:
	Step m_step;		//! ���݂̃X�e�b�v
	Vec2 m_select_pos;	//! �I��������̍��W
	Vec2 m_move_pos;	//! ��̈ړ���̍��W
	ObjectType m_take_piece;	//! ���O�Ɏ������
};

#endif
