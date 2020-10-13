#ifndef GAME_MAP_H_
#define GAME_MAP_H_

/**
* @file GameMap.h
* @brief GameMap�N���X�̃w�b�_
*/

#include "../Definition.h"
#include "../Draw/DrawerBase.h"

/**
* @class GameMap
* @brief �Q�[���̃}�b�v�����Ǘ�����N���X
*/
class GameMap
{
public:
	GameMap();
	~GameMap();

	/**
	* @brief �`�揈���֐�
	* @param drawer_ �`��N���X�̃|�C���^
	*/
	void Draw(DrawerBase* drawer_);

	void InitDraw(DrawerBase* drawer_);

	//! ������ꏊ��Ԃ��֐�
	void GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE]);

	//! ��������ŁA�܂������邩�̔���֐�
	bool SetMovePos(Vec2 move_pos_, CharacterParam chara_);

	/**
	* @brief �Q�[���}�b�v��������Ԃɂ���֐�
	* �Q�[���̏��������̂ݎg�p����
	*/
	void ClearGameMap();

	//! �������p�}�b�v�̍쐬�֐�
	void CreateInitGameMap();


private:
	//! �������p�̃Q�[���}�b�v
	CharacterParam m_init_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];

	//! �Q�[���}�b�v
	CharacterParam m_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];
};

#endif

