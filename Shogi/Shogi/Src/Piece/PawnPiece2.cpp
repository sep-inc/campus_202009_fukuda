#include "PawnPiece2.h"
#include <cstring>


PawnPiece2::PawnPiece2()
{
	m_p_range = range;
	m_obj_type = ObjectType::Pawn2;
	m_draw_string = "‚Ó";
	m_owner = PlayerType::Player2;
}

PawnPiece2::~PawnPiece2()
{
}

int PawnPiece2::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,1,0},
		{0,0,0}
};