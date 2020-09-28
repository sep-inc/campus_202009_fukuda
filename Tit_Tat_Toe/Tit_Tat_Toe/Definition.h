#ifndef DEFINITION_H_
#define DEFINITION_H_

#include <cstdint>

/**
* @file Definition.h
* @brief ��`���܂Ƃ߂��w�b�_
*/


/**
* @brief �`��p�o�b�t�@�̃T�C�Y
*/
#define DRAW_BUFFER_WIDTH 8
#define DRAW_BUFFER_HEIGHT 8


/**
* @brief �Q�[���}�b�v�̃T�C�Y
*/
#define GAME_MAP_WIDTH 3
#define GAME_MAP_HEIGHT 3


/**
* @brief �ő�^�[����
*/
#define MAX_TURN_NUM 4


/**
* @brief �Q�[���Ŏg�p����x,y���W�p�\����
*/
struct Vec2 {
	int8_t m_x;
	int8_t m_y;
};


/**
* @brief �`�悷��ۂɁA���ʂŎg���`��^�C�v
*/
enum class DrawType :uint8_t {
	TypeNone,			//! �^�C�v����
	Player,				//! �v���C���[�F�Z
	Enemy,				//! ����F�~
	HalfWidthSpace,		//! ���p�X�y�[�X
	HalfWidthSpace2,	//! ���p�X�y�[�X�Q��
	UpperLeft,			//! ����p�F��
	UpperRight,			//! �E��p�F��
	LowerLeft,			//! �����p�F��
	LowerRight,			//! �E���p�F��
	UpperMiddle,		//! �㒆���F��
	LowerMiddle,		//! �������F��
	MiddleLeft,			//! �������F��
	MiddleRight,		//! �E�����F��
	Middle,				//! �����F��
	VerticalLine,		//! �c���F��
	HorizontalLine,		//! �����F��
	CharA,				//! �����FA
	CharB,				//! �����FB
	CharC,				//! �����FC
	Num1,				//! �����F�P
	Num2,				//! �����F�Q
	Num3,				//! �����F�R

	MAX_TYPE
};


/**
* @brief �����X�e�b�v�̗�
*/
enum class Step :uint8_t {
	Step_Initialize,	//! �������X�e�b�v
	Step_Run,			//! �����X�e�b�v
	Step_End,			//! ����X�e�b�v			

	MAX_STEP
};


/**
* @brief ���s���ʂ̗�
*/
enum class MatchResult :uint8_t {
	None,	
	Win,	//! ����
	Lose,	//! �s�k
	Draw	//! ��������
};

#endif

