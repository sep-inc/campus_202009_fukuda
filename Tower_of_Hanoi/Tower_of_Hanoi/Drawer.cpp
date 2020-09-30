#include "Drawer.h"
#include <iostream>
#include <cstring>


Drawer::Drawer():
	m_blank_buffer{DrawType::Type_Empty},
	m_draw_buffer{DrawType::Type_Empty}
{
	Init();
}


Drawer::~Drawer()
{
}

void Drawer::Init()
{
	// 初期化処理
	BufferClear();
}

void Drawer::Run()
{
	// 描画バッファの連結
	LinkDrawBuffer();
	// 描画
	Print();
	// 描画バッファのクリア
	BufferClear();
}

void Drawer::Print()
{
	// 文字列の描画処理
	std::cout << m_draw_string.c_str() << std::flush;
}

void Drawer::BufferClear()
{
	// 描画用バッファを初期化用バッファで上書き
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
	m_draw_string.clear();
}

void Drawer::SetDrawBuffer(int x, int y, DrawType type)
{
	m_draw_buffer[x][y] = type;
}

void Drawer::SetBlankBuffer(int x, int y, DrawType type)
{
	m_blank_buffer[x][y] = type;
}

void Drawer::LinkDrawBuffer()
{
	// 描画バッファを連結する
	for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
		for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
			switch (m_draw_buffer[x][y])
			{
			case DrawType::Type_Empty:
				m_draw_string += "　";
				break;
			case DrawType::Type_Pile:
				m_draw_string += "□";
				break;
			case DrawType::Type_Disk:
				m_draw_string += "■";
				break;
			case DrawType::Type_Number1:
				m_draw_string += "１";
				break;
			case DrawType::Type_Number2:
				m_draw_string += "２";
				break;
			case DrawType::Type_Number3:
				m_draw_string += "３";
				break;
			default:
				break;
			}
		}
		m_draw_string += "\n";
	}
}
