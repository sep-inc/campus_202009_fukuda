#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief ��`���܂Ƃ߂��w�b�_
*/

#include <cinttypes>

//! �g�����̕`��p�o�b�t�@�T�C�Y
#define TRON_DRAW_BUFFER_WIDTH  20
#define TRON_DRAW_BUFFER_HEIGHT 14

//! �`�悷�镶����̃T�C�Y
#define DRAW_STRING_SIZE 8

struct Vec2
{
	int m_x;
	int m_y;
};

//! �Q�[���̎��
enum class GameType : uint8_t 
{
	TYPE_NONE,	//! �^�C�v����
	TRON,		//! �g����

	MAX_TYPE
};

#endif

