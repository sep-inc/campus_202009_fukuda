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
};

#endif