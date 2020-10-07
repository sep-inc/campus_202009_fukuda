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
	// ˆÚ“®—ÊŒvZ
	int move_x = move_pos.m_x - now_pos.m_x;
	int move_y = move_pos.m_y - now_pos.m_y;

	// ˆÚ“®—Ê‚ğ‰ÁZ‚µ‚½êŠ‚ª“®‚¯‚éˆÊ’u‚È‚çtrue‚ğ•Ô‚·
	if (m_p_range[m_range_center_pos.m_y + move_y][m_range_center_pos.m_x + move_x] == 1) {
		return true;
	}
	return false;
}

Vec2 PieceBase::m_range_center_pos = { MOVE_RANGE_HEIGHT / 2,MOVE_RANGE_WIDTH / 2 };
