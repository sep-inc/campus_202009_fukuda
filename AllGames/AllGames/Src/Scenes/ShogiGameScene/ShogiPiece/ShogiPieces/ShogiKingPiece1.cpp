#include "ShogiKingPiece1.h"

ShogiKingPiece1::ShogiKingPiece1()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::KING1;
	m_draw_string = "王";
	m_owner = ShogiPlayerType::PLAYER1;
}


ShogiKingPiece1::~ShogiKingPiece1()
{
}

int ShogiKingPiece1::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};