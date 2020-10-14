#ifndef PACMEN_DRAWER_H_
#define PACMEN_DRAWER_H_

/**
* @file PacMenDrawer.h
* @brief PacMenDrawer�N���X�̃w�b�_
*/

#include "DrawerBase.h"

/**
* @class PacMenDrawer
* @brief PacMen�Q�[����Drawer�N���X
*/
class PacMenDrawer : public DrawerBase
{
public:
	PacMenDrawer();
	~PacMenDrawer();

	/**
	* @brief �������p�o�b�t�@�̃Z�b�g�֐�
	* @param pos_ �Z�b�g�������ʒu
	* @param string_ �Z�b�g���镶����
	*/
	void SetBlankBuffer(Vec2 pos_, char* string_)override;

	/**
	* @brief �`��p�o�b�t�@�̃Z�b�g�֐�
	* @param pos_ �Z�b�g�������ʒu
	* @param string_ �Z�b�g���镶����
	*/
	void SetDrawBuffer(Vec2 pos_, char* string_)override;


private:
	/**
	* @brief �`��p�o�b�t�@�̃N���A�֐�
	*/
	void BufferClear()override;

	/**
	* @brief �`��o�b�t�@��A�����ĂP�̕�����֕ϊ�����֐�
	*/
	void LinkDrawBuffer()override;

private:
	//! �������p�o�b�t�@
	char m_blank_buffer[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH];
	//! �`��p�o�b�t�@
	char m_draw_buffer[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH][DRAW_STRING_SIZE];

};

#endif

