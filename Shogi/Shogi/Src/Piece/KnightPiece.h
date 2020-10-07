#ifndef KNIGHT_PIECE_H_
#define KNIGHT_PIECE_H_

/**
* @file KnightPiece.h
* @brief KnightPieceクラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class KnightPiece
* @brief 桂馬クラス
*/
class KnightPiece :public PieceBase
{
public:
	KnightPiece();
	~KnightPiece();

private:
	//! 移動可能範囲
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif