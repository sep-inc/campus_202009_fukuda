#ifndef DRAWER_BASE_H_
#define DRAWER_BASE_H_

/**
* @file DrawerBase.h
* @brief DrawerBase�N���X�̃w�b�_
*/

#include "../Definition.h"
#include <string>

/**
* @class DrawerBase
* @brief Drawer�N���X�̊��N���X
*/
class DrawerBase {
public:
	DrawerBase();
	virtual ~DrawerBase();

	/**
	* @brief �`��֐�
	*/
	void Draw();

	/**
	* @brief �`����̃N���A�֐�
	* �`��Ɏg�p����
	*/
	void Clear();

	//! �`��p�o�b�t�@�̃Z�b�g�֐�
	virtual void SetDrawBuffer(Vec2 pos_, char* string_) = 0;

	/**
	* @brief ���U���g�����Z�b�g����֐�
	* @param result_ �o�͂��錋�ʂ̕�����
	*/
	void SetResultString(std::string result_);


protected:
	//! �`��o�b�t�@�̃N���A
	virtual void BufferClear() = 0;

	//! �`��o�b�t�@��A�����ĂP�̕�����֕ϊ�����֐�
	virtual void LinkDrawBuffer() = 0;

protected:
	//! �`��p������
	std::string m_draw_string;
	//! ���U���g�`��p������
	std::string m_result_string;
};

#endif
