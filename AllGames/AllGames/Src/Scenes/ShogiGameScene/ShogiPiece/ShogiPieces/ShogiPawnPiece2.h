#ifndef SHOGI_PAWN_PIECE2_H_
#define SHOGI_PAWN_PIECE2_H_

#include "../ShogiPieceBase.h"

/**
* @class PawnPiece
* @brief 歩クラス
*/
class ShogiPawnPiece2 : public ShogiPieceBase {
public:
	ShogiPawnPiece2();
	~ShogiPawnPiece2();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif
