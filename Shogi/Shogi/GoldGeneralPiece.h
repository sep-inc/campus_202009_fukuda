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

	/**
	* @brief �w�肳�ꂽ�͈͂ɋ�����邩�𔻕ʂ���֐�
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos)override;

private:
	//! ��̓�����͈� 1 = �ړ��\
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{0,1,0}
	};

};

#endif