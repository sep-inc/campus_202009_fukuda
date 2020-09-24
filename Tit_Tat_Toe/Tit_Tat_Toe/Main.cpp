#include "Global.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + cでプログラムを終了する関数
void SignalHandle(int);

int main() {
	// 描画クラスの初期化
	g_drawer.Init();

	while (true) {
		// 各クラスのステップ処理
		g_player.Update();
		g_enemy.Update();
		g_map.Update();

		// 描画処理
		g_drawer.Run();
	}

	return 0;
}


/**
* @brief Ctrl + cでプログラムを終了する関数
* @return void 戻り値なし
*/
void SignalHandle(int) {
	exit(0);
}