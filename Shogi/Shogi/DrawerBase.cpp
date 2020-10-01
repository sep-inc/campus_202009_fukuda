#include "DrawerBase.h"
#include <iostream>

DrawerBase::DrawerBase()
{
}


DrawerBase::~DrawerBase()
{
}

void DrawerBase::Print()
{
	std::cout << m_draw_string.c_str() << std::flush;
}
