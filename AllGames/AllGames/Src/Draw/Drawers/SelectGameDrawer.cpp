#include "SelectGameDrawer.h"

SelectGameDrawer::SelectGameDrawer() :
	m_blank_buffer{ "\0" },
	m_draw_buffer{ "\0" }
{

}

SelectGameDrawer::~SelectGameDrawer()
{

}

void SelectGameDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void SelectGameDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], SELECT_GAME_DRAW_STRING_SIZE, string_);
}

DrawerBase* SelectGameDrawer::InstanceSelectGameDrawer()
{
	return static_cast<DrawerBase*>(new SelectGameDrawer);
}

void SelectGameDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < SELECT_GAME_DRAW_HEIGHT; y++) {
		for (int x = 0; x < SELECT_GAME_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}