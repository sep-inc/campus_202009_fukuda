#include "Global.h"
#include <conio.h>

// ESCのキーコード
#define ESC (0x1B)


int main() {
	// データの読み込み
	g_load_data.Load();
	while (true) {
		// 駅名入力
		g_input.InputName();
		// データの計算処理
		g_array_station_data.Update();
		// 結果出力
		g_drawer.Draw();

		// 続けるか終了するかの判定
		printf("\nESCキー：終了　その他のキー：続ける\n");
		if (getch() == ESC) {
			break;
		}
	}
	
	return 0;
}