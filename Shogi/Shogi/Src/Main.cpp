#include "ShogiGame/ShogiGame.h"
#include "Draw/Drawer.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + Cでプログラムを終了する関数
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	while (true) {
		/* 更新処理 */
		ShogiGame::Instance()->Update();
		/* 描画処理 */
		Drawer::Instance()->Run();
		/* ゲーム終了処理 */
		if (ShogiGame::Instance()->IsGameFinish()) {
			break;
		}
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