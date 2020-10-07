#ifndef KING_PIECE_H_
#define KING_PIECE_H_

/**
* @file KingPiece.h
* @brief KingPieceクラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class KingPiece
* @brief 玉クラス
*/
class KingPiece : public PieceBase
{
public:
	KingPiece();
	~KingPiece();

private:
	//! 移動可能範囲
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif