#include "GoldGeneralPiece2.h"
#include <cstring>

GoldGeneralPiece2::GoldGeneralPiece2()
{
	m_p_range = range;
	m_obj_type = ObjectType::GoldGeneral2;
	m_draw_string = "‹Ø";
	m_owner = PlayerType::Player2;
}

GoldGeneralPiece2::~GoldGeneralPiece2()
{
}

int GoldGeneralPiece2::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,1,0},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};