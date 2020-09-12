#include "Block.h"
#include "Drawer.h"
#include "Global.h"


Block::Block()
{
}

Block::~Block()
{
}

void Block::Init(float pos_x, float pos_y, bool enable, Kind kind)
{
	ObjectBase::Init(pos_x, pos_y, enable, kind);
	m_size.width = BLOCK_WIDTH;
	m_size.height = BLOCK_HEIGHT;
}

void Block::SetUpDrawBuffer()
{
	if (m_enable == true) {
		g_drawer.SetBlankBuffer(m_pos.x, m_pos.y, m_kind, m_size.width, m_size.height);
	}
}

Vec2 Block::GetBlockPos()
{
	return m_pos;
}

void Block::IsDelete()
{
	m_enable = false;
}
