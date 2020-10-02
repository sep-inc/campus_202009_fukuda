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

	/**
	* @brief �w�肳�ꂽ�͈͂ɋ�����邩�𔻕ʂ���֐�
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! ��̓�����͈� 1 = �ړ��\
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,0,1},
		{0,0,0},
		{0,0,0}
	};

};

#endif