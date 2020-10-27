#include "Draw/DrawerManager.h"
#include "Scenes/SceneManager.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + C�Ńv���O�������I������֐�
void SignalHandle(int);


int main() {
	signal(SIGINT, SignalHandle);


	while (true) {
		/* Scene�̍X�V���� */
		SceneManager::Instance()->Update();

		/* �`�揈�� */
		// �o�͉�ʂ̃N���A
		system("cls");
		// �`����̃N���A
		DrawerManager::Instance()->Clear();
		// �`����̃Z�b�g
		SceneManager::Instance()->Draw(DrawerManager::Instance()->GetDrawerInstance());
		// �`��
		DrawerManager::Instance()->Draw();
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