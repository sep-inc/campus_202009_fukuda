#include "Input.h"
#include <cstdio>
#include <cstdlib>
#include <conio.h>


Input::Input()
{
}


Input::~Input()
{
}

int Input::SelectSourcePile()
{
	char tmp = 0;	// 入力した値を保存する変数

	while (true) {
		printf("動かす円盤のある番号を入力 : ");
		// 値の入力
		tmp = getchar();
		// getcharで入力されたバッファのクリア
		while (getchar() != '\n');
		// 入力された値が1、２、３のいずれかなら値を返す
		if (tmp == '1'|| tmp == '2' || tmp == '3') {
			return atoi(&tmp);
		}
		// 例外処理
		else {
			printf("入力した値が不正です\n");
		}
	}
}

int Input::SelectDestinationPile(int source_pile_num)
{
	char tmp;	// 入力した値を保存する変数

	while (true) {
		printf("円盤を移動させる場所の番号を入力 : ");
		// 値の入力
		tmp = getchar();
		// getcharで入力されたバッファのクリア
		while (getchar() != '\n');
		// 入力された値が移動元の番号と同じ場合
		if (atoi(&tmp) == source_pile_num) {
			printf("そこには移動できません\n");
		}
		// 入力された値が１、２、３以外の値の場合
		else if (tmp != '1' && tmp != '2' && tmp != '3') {
			printf("入力した値が不正です\n");
		}
		else {
			return atoi(&tmp);
		}
	}
}
