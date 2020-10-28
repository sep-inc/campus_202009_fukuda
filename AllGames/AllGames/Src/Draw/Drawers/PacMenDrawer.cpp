#include "PacMenDrawer.h"
#include <cstring>

PacMenDrawer::PacMenDrawer() :
	m_blank_buffer{ "\0" },
	m_draw_buffer{ "" }
{
}

PacMenDrawer::~PacMenDrawer()
{
}

void PacMenDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void PacMenDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], PACMEN_DRAW_STRING_SIZE, string_);
}

void PacMenDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < PACMEN_DRAW_HEIGHT; y++) {
		for (int x = 0; x < PACMEN_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}