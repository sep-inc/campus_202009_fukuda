#include "TetrisDrawer.h"

TetrisDrawer::TetrisDrawer():
	m_blank_buffer{"\0"},
	m_draw_buffer{""}
{
}

TetrisDrawer::~TetrisDrawer()
{
}


void TetrisDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}


void TetrisDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], TETRIS_DRAW_STRING_SIZE, string_);
}

void TetrisDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < TETRIS_DRAW_HEIGHT; y++) {
		for (int x = 0; x < TETRIS_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}