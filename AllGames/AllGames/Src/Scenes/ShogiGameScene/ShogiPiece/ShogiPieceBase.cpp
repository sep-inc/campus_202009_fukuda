#include "ShogiPieceBase.h"

ShogiPieceBase::ShogiPieceBase() :
	m_p_range(nullptr),
	m_obj_type(ShogiGameObjectType::TYPE_EMPTY),
	m_owner(ShogiPlayerType::TYPE_NONE)
{
}

ShogiPieceBase::~ShogiPieceBase()
{
}

bool ShogiPieceBase::CanMove(Vec2_Int now_pos, Vec2_Int move_pos)
{
	// 移動量計算
	int move_x = move_pos.m_x - now_pos.m_x;
	int move_y = move_pos.m_y - now_pos.m_y;

	// 移動量を加算した場所が動ける位置ならtrueを返す
	if (m_p_range[m_range_center_pos.m_y + move_y][m_range_center_pos.m_x + move_x] == 1) {
		return true;
	}
	return false;
}

Vec2_Int ShogiPieceBase::m_range_center_pos = { SHOGIGAME_MOVE_RANGE_HEIGHT / 2,SHOGIGAME_MOVE_RANGE_WIDTH / 2 };
