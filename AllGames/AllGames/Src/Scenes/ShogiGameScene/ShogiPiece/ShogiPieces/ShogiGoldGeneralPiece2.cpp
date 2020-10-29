#include "ShogiGoldGeneralPiece2.h"

ShogiGoldGeneralPiece2::ShogiGoldGeneralPiece2()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::GOLD_GENERAL2;
	m_draw_string = "筋";
	m_owner = ShogiPlayerType::PLAYER2;
}

ShogiGoldGeneralPiece2::~ShogiGoldGeneralPiece2()
{
}

int ShogiGoldGeneralPiece2::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{0,1,0},
		{1,0,1},
		{1,1,1},
		{0,0,0}
};