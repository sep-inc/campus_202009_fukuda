#include "KnightPiece2.h"
#include <cstring>

KnightPiece2::KnightPiece2()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 0;

	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,0,0},
		{1,0,1}
	};
	memcpy(m_move_range, range, sizeof(range));

	m_obj_type = ObjectType::Knight2;

	m_draw_string = "Œy";

	m_owner = PlayerType::Player2;
}


KnightPiece2::~KnightPiece2()
{
}
