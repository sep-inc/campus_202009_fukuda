#include "ShogiBoard.h"
#include "ShogiGame.h"
#include <cstring>

ShogiBoard::ShogiBoard():
	m_shogi_board{nullptr}
{
}

ShogiBoard::~ShogiBoard()
{
}

void ShogiBoard::InitBoard()
{
	ShogiGame* tmp = ShogiGame::Instance();
	PieceBase* init_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {
		{nullptr,							tmp->m_p_pieces->m_p_pawn2,		nullptr,	tmp->m_p_pieces->m_p_pawn1,		tmp->m_p_pieces->m_p_knight1},
		{tmp->m_p_pieces->m_p_king2,		tmp->m_p_pieces->m_p_pawn2,		nullptr,	tmp->m_p_pieces->m_p_pawn1,		tmp->m_p_pieces->m_p_gold_general1},
		{tmp->m_p_pieces->m_p_gold_general2,tmp->m_p_pieces->m_p_pawn2,		nullptr,	tmp->m_p_pieces->m_p_pawn1,		tmp->m_p_pieces->m_p_king1},
		{tmp->m_p_pieces->m_p_knight2,		tmp->m_p_pieces->m_p_pawn2,		nullptr,	tmp->m_p_pieces->m_p_pawn1,		nullptr}
	};

	// 初期配置を将棋盤にコピー
	memcpy(m_shogi_board, init_board, sizeof(init_board));
}

PieceBase* ShogiBoard::GetContens(Vec2 pos)
{
	return m_shogi_board[pos.m_x][pos.m_y];
}

void ShogiBoard::SetPiece(Vec2 now_pos, Vec2 move_pos)
{
	m_shogi_board[move_pos.m_x][move_pos.m_y] = m_shogi_board[now_pos.m_x][now_pos.m_y];
	m_shogi_board[now_pos.m_x][now_pos.m_y] = nullptr;
}

bool ShogiBoard::KingExists(int turn_num)
{
	// 奇数ターンの判定
	if (turn_num % 2 == 1) {
		for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
			for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
				if (m_shogi_board[x][y] == ShogiGame::Instance()->m_p_pieces->m_p_king2) {
					return true;
				}
			}
		}
	}
	// 偶数ターンの判定
	else {
		for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
			for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
				if (m_shogi_board[x][y] == ShogiGame::Instance()->m_p_pieces->m_p_king1) {
					return true;
				}
			}
		}
	}
	return false;
}
