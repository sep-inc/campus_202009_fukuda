#include "PawnPiece.h"
#include <cstring>

PawnPiece::PawnPiece()
{
	m_range_center_pos.m_x = 1;
	m_range_center_pos.m_y = 1;

	int range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,1,0},
		{0,0,0},
		{0,0,0}
	};
	memcpy(m_move_range, range, sizeof(range));

	m_obj_type = ObjectType::Pawn1;
}

PawnPiece::~PawnPiece()
{
}
