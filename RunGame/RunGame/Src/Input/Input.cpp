#include "Input.h"

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