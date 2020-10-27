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
	// �L�[�����͂���Ă����ꍇ
	if (_kbhit()) {
		buf = _getch();
		// ���͕�����2�o�C�g�i���ꕶ���j�̏ꍇ
		if ((buf == KeyType::NULL_KEY) || (buf == KeyType::SO_KEY)) {
			buf = _getch();
		}
		return buf;
	}
	// �L�[�����͂���Ă��Ȃ������ꍇ
	return -1;
}
