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

	m_obj_type = ObjectType::Knight1;
	m_draw_string = "Œj";
	m_owner = PlayerType::Player1;
}


KnightPiece::~KnightPiece()
{
}
