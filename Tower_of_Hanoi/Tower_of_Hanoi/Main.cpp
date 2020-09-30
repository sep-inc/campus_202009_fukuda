#include "ObjectManager.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + Cでプログラムを終了する関数
void SignalHandle(int);


int main() {
	signal(SIGINT, SignalHandle);

	ObjectManager::Instance()->CreateObjects();

	while (true) {
		ObjectManager::Instance()->m_p_player->UpdateStep();
		ObjectManager::Instance()->m_p_game_stage_manager->UpdateStep();
		ObjectManager::Instance()->m_p_drawer->Run();
		getchar();
		system("cls");
	}

	ObjectManager::Instance()->DeleteObjects();

	return 0;
}


/**
* @brief Ctrl + cでプログラムを終了する関数 
* @return void 戻り値なし
*/
void SignalHandle(int) {
	exit(0);
}