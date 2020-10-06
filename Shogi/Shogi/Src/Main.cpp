#include "ShogiGame/ShogiGame.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + C�Ńv���O�������I������֐�
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	ShogiGame::Instance()->Update();

	return 0;
}


/**
* @brief Ctrl + c�Ńv���O�������I������֐�
* @return void �߂�l�Ȃ�
*/
void SignalHandle(int) {
	exit(0);
}