#include "GoldGeneralPiece.h"
#include <cstring>

GoldGeneralPiece::GoldGeneralPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;
	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,1,1},
		{1,0,1},
		{0,1,0}
	};
	memcpy(m_move_range, range, sizeof(range));

	m_obj_type = ObjectType::GoldGeneral1;
	m_draw_string = "‹à";
	m_owner = PlayerType::Player1;
}


GoldGeneralPiece::~GoldGeneralPiece()
{
}
