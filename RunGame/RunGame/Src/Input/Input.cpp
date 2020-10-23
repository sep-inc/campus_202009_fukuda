#include "Input.h"
#include <cstdio>
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

int Input::PressSpaceKey()
{
	int buf = 0;
	if (_kbhit()) {
		buf = _getch();
		return buf;
	}
	return -1;
}

