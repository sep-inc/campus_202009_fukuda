#ifndef SHOGI_KING_PIECE2_H_
#define SHOGI_KING_PIECE2_H_

#include "../ShogiPieceBase.h"

class ShogiKingPiece2 :public ShogiPieceBase {
public:
	ShogiKingPiece2();
	~ShogiKingPiece2();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif