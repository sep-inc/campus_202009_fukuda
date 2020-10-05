#include "KnightPiece.h"
#include <cstring>

KnightPiece::KnightPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 2;
	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,0,1},
		{0,0,0},
		{0,0,0}
	};
	memcpy(m_move_range, range, sizeof(range));
}


KnightPiece::~KnightPiece()
{
}
