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

bool Input::PressSpaceKey(KeyType key_type_)
{
	if (_kbhit()) {
		if (_getch() == key_type_) {
			return true;
		}
	}
	return false;
}
