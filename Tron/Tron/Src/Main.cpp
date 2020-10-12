#include "Draw/DrawerManager.h"
#include "TronGame/TronGame.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + C�Ńv���O�������I������֐�
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);
	
	// �`��N���X�̐���
	DrawerManager::Instance()->CreateDrawer();

	while (true) {
		
		/* �Q�[���̍X�V */
		TronGame::Instance()->Update();

		if (TronGame::Instance()->IsGameFinish()) {
			break;
		}

		/* �`�揈�� */
		// �o�͉�ʂ̃N���A
		system("cls");
		// �`����̃N���A
		DrawerManager::Instance()->m_p_drawer->Clear();
		// �`����̃Z�b�g
		TronGame::Instance()->SetDrawMap();
		TronGame::Instance()->SetResult();
		// �`��
		DrawerManager::Instance()->m_p_drawer->Draw();

	}

	// �`��N���X�̔j��
	DrawerManager::Instance()->DeleteDrawer();

	return 0;
}


/**
* @brief Ctrl + c�Ńv���O�������I������֐�
* @return void �߂�l�Ȃ�
*/
void SignalHandle(int) {
	exit(0);
}