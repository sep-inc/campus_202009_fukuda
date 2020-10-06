#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief ��`���܂Ƃ߂��w�b�_
*/

#include <cinttypes>


struct Vec2 {
	int m_x;
	int m_y;
};

//! �����X�e�b�v�̎��
enum class Step :uint8_t {
	Initialize,	//! �������X�e�b�v
	Update,		//! �X�V�X�e�b�v
	End			//! ����X�e�b�v
};

//! �I�u�W�F�N�g�̎��
enum class ObjectType :uint8_t {
	Type_Empty,		//! �^�C�v�Ȃ�
	King1,			//! ��1
	Pawn1,			//! ��1
	GoldGeneral1,	//! ��1
	Knight1,		//! �j�n1
	King2,			//! ��2
	Pawn2,			//! ��2
	GoldGeneral2,	//! ��2
	Knight2			//! �j�n2
};

//! �v���C���[�^�C�v
enum class PlayerType :uint8_t {
	Type_None,
	Player1,
	Player2
};

//! �Q�[���I�����ʂ̎��
enum class ResultType :uint8_t {
	Result_None,	//! ���ʖ���
	Win_Player1,	//! �v���C���[1�̏���
	Win_Player2		//! �v���C���[2�̏���
};

//! �`��o�b�t�@�̃T�C�Y
#define DRAW_BUFFER_WIDTH  10
#define DRAW_BUFFER_HEIGHT 12

//! �����Ղ̃T�C�Y
#define SHOGI_BOARD_WIDTH  4
#define SHOGI_BOARD_HEIGHT 5

//! ��̓�����͈͂̃T�C�Y
#define MOVE_RANGE_WIDTH  3
#define MOVE_RANGE_HEIGHT 3

#endif

