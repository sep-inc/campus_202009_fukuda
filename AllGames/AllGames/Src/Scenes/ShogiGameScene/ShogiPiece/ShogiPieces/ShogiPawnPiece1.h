#ifndef SHOGI_PAWN_PIECE1_H_
#define SHOGI_PAWN_PIECE1_H_

#include "../ShogiPieceBase.h"

/**
* @class PawnPiece
* @brief 歩クラス
*/
class ShogiPawnPiece1 : public ShogiPieceBase {
public:
	ShogiPawnPiece1();
	~ShogiPawnPiece1();

private:
	//! 移動可能範囲
	static int range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT];
};

#endif