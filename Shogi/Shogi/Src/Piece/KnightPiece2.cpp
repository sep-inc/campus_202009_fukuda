#include "KnightPiece2.h"
#include <cstring>

KnightPiece2::KnightPiece2()
{
	m_p_range = range;
	m_obj_type = ObjectType::Knight2;
	m_draw_string = "Œy";
	m_owner = PlayerType::Player2;
}


KnightPiece2::~KnightPiece2()
{
}

int KnightPiece2::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{1,0,1}
};