#include "Draw/DrawerManager.h"
#include "TronGame/TronGame.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + Cでプログラムを終了する関数
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	// 描画クラスの生成
	DrawerManager::Instance()->CreateDrawer();

	while (true) {
		/* ゲームの更新 */
		TronGame::Instance()->Update();

		/* 描画処理 */
		// 描画情報のクリア
		DrawerManager::Instance()->m_p_drawer->BufferClear();
		// 描画情報作成
		// 描画
		DrawerManager::Instance()->m_p_drawer->Draw();
	}

	// 描画クラスの破棄
	DrawerManager::Instance()->DeleteDrawer();

	return 0;
}


/**
* @brief Ctrl + cでプログラムを終了する関数
* @return void 戻り値なし
*/
void SignalHandle(int) {
	exit(0);
}