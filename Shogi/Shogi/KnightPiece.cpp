#include "KnightPiece.h"

KnightPiece::KnightPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 2;
}


KnightPiece::~KnightPiece()
{
}

bool KnightPiece::CanMove(Vec2 now_pos, Vec2 move_pos)
{
	// ˆÚ“®—ÊŒvZ
	int move_x = move_pos.m_x - now_pos.m_x;
	int move_y = move_pos.m_y - now_pos.m_y;

	// ˆÚ“®—Ê‚ğ‰ÁZ‚µ‚½êŠ‚ª“®‚¯‚éˆÊ’u‚È‚çtrue‚ğ•Ô‚·
	if (m_move_range[m_range_center_pos.m_x + move_x][m_range_center_pos.m_y + move_y] == 1) {
		return true;
	}
	return false;
}
