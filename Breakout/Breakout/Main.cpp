#include "Global.h"
#include <cstdio>
#include <cstdlib>

/*
	�o�[�̒ǔ������A����ɔ����������蔻��̐݌v������ύX�\��
*/

int main() {
	g_drawer.Init();

	while (true) {
		getchar();
		system("cls");

		/* �X�e�b�v�X�V */
		g_block_array.Update();
		g_bar.Update();
		g_ball.Update();
		
		/* �`�揈�� */
		g_drawer.BufferClear();
		g_block_array.SetUpDrawBuffer();
		g_bar.SetUpDrawBuffer();
		g_ball.SetUpDrawBuffer();
		g_drawer.DrawTable();
	}

	return 0;
}