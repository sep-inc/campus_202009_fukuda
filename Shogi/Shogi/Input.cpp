#include "Input.h"
#include <cstdio>
#include <cstdlib>

Input* Input::p_instance = 0;

Input* Input::Instance() {
	if (p_instance == 0) {
		p_instance = new Input;
	}
	return p_instance;
}

char Input::InputChar()
{
	// ��������
	char tmp = getchar();
	// getchar()�̓��̓o�b�t�@�̃N���A
	while (getchar() != '\n');

	return tmp;
}

int Input::InputNum()
{
	// ��������
	char tmp = getchar();
	// getchar()�̓��̓o�b�t�@�̃N���A
	while (getchar() != '\n');
	// �����𐔎��ɕϊ�
	return atoi(&tmp);
}

Input::Input() {

}

Input::~Input()
{
}
