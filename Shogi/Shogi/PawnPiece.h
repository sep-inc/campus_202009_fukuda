#ifndef PAWN_PIECE_H_
#define PAWN_PIECE_H_

/**
* @file PawnPiece.h
* @brief PawnPieceクラスのヘッダ
*/

#include "PieceBase.h"

/**
* @class PawnPiece
* @brief 歩クラス
*/
class PawnPiece : public PieceBase {
public:
	PawnPiece();
	~PawnPiece();

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! 駒の動ける範囲 1 = 移動可能
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,1,0},
		{0,0,0},
		{0,0,0}
	};

};

#endif

