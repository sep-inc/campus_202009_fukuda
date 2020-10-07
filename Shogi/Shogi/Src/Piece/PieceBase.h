#ifndef PIECEBASE_H_
#define PIECEBASE_H_

/**
* @file PieceBase.h
* @brief PieceBase�N���X�̃w�b�_
*/

#include "../Definition.h"
#include <string>

/**
* @class PieceBase
* @brief Piece�N���X�̊��N���X
*/
class PieceBase {
public:
	PieceBase();
	virtual ~PieceBase();

	/**
	* @brief �w�肳�ꂽ�͈͂ɋ�����邩�𔻕ʂ���֐�
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos);

	/**
	* @brief �I�u�W�F�N�g�̎�ނ�Ԃ��֐�
	* @return ���g�̎��
	*/
	inline ObjectType GetObjectType()const { return m_obj_type; }

	/**
	* @brief ���g�̕ێ��҂�Ԃ��֐�
	*/
	inline PlayerType GetMyOwner()const { return m_owner; }

	/**
	* @brief �`�敶���擾�֐�
	*/
	std::string GetDrawString() { return m_draw_string.c_str(); }

protected:
	int(*m_p_range)[MOVE_RANGE_HEIGHT];	//! �ړ��\�͈͂�2���z��̃|�C���^
	ObjectType m_obj_type;				//! ���g�̎��
	PlayerType m_owner;					//! ���g�ۗ̕L��
	std::string m_draw_string;			//! ���g�̕`����

private:
	static Vec2 m_range_center_pos;			//! �ړ��\�͈͂̔z��ɂ����钆�S�ʒu
};

#endif

