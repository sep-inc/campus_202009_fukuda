#ifndef TRON_DRAWER_H_
#define TRON_DRAWER_H_

/**
* @file TronDrawer.h
* @brief TronDrawer�N���X�̃w�b�_
*/

#include "DrawerBase.h"

/**
* @class TronDrawer
* @brief Tron�Q�[����Drawer�N���X
*/
class TronDrawer : public DrawerBase
{
public:
	TronDrawer();
	~TronDrawer()override;
	
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
	char m_blank_buffer[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH][DRAW_STRING_SIZE];
	//! �`��p�o�b�t�@
	char m_draw_buffer[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH][DRAW_STRING_SIZE];

};


#endif

