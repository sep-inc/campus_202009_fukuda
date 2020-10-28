#ifndef UTILITY_H_
#define UTILITY_H_

/**
* @file Utility.h
* @brief 汎用的なものをまとめたヘッダ
*/


struct Vec2_Int
{
	int m_x;
	int m_y;

	Vec2_Int():
		m_x(0),
		m_y(0)
	{}

	Vec2_Int(int x_, int y_):
		m_x(x_),
		m_y(y_)
	{}
};

struct Vec2_Float
{
	float m_x;
	float m_y;

	Vec2_Float() :
		m_x(0.f),
		m_y(0.f)
	{}
};

#endif
