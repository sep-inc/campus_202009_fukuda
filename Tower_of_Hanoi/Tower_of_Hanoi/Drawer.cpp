#include "Drawer.h"


Drawer::Drawer():
	m_blank_buffer{DrawType::Type_Empty},
	m_draw_buffer{DrawType::Type_Empty}
{
}


Drawer::~Drawer()
{
}

void Drawer::Init()
{
}

void Drawer::Run()
{
	// 描画バッファの連結
	LinkDrawBuffer();
	// 描画
	Print();
}

void Drawer::Print()
{
}

void Drawer::SetDrawBuffer(int x, int y, DrawType type)
{
}

void Drawer::SetBlankBuffer(int x, int y, DrawType type)
{


}

void Drawer::LinkDrawBuffer()
{
}
