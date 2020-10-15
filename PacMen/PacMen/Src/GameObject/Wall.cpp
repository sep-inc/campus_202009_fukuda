#include "Wall.h"
#include <cstring>

Wall::Wall()
{
	Init();
}

Wall::~Wall()
{
}

void Wall::Init()
{
	m_param.m_type = PacMenObjectType::WALL;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "■");
}
