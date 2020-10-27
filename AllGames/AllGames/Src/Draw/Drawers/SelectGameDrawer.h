#ifndef SELECT_GAME_DRAWER_H_
#define SELECT_GAME_DRAWER_H_

#include "DrawerBase.h"
#include "../../Scenes/SelectGameScene/SelectGameDefinition.h"

/**
* @class SelectGameDrawer
* @brief SelectGame�Ɏg�p����Drawer�N���X
*/
class SelectGameDrawer : public DrawerBase
{
public:
	SelectGameDrawer();
	~SelectGameDrawer();

	/**
	* @brief �`��p�o�b�t�@�̃Z�b�g�֐�
	* @param pos_ �Z�b�g�������ʒu
	* @param string_ �Z�b�g���镶����
	*/
	void SetDrawBuffer(Vec2_Int pos_, char* string_)override;


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
	char m_blank_buffer[SELECT_GAME_DRAW_HEIGHT][SELECT_GAME_DRAW_WIDTH][SELECT_GAME_DRAW_STRING_SIZE];
	//! �`��p�o�b�t�@
	char m_draw_buffer[SELECT_GAME_DRAW_HEIGHT][SELECT_GAME_DRAW_WIDTH][SELECT_GAME_DRAW_STRING_SIZE];


};

#endif
