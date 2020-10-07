#include "PawnPiece.h"
#include <cstring>

PawnPiece::PawnPiece()
{
	m_p_range = range;
	m_obj_type = ObjectType::Pawn1;
	m_draw_string = "•à";
	m_owner = PlayerType::Player1;
}

PawnPiece::~PawnPiece()
{
}

int PawnPiece::range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
		{0,0,0},
		{0,0,0}
};