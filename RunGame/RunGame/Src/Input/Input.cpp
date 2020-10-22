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

bool Input::PressSpaceKey(KeyType key_type_)
{
	int buf;
	if (_kbhit()) {
		buf = _getch();
		fflush(stdin);
		if (buf == key_type_) {
			return true;
		}
	}
	return false;
}
