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
	virtual bool CanMove(Vec2 now_pos, Vec2 move_pos) = 0;

protected:
	Vec2 m_range_center_pos;
};

#endif

