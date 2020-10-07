#ifndef SHOGI_BOARD_H_
#define SHOGI_BOARD_H_

/**
* @file ShogiBoard.h
* @brief ShogiBoard�N���X�̃w�b�_
*/

#include "../Definition.h"
#include "../Piece/PieceBase.h"

/**
* @class ShogiBoard
* @brief �����ՃN���X
*/
class ShogiBoard {
public:
	ShogiBoard();
	~ShogiBoard();

	/**
	* @brief �}�X�̒��g�𒲂ׂ�֐�
	* @param pos ���ׂ����}�X�ڂ̍��W
	* @return �}�X�̒��g
	*/
	PieceBase* GetContens(Vec2 pos);

	/**
	* @brief ����Z�b�g����֐�
	* @param x �Z�b�g����X���W
	* @param y �Z�b�g����Y���W
	* @param piece �Z�b�g����N���X�̃|�C���^
	*/
	void SetPiece(int x, int y, PieceBase* piece);

	/**
	* @brief �ړ��������Z�b�g����֐�
	* @param now_pos �ړ��������̌��݂̍��W
	* @param pos �Z�b�g����}�X�ڂ̍��W
	*/
	void SetMovePiece(Vec2 now_pos, Vec2 move_pos);


private:
	//! �����Քz��
	PieceBase* m_shogi_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT];

};

#endif

