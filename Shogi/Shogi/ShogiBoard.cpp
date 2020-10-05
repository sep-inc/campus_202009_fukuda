#include "ShogiBoard.h"
#include <cstring>

ShogiBoard::ShogiBoard():
	m_shogi_board{ObjectType::Type_Empty}
{
}

ShogiBoard::~ShogiBoard()
{
}

void ShogiBoard::InitBoard()
{
	// 初期配置作成
	ObjectType init_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {
		{ObjectType::Type_Empty,	ObjectType::Pawn2,			ObjectType::Type_Empty,		ObjectType::Pawn1,		ObjectType::Knight1},
		{ObjectType::King2,			ObjectType::Pawn2,			ObjectType::Type_Empty,		ObjectType::Pawn1,		ObjectType::GoldGeneral1},
		{ObjectType::GoldGeneral2,	ObjectType::Pawn2,			ObjectType::Type_Empty,		ObjectType::Pawn1,		ObjectType::King1},
		{ObjectType::Knight2,		ObjectType::Pawn2,			ObjectType::Type_Empty,		ObjectType::Pawn1,		ObjectType::Type_Empty}
	};
	// 初期配置を将棋盤にコピー
	memcpy(m_shogi_board, init_board, sizeof(init_board));
}

ObjectType ShogiBoard::GetContens(Vec2 pos)
{
	return m_shogi_board[pos.m_x][pos.m_y];
}

void ShogiBoard::SetPiece(Vec2 now_pos, Vec2 move_pos)
{
	m_shogi_board[move_pos.m_x][move_pos.m_y] = m_shogi_board[now_pos.m_x][now_pos.m_y];
	m_shogi_board[now_pos.m_x][now_pos.m_y] = ObjectType::Type_Empty;
}

bool ShogiBoard::KingExists(int turn_num)
{
	// 奇数ターンの判定
	if (turn_num % 2 == 1) {
		for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
			for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
				if (m_shogi_board[x][y] == ObjectType::King2) {
					return true;
				}
			}
		}
	}
	// 偶数ターンの判定
	else {
		for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
			for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
				if (m_shogi_board[x][y] == ObjectType::King1) {
					return true;
				}
			}
		}
	}
	return false;
}

void ShogiBoard::ReverseBoard()
{
	ObjectType tmp[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {};
	int tmp_x = 0;
	int tmp_y = 0;
	// 反転処理
	for (int x = SHOGI_BOARD_WIDTH - 1; x >= 0; x--) {
		for (int y = SHOGI_BOARD_HEIGHT - 1; y >= 0; y--) {
			tmp[x][y] = m_shogi_board[x][y];
			tmp_y++;
		}
		tmp_x++;
	}
	// 反転させた配列のコピー
	memcpy(m_shogi_board, tmp, sizeof(tmp));
}
