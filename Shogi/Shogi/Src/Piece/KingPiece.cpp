#include "KingPiece.h"
#include <cstring>


KingPiece::KingPiece()
{
	m_p_range = range;
	m_obj_type = ObjectType::King1;
	m_draw_string = "‰¤";
	m_owner = PlayerType::Player1;
}


KingPiece::~KingPiece()
{
}

int KingPiece::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};