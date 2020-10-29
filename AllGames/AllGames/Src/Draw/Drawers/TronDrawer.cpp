#include "TronDrawer.h"

TronDrawer::TronDrawer() :
	m_blank_buffer{ "\0" },
	m_draw_buffer{ "" }
{
}

TronDrawer::~TronDrawer()
{
}

void TronDrawer::BufferClear()
{
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}


void TronDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	strcpy_s(m_draw_buffer[pos_.m_y][pos_.m_x], TRON_DRAW_STRING_SIZE, string_);
}

DrawerBase* TronDrawer::InstanceTronGameDrawer()
{
	return static_cast<DrawerBase*>(new TronDrawer);
}

void TronDrawer::LinkDrawBuffer()
{
	for (int y = 0; y < TRON_DRAW_HEIGHT; y++) {
		for (int x = 0; x < TRON_DRAW_WIDTH; x++) {
			m_draw_string += m_draw_buffer[y][x];
		}
		m_draw_string += "\n";
	}
}