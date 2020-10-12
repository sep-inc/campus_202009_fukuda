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



//! �Q�[���̎��
enum class GameType : uint8_t
{
	TYPE_NONE,	//! �^�C�v����
	TRON,		//! �g����

	MAX_TYPE
};

//! �}�b�v��̃I�u�W�F�N�g�̎��
enum class ObjectType : uint8_t
{
	TYPE_EMPTY,	//! ��
	PLAYER,		//! �v���C���[
	ENEMY,		//! �G�l�~�[
	FRAME,		//! �O�g

	MAX_TYPE
};


struct Vec2
{
	int m_x;
	int m_y;
};

//! �L�����N�^�[�ɕK�v�ȃp�����[�^�Q
struct CharacterParam
{
	ObjectType m_type;						//! ���g�̎��
	char m_draw_string[DRAW_STRING_SIZE];	//! �`��̕���

	//! ��ŏ�����
	CharacterParam() :
		m_type(ObjectType::TYPE_EMPTY),
		m_draw_string("�@")
	{}
};



#endif

