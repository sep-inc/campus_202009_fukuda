#include "Draw/DrawerManager.h"
#include <cstdlib>
#include <csignal>

//! Ctrl + C�Ńv���O�������I������֐�
void SignalHandle(int);

int main() {
	signal(SIGINT, SignalHandle);

	// �`��N���X�̐���
	DrawerManager::Instance()->CreateDrawer();

	while (true) {


		/* �`�揈�� */
		// �`����̃N���A
		DrawerManager::Instance()->m_p_drawer->BufferClear();
		// �`����쐬
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