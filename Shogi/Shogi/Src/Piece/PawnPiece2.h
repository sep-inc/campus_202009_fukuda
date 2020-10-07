#ifndef PAWN_PIECE2_H_
#define PAWN_PIECE2_H_

/**
* @file PawnPiece.h
* @brief PawnPiece2クラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class PawnPiece2
* @brief Player2の歩クラス
*/
class PawnPiece2 : public PieceBase {
public:
	PawnPiece2();
	~PawnPiece2();

private:
	//! 移動可能範囲
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif

