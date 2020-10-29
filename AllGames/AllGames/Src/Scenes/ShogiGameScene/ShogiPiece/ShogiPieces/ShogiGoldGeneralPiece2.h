#ifndef SHOGI_GOLDGENERAL_PIECE2_H_
#define SHOGI_GOLDGENERAL_PIECE2_H_

#include "../ShogiPieceBase.h"

class ShogiGoldGeneralPiece2 :public ShogiPieceBase {
public:
	ShogiGoldGeneralPiece2();
	~ShogiGoldGeneralPiece2();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif