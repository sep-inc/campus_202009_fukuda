#ifndef SHOGI_KNIGHT_PIECE1_H_
#define SHOGI_KNIGHT_PIECE1_H_

#include "../ShogiPieceBase.h"

class ShogiKnightPiece1 :public ShogiPieceBase {
public:
	ShogiKnightPiece1();
	~ShogiKnightPiece1();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif