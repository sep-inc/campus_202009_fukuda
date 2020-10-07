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

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif

