#ifndef RUN_GAME_DRAWER_H_
#define RUN_GAME_DRAWER_H_

#include "DrawerBase.h"
#include "../../Scenes/RunGameScene/RunGameDefinition.h"

/**
* @class RunGameDrawer
* @brief Run�Q�[���Ɏg�p����Drawer�N���X
*/
class RunGameDrawer : public DrawerBase
{
public:
	RunGameDrawer();
	~RunGameDrawer();

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
	char m_blank_buffer[RUNGAME_DRAW_HEIGHT][RUNGAME_DRAW_WIDTH][RUNGAME_DRAW_STRING_SIZE];
	//! �`��p�o�b�t�@
	char m_draw_buffer[RUNGAME_DRAW_HEIGHT][RUNGAME_DRAW_WIDTH][RUNGAME_DRAW_STRING_SIZE];


};

#endif
