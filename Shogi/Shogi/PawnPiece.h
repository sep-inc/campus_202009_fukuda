#ifndef PAWN_PIECE_H_
#define PAWN_PIECE_H_

/**
* @file PawnPiece.h
* @brief PawnPiece�N���X�̃w�b�_
*/

#include "PieceBase.h"

/**
* @class PawnPiece
* @brief ���N���X
*/
class PawnPiece : public PieceBase {
public:
	PawnPiece();
	~PawnPiece();

	/**
	* @brief �w�肳�ꂽ�͈͂ɋ�����邩�𔻕ʂ���֐�
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! ��̓�����͈� 1 = �ړ��\
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,1,0},
		{0,0,0},
		{0,0,0}
	};

};

#endif

