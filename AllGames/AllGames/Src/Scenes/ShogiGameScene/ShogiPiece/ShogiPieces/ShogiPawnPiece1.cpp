#include "ShogiPawnPiece1.h"

ShogiPawnPiece1::ShogiPawnPiece1()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::PAWN1;
	m_draw_string = "歩";
	m_owner = ShogiPlayerType::PLAYER1;
}

ShogiPawnPiece1::~ShogiPawnPiece1()
{
}

int ShogiPawnPiece1::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
		{0,0,0},
		{0,0,0}
};