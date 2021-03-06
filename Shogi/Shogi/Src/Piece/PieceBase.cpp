#include "PieceBase.h"

PieceBase::PieceBase():
	m_p_range(nullptr),
	m_obj_type(ObjectType::Type_Empty),
	m_owner(PlayerType::Type_None)
{
}

PieceBase::~PieceBase()
{
}

bool PieceBase::CanMove(Vec2 now_pos, Vec2 move_pos)
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

Vec2 PieceBase::m_range_center_pos = { MOVE_RANGE_HEIGHT / 2,MOVE_RANGE_WIDTH / 2 };
