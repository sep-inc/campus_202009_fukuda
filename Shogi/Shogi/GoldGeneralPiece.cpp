#include "GoldGeneralPiece.h"

GoldGeneralPiece::GoldGeneralPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;
}


GoldGeneralPiece::~GoldGeneralPiece()
{
}

bool GoldGeneralPiece::CanMove(Vec2 now_pos, Vec2 move_pos)
{
	// 移動量計算
	int move_x = move_pos.m_x - now_pos.m_x;
	int move_y = move_pos.m_y - now_pos.m_y;

	// 移動量を加算した場所が動ける位置ならtrueを返す
	if (m_move_range[m_range_center_pos.m_x + move_x][m_range_center_pos.m_y + move_y] == 1) {
		return true;
	}
	return false;
}
