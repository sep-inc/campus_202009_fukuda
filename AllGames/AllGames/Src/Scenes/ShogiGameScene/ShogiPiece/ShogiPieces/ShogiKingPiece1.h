#ifndef SHOGI_KING_PIECE1_H_
#define SHOGI_KING_PIECE1_H_

#include "../ShogiPieceBase.h"

class ShogiKingPiece1 :public ShogiPieceBase {
public:
	ShogiKingPiece1();
	~ShogiKingPiece1();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif