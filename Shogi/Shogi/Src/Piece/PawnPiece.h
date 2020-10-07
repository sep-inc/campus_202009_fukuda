#ifndef PAWN_PIECE_H_
#define PAWN_PIECE_H_

/**
* @file PawnPiece.h
* @brief PawnPieceクラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class PawnPiece
* @brief 歩クラス
*/
class PawnPiece : public PieceBase {
public:
	PawnPiece();
	~PawnPiece();

private:
	//! 移動可能範囲
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif

