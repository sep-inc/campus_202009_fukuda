#include "GoldGeneralPiece.h"
#include <cstring>

GoldGeneralPiece::GoldGeneralPiece()
{
	m_p_range = range;
	m_obj_type = ObjectType::GoldGeneral1;
	m_draw_string = "‹à";
	m_owner = PlayerType::Player1;
}


GoldGeneralPiece::~GoldGeneralPiece()
{
}

int GoldGeneralPiece::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{0,1,0},
		{0,0,0}
};