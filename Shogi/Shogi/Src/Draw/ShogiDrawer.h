#ifndef SHOGI_DRAWER_H_
#define SHOGI_DRAWER_H_

/**
* @file ShogiDrawer.h
* @brief ShogiDrawer�N���X�̃w�b�_
*/

#include "DrawerBase.h"
#include "../Definition.h"

/**
* @class ShogiDrawer
* ShogiGame�Ŏg�p�����Drawer�N���X
*/
class ShogiDrawer : public DrawerBase {
public:
	ShogiDrawer();
	~ShogiDrawer()override;

	/**
	@ brief �`��o�b�t�@�N���A�֐�
	*/
	void ClearBuffer()override;

	/**
	* @brief �`��o�b�t�@�֏������ފ֐�
	* @param x �`�掞��X���W
	* @param y �`�掞��Y���W
	* @param type �`�悷����
	*/
	void SetDrawBuffer(int x, int y, ObjectType type);

	/**
	* @brief �������p�o�b�t�@�֏������ފ֐�
	* @param x �`�掞��X���W
	* @param y �`�掞��Y���W
	* @param type �`�悷����
	*/
	void SetBlankBuffer(int x, int y, ObjectType type);

	/**
	* @brief ���U���g�����Z�b�g����֐�
	*/
	void SetResult();

private:
	//! �������p�o�b�t�@
	ObjectType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	//! �`��p�o�b�t�@
	ObjectType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

};

#endif
