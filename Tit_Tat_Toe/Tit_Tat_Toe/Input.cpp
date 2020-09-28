#include "Input.h"
#include <conio.h>
#include <cstdio>
#include <cinttypes>

Input::Input()
{
}

Input::~Input()
{
}

Vec2 Input::InputPlayer()
{
	Vec2 pos = {};	// 入力値保存用の変数

	// X座標の入力処理
	while (true) {
		char tmp_x = '\0';
		printf("列を入力してください : ");
		// 入力受付
		// tmp = _getch();
		tmp_x = getchar();
		// 入力したキーをクリア　※この処理がないと、次のループでEnterが読み込まれてしまう
		while (getchar() != '\n');
		// aが入力されたら、X座標に0を入れてXの入力処理を終了
		if (tmp_x == 'a') {
			pos.m_x = 0;
			break;
		}
		// bが入力されたら、X座標に0を入れてXの入力処理を終了
		else if (tmp_x == 'b') {
			pos.m_x = 1;
			break;
		}
		// cが入力されたら、X座標に0を入れてXの入力処理を終了
		else if (tmp_x == 'c') {
			pos.m_x = 2;
			break;
		}
		// 入力の例外処理
		else {
			printf("入力が不正です、もう一度入力しなおして下さい\n");
		}
	}
	printf("\n");

	// Y座標の入力処理
	while (true) {
		int tmp_y = 0;
		printf("行を入力してください : ");
		// 入力受付
		tmp_y = getchar();
		// 入力したキーをクリア
		while (getchar() != '\n');
		// 入力値が1ならY座標に0を入れてYの入力処理を終了
		if (tmp_y == '1') {
			pos.m_y = 0;
			break;
		}
		// 入力値が1ならY座標に1を入れてYの入力処理を終了
		else if (tmp_y == '2') {
			pos.m_y = 1;
			break;
		}
		// 入力値が1ならY座標に2を入れてYの入力処理を終了
		else if(tmp_y == '3') {
			pos.m_y = 2;
			break;
		}
		// 入力の例外処理
		else {
			printf("入力が不正です、もう一度入力しなおして下さい\n");
		}
	}
	printf("\n");
	// 入力された情報を返す
	return pos;
}
