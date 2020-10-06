#include "ShogiGame/ShogiGame.h"
#include "Draw/DrawerManager.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + C�Ńv���O�������I������֐�
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	while (true) {
		/* �X�V���� */
		ShogiGame::Instance()->Update();
		/* �`�揈�� */
		DrawerManager::Instance()->GetDrawerInstance()->Run();
		/* �Q�[���I������ */
		if (ShogiGame::Instance()->IsGameFinish()) {
			break;
		}
	}
	
	return 0;
}


/**
* @brief Ctrl + c�Ńv���O�������I������֐�
* @return void �߂�l�Ȃ�
*/
void SignalHandle(int) {
	exit(0);
}