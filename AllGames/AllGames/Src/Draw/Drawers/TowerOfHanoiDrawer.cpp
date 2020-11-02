#include "TowerOfHanoiDrawer.h"
#include <cstring>

TowerOfHanoiDrawer::TowerOfHanoiDrawer():
	m_blank_buffer{"\0"},
	m_draw_buffer{""}
{
}

TowerOfHanoiDrawer::~TowerOfHanoiDrawer()
{
}

void TowerOfHanoiDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], TOWER_OF_HANOI_DRAW_STRING_SIZE, string_);
}

void TowerOfHanoiDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void TowerOfHanoiDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < TOWER_OF_HANOI_DRAW_HEIGHT; y++) {
		for (int x = 0; x < TOWER_OF_HANOI_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}
