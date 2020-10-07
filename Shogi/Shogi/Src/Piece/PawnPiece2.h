#ifndef PAWN_PIECE2_H_
#define PAWN_PIECE2_H_

/**
* @file PawnPiece.h
* @brief PawnPiece2�N���X�̃w�b�_
*/

#include "PieceBase.h"

/**
* @class PawnPiece2
* @brief Player2�̕��N���X
*/
class PawnPiece2 : public PieceBase {
public:
	PawnPiece2();
	~PawnPiece2();

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif

