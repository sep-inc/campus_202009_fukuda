#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief ��`���܂Ƃ߂��w�b�_
*/

#include <cinttypes>


//! �I�u�W�F�N�g�̎��
enum class ObjectType :uint8_t {
	Type_None,		//! �^�C�v�Ȃ�
	King,			//! ��
	Pawn,			//! ��
	GoldGeneral,	//! ��
	Knight			//! �j�n
};

//! �`��o�b�t�@�̃T�C�Y
#define DRAW_BUFFER_WIDTH  10
#define DRAW_BUFFER_HEIGHT 12

#endif

