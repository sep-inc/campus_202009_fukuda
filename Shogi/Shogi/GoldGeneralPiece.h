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

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! 駒の動ける範囲 1 = 移動可能
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{0,1,0}
	};

};

#endif