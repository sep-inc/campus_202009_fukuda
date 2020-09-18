#include "Global.h"
#include <csignal>

// Ctrl + Cでプログラムを終了する関数
void signal_handle(int); 

int main() {
	signal(SIGINT, signal_handle);
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
		if (g_input.InputContinueOrEnd()) {
			break;
		}
	}
	
	return 0;
}

void signal_handle(int) {
	printf("\nプログラム終了\n");
	exit(0);
}