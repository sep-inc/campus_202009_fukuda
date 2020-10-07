#ifndef KING_PIECE_H_
#define KING_PIECE_H_

/**
* @file KingPiece.h
* @brief KingPiece�N���X�̃w�b�_
*/

#include "PieceBase.h"

/**
* @class KingPiece
* @brief �ʃN���X
*/
class KingPiece : public PieceBase
{
public:
	KingPiece();
	~KingPiece();

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif