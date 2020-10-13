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
	* @brief �����������֐�
	*/
	void Init();

	/**
	* @brief �`�揈���֐�
	* @param drawer_ �`��N���X�̃|�C���^
	*/
	void Draw(DrawerBase* drawer_);

	/**
	* @brief �ړ��\�͈͂�Ԃ��֐�
	* �w�肳�ꂽ�ʒu����ړ��\�ȏꏊ�����X�g�����A��������z��̒��Ɋi�[����
	*
	* @param now_pos_ ���ݒn
	* @param move_list_ �ړ��\�͈̓��X�g�̔z��
	*/
	void GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE]);

	/**
	* @brief �ړ��ꏊ���Z�b�g�A���̏ꏊ���瑼�̈ʒu�Ɉړ����\���𔻒肷��֐�
	* @param move_pos_ �ړ���̍��W
	* @param chara_ �Z�b�g����L�����N�^�[�̏��
	* @return bool �ړ��\�ȏꏊ���Ȃ����true��Ԃ�
	*/
	bool SetMovePos(Vec2 move_pos_, CharacterParam chara_);


private:
	//! �������p�}�b�v�̍쐬�֐�
	void CreateInitGameMap();

	/**
	* @brief �Q�[���}�b�v��������Ԃɂ���֐�
	* �Q�[���̏��������̂ݎg�p����
	*/
	void ClearGameMap();


private:
	//! �������p�̃Q�[���}�b�v
	CharacterParam m_init_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];

	//! �Q�[���}�b�v
	CharacterParam m_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];
};

#endif

