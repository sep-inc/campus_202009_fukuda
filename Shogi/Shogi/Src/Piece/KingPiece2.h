#ifndef KING_PIECE2_H_
#define KING_PIECE2_H_

#include "PieceBase.h"

class KingPiece2 :public PieceBase{
public:
	KingPiece2();
	~KingPiece2();

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif