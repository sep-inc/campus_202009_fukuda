#include "ShogiBoard.h"
#include "../ShogiGame/ShogiGame.h"
#include <cstring>

ShogiBoard::ShogiBoard():
	m_shogi_board{nullptr}
{
}

ShogiBoard::~ShogiBoard()
{
}

PieceBase* ShogiBoard::GetContens(Vec2 pos)
{
	return m_shogi_board[pos.m_x][pos.m_y];
}

void ShogiBoard::SetPiece(int x, int y, PieceBase* piece)
{
	m_shogi_board[x][y] = piece;
}

void ShogiBoard::SetMovePiece(Vec2 now_pos, Vec2 move_pos)
{
	m_shogi_board[move_pos.m_x][move_pos.m_y] = m_shogi_board[now_pos.m_x][now_pos.m_y];
	m_shogi_board[now_pos.m_x][now_pos.m_y] = nullptr;
}

