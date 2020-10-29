#include "ShogiPawnPiece2.h"

ShogiPawnPiece2::ShogiPawnPiece2()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::PAWN2;
	m_draw_string = "ふ";
	m_owner = ShogiPlayerType::PLAYER2;
}

ShogiPawnPiece2::~ShogiPawnPiece2()
{
}

int ShogiPawnPiece2::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,1,0},
		{0,0,0}
};