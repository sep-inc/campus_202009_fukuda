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

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! 駒の動ける範囲 1 = 移動可能
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,0,1},
		{0,0,0},
		{0,0,0}
	};

};

#endif