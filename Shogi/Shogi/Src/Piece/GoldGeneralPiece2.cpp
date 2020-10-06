#include "GoldGeneralPiece2.h"
#include <cstring>

GoldGeneralPiece2::GoldGeneralPiece2()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;

	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,1,0},
		{1,0,1},
		{1,1,1}
	};
	memcpy(m_move_range, range, sizeof(range));

	m_obj_type = ObjectType::GoldGeneral2;

	m_draw_string = "‹Ø";

	m_owner = PlayerType::Player2;
}

GoldGeneralPiece2::~GoldGeneralPiece2()
{
}
