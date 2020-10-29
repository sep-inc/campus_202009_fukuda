#ifndef SHOGI_GOLDGENERAL_PIECE1_H_
#define SHOGI_GOLDGENERAL_PIECE1_H_

#include "../ShogiPieceBase.h"

class ShogiGoldGeneralPiece1 :public ShogiPieceBase {
public:
	ShogiGoldGeneralPiece1();
	~ShogiGoldGeneralPiece1();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif