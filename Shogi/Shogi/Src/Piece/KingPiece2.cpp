#include "KingPiece2.h"
#include <cstring>

KingPiece2::KingPiece2()
{
	m_p_range = range;
	m_obj_type = ObjectType::King2;
	m_draw_string = "‹Ê";
	m_owner = PlayerType::Player2;
}


KingPiece2::~KingPiece2()
{
}

int KingPiece2::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};