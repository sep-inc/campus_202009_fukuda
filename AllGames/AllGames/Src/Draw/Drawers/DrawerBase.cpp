#include "DrawerBase.h"
#include <cstdio>
#include <cstring>

DrawerBase::DrawerBase() :
	m_draw_string("\0"),
	m_result_string("\0")
{
}

DrawerBase::~DrawerBase()
{
}

void DrawerBase::Draw()
{
	LinkDrawBuffer();
	printf("%s", m_draw_string.c_str());
	if (m_result_string != "\0") {
		printf("%s", m_result_string.c_str());
	}
}

void DrawerBase::Clear()
{
	// 描画用文字列クリア
	m_draw_string.clear();
	// 描画バッファクリア
	BufferClear();
}

void DrawerBase::SetResultString(std::string result_)
{
	m_result_string = result_;
}