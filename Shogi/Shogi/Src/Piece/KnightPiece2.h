#ifndef KNIGHT_PIECE2_H_
#define KNIGHT_PIECE2_H_

#include "PieceBase.h"

class KnightPiece2 :public PieceBase{
public:
	KnightPiece2();
	~KnightPiece2();

private:
	//! ˆÚ“®‰Â”\”ÍˆÍ
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif