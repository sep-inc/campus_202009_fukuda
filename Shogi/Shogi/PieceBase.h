#ifndef PIECEBASE_H_
#define PIECEBASE_H_

/**
* @file PieceBase.h
* @brief PieceBaseクラスのヘッダ
*/

#include "Definition.h"

/**
* @class PieceBase
* @brief Pieceクラスの基底クラス
*/
class PieceBase {
public:
	PieceBase();
	virtual ~PieceBase();

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	virtual bool CanMove(Vec2 now_pos, Vec2 move_pos) = 0;

protected:
	Vec2 m_range_center_pos;
};

#endif

