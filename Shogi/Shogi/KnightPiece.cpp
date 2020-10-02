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
	// �ړ��ʌv�Z
	int move_x = move_pos.m_x - now_pos.m_x;
	int move_y = move_pos.m_y - now_pos.m_y;

	// �ړ��ʂ����Z�����ꏊ��������ʒu�Ȃ�true��Ԃ�
	if (m_move_range[m_range_center_pos.m_x + move_x][m_range_center_pos.m_y + move_y] == 1) {
		return true;
	}
	return false;
}
