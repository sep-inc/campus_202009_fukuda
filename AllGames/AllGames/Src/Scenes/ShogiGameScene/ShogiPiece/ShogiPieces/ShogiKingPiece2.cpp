#include "ShogiKingPiece2.h"

ShogiKingPiece2::ShogiKingPiece2()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::KING2;
	m_draw_string = "玉";
	m_owner = ShogiPlayerType::PLAYER2;
}


ShogiKingPiece2::~ShogiKingPiece2()
{
}

int ShogiKingPiece2::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};