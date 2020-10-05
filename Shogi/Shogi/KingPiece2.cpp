#include "KingPiece2.h"
#include <cstring>

KingPiece2::KingPiece2()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;

	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{1,1,1}
	};
	memcpy(m_move_range, range, sizeof(range));
}


KingPiece2::~KingPiece2()
{
}
