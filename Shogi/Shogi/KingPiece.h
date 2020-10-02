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

	/**
	* @brief �w�肳�ꂽ�͈͂ɋ�����邩�𔻕ʂ���֐�
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! ��̓�����͈� 1 = �ړ��\
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{1,1,1}
	};
};

#endif