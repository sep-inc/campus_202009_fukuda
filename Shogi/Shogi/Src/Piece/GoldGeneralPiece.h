#ifndef GOLD_GENERAL_PIECE_H_
#define GOLD_GENERAL_PIECE_H_

/**
* @file GoldGeneralPiece.h
* @brief GoldGeneralPiece�N���X�̃w�b�_
*/

#include "PieceBase.h"

/**
* @class GoldGeneralPiece
* @brief ���N���X
*/
class GoldGeneralPiece :public PieceBase
{
public:
	GoldGeneralPiece();
	~GoldGeneralPiece();

private:
	//! �ړ��\�͈�
	static int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
};

#endif