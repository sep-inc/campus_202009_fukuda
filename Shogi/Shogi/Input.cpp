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
	// 文字入力
	char tmp = getchar();
	// getchar()の入力バッファのクリア
	while (getchar() != '\n');

	return tmp;
}

int Input::InputNum()
{
	// 文字入力
	char tmp = getchar();
	// getchar()の入力バッファのクリア
	while (getchar() != '\n');
	// 文字を数字に変換
	return atoi(&tmp);
}

Input::Input() {

}

Input::~Input()
{
}
