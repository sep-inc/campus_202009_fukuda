#ifndef GOLD_GENERAL_PIECE2_H_
#define GOLD_GENERAL_PIECE2_H_

#include "PieceBase.h"

class GoldGeneralPiece2 :public PieceBase{
public:
	GoldGeneralPiece2();
	~GoldGeneralPiece2();

private:
	//! ˆÚ“®‰Â”\”ÍˆÍ
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif