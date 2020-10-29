#include "ShogiKnightPiece2.h"

ShogiKnightPiece2::ShogiKnightPiece2()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::KNIGHT2;
	m_draw_string = "軽";
	m_owner = ShogiPlayerType::PLAYER2;
}


ShogiKnightPiece2::~ShogiKnightPiece2()
{
}

int ShogiKnightPiece2::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{1,0,1}
};