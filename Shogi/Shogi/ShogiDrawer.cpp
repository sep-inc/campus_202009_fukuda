#include "ShogiDrawer.h"
#include <cstring>

ShogiDrawer::ShogiDrawer():
	m_blank_buffer{ObjectType::Type_None},
	m_draw_buffer{ObjectType::Type_None}
{
}

ShogiDrawer::~ShogiDrawer()
{
}

void ShogiDrawer::ClearBuffer()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void ShogiDrawer::SetDrawBuffer(int x, int y, ObjectType type)
{
	m_draw_buffer[x][y] = type;
}

void ShogiDrawer::SetBlankBuffer(int x, int y, ObjectType type)
{
	m_blank_buffer[x][y] = type;
}

void ShogiDrawer::SetResult()
{
}
