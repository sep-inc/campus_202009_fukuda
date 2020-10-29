#ifndef SHOGI_KNIGHT_PIECE2_H_
#define SHOGI_KNIGHT_PIECE2_H_

#include "../ShogiPieceBase.h"

class ShogiKnightPiece2 :public ShogiPieceBase {
public:
	ShogiKnightPiece2();
	~ShogiKnightPiece2();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif