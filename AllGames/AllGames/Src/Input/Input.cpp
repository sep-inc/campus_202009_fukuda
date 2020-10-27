#include "Input.h"
#include "../AllDefinition.h"
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

int Input::GetKey()
{
	int buf = 0;
	// キーが入力されていた場合
	if (_kbhit()) {
		buf = _getch();
		// 入力文字が2バイト（特殊文字）の場合
		if ((buf == KeyType::NULL_KEY) || (buf == KeyType::SO_KEY)) {
			buf = _getch();
		}
		return buf;
	}
	// キーが入力されていなかった場合
	return -1;
}
