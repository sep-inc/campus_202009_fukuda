#include "KnightPiece.h"
#include <cstring>

KnightPiece::KnightPiece()
{
	m_p_range = range;
	m_obj_type = ObjectType::Knight1;
	m_draw_string = "Œj";
	m_owner = PlayerType::Player1;
}


KnightPiece::~KnightPiece()
{
}

int KnightPiece::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{1,0,1},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0}
};