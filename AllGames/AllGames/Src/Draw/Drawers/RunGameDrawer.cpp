#include "RunGameDrawer.h"
#include <cstring>

RunGameDrawer::RunGameDrawer() :
	m_blank_buffer{ "\0" },
	m_draw_buffer{ "\0" }
{

}

RunGameDrawer::~RunGameDrawer()
{

}

void RunGameDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void RunGameDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], RUNGAME_DRAW_STRING_SIZE, string_);
}

void RunGameDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < RUNGAME_DRAW_HEIGHT; y++) {
		for (int x = 0; x < RUNGAME_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}