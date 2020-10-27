#include "Draw/DrawerManager.h"
#include "Scenes/SceneManager.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + Cでプログラムを終了する関数
void SignalHandle(int);


int main() {
	signal(SIGINT, SignalHandle);


	while (true) {
		/* Sceneの更新処理 */
		SceneManager::Instance()->Update();

		/* 描画処理 */
		// 出力画面のクリア
		system("cls");
		// 描画情報のクリア
		DrawerManager::Instance()->Clear();
		// 描画情報のセット
		SceneManager::Instance()->Draw(DrawerManager::Instance()->GetDrawerInstance());
		// 描画
		DrawerManager::Instance()->Draw();
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