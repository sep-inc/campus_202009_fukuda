#ifndef PIECEBASE_H_
#define PIECEBASE_H_

/**
* @file PieceBase.h
* @brief PieceBase�N���X�̃w�b�_
*/

#include "Definition.h"

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

protected:
	Vec2 m_range_center_pos;
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
	ObjectType m_obj_type;
};

#endif

