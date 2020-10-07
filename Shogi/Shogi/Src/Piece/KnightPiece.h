#ifndef KNIGHT_PIECE_H_
#define KNIGHT_PIECE_H_

/**
* @file KnightPiece.h
* @brief KnightPiece�N���X�̃w�b�_
*/

#include "PieceBase.h"

/**
* @class KnightPiece
* @brief �j�n�N���X
*/
class KnightPiece :public PieceBase
{
public:
	KnightPiece();
	~KnightPiece();

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif