﻿#include "Draw/DrawerManager.h"
#include "PacMenGame/PacMenGame.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + Cでプログラムを終了する関数
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	// 描画クラスの生成
	DrawerManager::Instance()->CreateDrawer();

	while (true) {
		/* ゲームの更新処理 */
		PacMenGame::Instance()->Update();
		if (PacMenGame::Instance()->IsGameFinish()) {
			break;
		}

		/* 描画処理 */
		// 出力画面のクリア
		system("cls");
		// 描画情報のクリア
		DrawerManager::Instance()->m_p_drawer->Clear();
		// 描画情報のセット
		PacMenGame::Instance()->Draw();
		PacMenGame::Instance()->SetResult();
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