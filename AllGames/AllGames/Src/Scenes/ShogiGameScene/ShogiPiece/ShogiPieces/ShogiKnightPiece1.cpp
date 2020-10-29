#include "ShogiKnightPiece1.h"

ShogiKnightPiece1::ShogiKnightPiece1()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::KNIGHT1;
	m_draw_string = "桂";
	m_owner = ShogiPlayerType::PLAYER1;
}


ShogiKnightPiece1::~ShogiKnightPiece1()
{
}

int ShogiKnightPiece1::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{1,0,1},
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{0,0,0}
};