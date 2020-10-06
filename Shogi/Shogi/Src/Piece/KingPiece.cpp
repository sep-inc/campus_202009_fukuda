#include "KingPiece.h"
#include <cstring>


KingPiece::KingPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;
	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{1,1,1}
	};
	memcpy(m_move_range, range, sizeof(range));

	m_obj_type = ObjectType::King1;

	m_draw_string = "‰¤";

	m_owner = PlayerType::Player1;
}


KingPiece::~KingPiece()
{
}
