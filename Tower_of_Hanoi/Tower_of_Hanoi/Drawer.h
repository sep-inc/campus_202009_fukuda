#ifndef DRAWER_H_
#define DRAWER_H_

/**
* @file Drawer.h
* @brief Drawer�N���X�̃w�b�_
*/


#include "Definition.h"
#include <string>

/**
* @class Drawer.h
* @brief �`��N���X
*/
class Drawer
{
public:
	Drawer();
	~Drawer();

	/**
	* @brief �������֐�
	*/
	void Init();

	/**
	* @brief �`�揈�����܂Ƃ߂��֐�
	* Main�ł͂��̊֐��݂̂��Ăяo��
	*/
	void Run();

	/**
	* @brief �`��֐�
	* �A�������������`�悷��
	*/
	void Print();

	/**
	* @brief �o�b�t�@�N���A�֐�
	*/
	void BufferClear();

	/**
	* @brief �`��o�b�t�@�Ƀf�[�^���Z�b�g����֐�
	*/
	void SetDrawBuffer(int x, int y, DrawType type);

	/**
	* @brief �������p�o�b�t�@�Ƀf�[�^���Z�b�g����֐�
	*/
	void SetBlankBuffer(int x, int y, DrawType type);

	/**
	* @brief �`��o�b�t�@�A���֐�
	* �`��o�b�t�@�̒��g��1�̕�����ɘA������
	*/
	void LinkDrawBuffer();

private:
	//! �������p�o�b�t�@
	DrawType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

	//! �`��p�o�b�t�@
	DrawType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

	std::string m_draw_string;
};

#endif
