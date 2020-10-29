#include "ShogiBoard.h"

ShogiBoard::ShogiBoard() :
	m_shogi_board{ nullptr }
{
}

ShogiBoard::~ShogiBoard()
{
}

ShogiPieceBase* ShogiBoard::GetContens(Vec2_Int pos)
{
	return m_shogi_board[pos.m_x][pos.m_y];
}

void ShogiBoard::SetPiece(int x, int y, ShogiPieceBase* piece)
{
	m_shogi_board[x][y] = piece;
}

void ShogiBoard::SetMovePiece(Vec2_Int now_pos, Vec2_Int move_pos)
{
	m_shogi_board[move_pos.m_x][move_pos.m_y] = m_shogi_board[now_pos.m_x][now_pos.m_y];
	m_shogi_board[now_pos.m_x][now_pos.m_y] = nullptr;
}