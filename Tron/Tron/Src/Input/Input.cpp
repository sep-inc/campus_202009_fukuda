#include "Input.h"
#include <conio.h>

Input* Input::p_instance = 0;


Input::Input()
{

}

Input::~Input()
{

}

Input* Input::Instance()
{
	if (p_instance == 0) {
		p_instance = new Input;
	}
	return p_instance;
}

Vec2 Input::InputDirection()
{
	Vec2 pos;
	int key;
	while (true) {
		key = _getch();
		if ((key == 0x00) || (key == 0xe0)) {
			key = _getch();
			if (key == LEFT_KEY)		{ pos.m_x = -1; }
			else if (key == RIGHT_KEY)	{ pos.m_x = 1; }
			else if (key == UP_KEY)		{ pos.m_y = -1; }
			else if (key == DOWN_KEY)	{ pos.m_y = 1; }
		}
	}
	return pos;
}
