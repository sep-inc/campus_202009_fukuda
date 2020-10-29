#include "ShogiGameDrawer.h"

ShogiGameDrawer::ShogiGameDrawer()
{
}

ShogiGameDrawer::~ShogiGameDrawer()
{
}

void ShogiGameDrawer::Draw()
{
	printf("%s", m_draw_string.c_str());
	if (m_result_string != "\0") {
		printf("%s", m_result_string.c_str());
	}
}

void ShogiGameDrawer::Clear()
{
	m_draw_string.clear();
}

void ShogiGameDrawer::SetDrawBuffer(Vec2_Int pos_, char* string_)
{
	/*
		使用しない
	*/
}

void ShogiGameDrawer::SetDrawMapString(std::string map_)
{
	m_draw_string = map_;
}

DrawerBase* ShogiGameDrawer::InstanceSelectGameDrawer()
{
	return static_cast<DrawerBase*>(new ShogiGameDrawer);
}

void ShogiGameDrawer::BufferClear()
{
	/*
		使用しない
	*/
}

void ShogiGameDrawer::LinkDrawBuffer()
{
	/*
		使用しない
	*/
}
