#include "TronDrawer.h"
#include <cstring>

TronDrawer::TronDrawer():
	m_blank_buffer{""},
	m_draw_buffer{""}
{
}

TronDrawer::~TronDrawer()
{
}

void TronDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void TronDrawer::SetBlankBuffer(Vec2 pos_, char* string_)
{
	strcpy_s(m_blank_buffer[pos_.m_y][pos_.m_x], DRAW_STRING_SIZE, string_);
}

void TronDrawer::SetDrawBuffer(Vec2 pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], DRAW_STRING_SIZE, string_);
}

void TronDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < TRON_DRAW_BUFFER_HEIGHT; y++) {
		for (int x = 0; x < TRON_DRAW_BUFFER_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}
