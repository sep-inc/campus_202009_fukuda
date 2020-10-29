#include "ShogiGoldGeneralPiece1.h"

ShogiGoldGeneralPiece1::ShogiGoldGeneralPiece1()
{
	m_p_range = range;
	m_obj_type = ShogiGameObjectType::GOLD_GENERAL1;
	m_draw_string = "金";
	m_owner = ShogiPlayerType::PLAYER1;
}

ShogiGoldGeneralPiece1::~ShogiGoldGeneralPiece1()
{
}

int ShogiGoldGeneralPiece1::range[SHOGIGAME_MOVE_RANGE_WIDTH][SHOGIGAME_MOVE_RANGE_HEIGHT] = {
		{0,0,0},
		{1,1,1},
		{1,0,1},
		{0,1,0},
		{0,0,0}
};