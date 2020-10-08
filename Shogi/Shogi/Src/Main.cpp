#include "ShogiGame/ShogiGame.h"
#include "Draw/Drawer.h"
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
		// �`��o�b�t�@�̃N���A
		Drawer::Instance()->ClearBuffer();
		// �`����̃Z�b�g
		ShogiGame::Instance()->SetDraw();
		// �`��
		Drawer::Instance()->DrawBuffer();
	
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