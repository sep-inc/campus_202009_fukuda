#ifndef GOLD_GENERAL_PIECE_H_
#define GOLD_GENERAL_PIECE_H_

/**
* @file GoldGeneralPiece.h
* @brief GoldGeneralPieceクラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class GoldGeneralPiece
* @brief 金クラス
*/
class GoldGeneralPiece :public PieceBase
{
public:
	GoldGeneralPiece();
	~GoldGeneralPiece();

private:
	//! 移動可能範囲
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif