#include "Input.h"
#include <conio.h>
#include <cstdio>
#include <cinttypes>

Input::Input()
{
}

Input::~Input()
{
}

Vec2 Input::InputPlayer()
{
	Vec2 pos = {};	// ���͒l�ۑ��p�̕ϐ�

	// X���W�̓��͏���
	while (true) {
		char tmp_x = '\0';
		printf("�����͂��Ă������� : ");
		// ���͎�t
		// tmp = _getch();
		tmp_x = getchar();
		// ���͂����L�[���N���A�@�����̏������Ȃ��ƁA���̃��[�v��Enter���ǂݍ��܂�Ă��܂�
		while (getchar() != '\n');
		// a�����͂��ꂽ��AX���W��0������X�̓��͏������I��
		if (tmp_x == 'a') {
			pos.m_x = 0;
			break;
		}
		// b�����͂��ꂽ��AX���W��0������X�̓��͏������I��
		else if (tmp_x == 'b') {
			pos.m_x = 1;
			break;
		}
		// c�����͂��ꂽ��AX���W��0������X�̓��͏������I��
		else if (tmp_x == 'c') {
			pos.m_x = 2;
			break;
		}
		// ���̗͂�O����
		else {
			printf("���͂��s���ł��A������x���͂��Ȃ����ĉ�����\n");
		}
	}
	printf("\n");

	// Y���W�̓��͏���
	while (true) {
		int tmp_y = 0;
		printf("�s����͂��Ă������� : ");
		// ���͎�t
		tmp_y = getchar();
		// ���͂����L�[���N���A
		while (getchar() != '\n');
		// ���͒l��1�Ȃ�Y���W��0������Y�̓��͏������I��
		if (tmp_y == '1') {
			pos.m_y = 0;
			break;
		}
		// ���͒l��1�Ȃ�Y���W��1������Y�̓��͏������I��
		else if (tmp_y == '2') {
			pos.m_y = 1;
			break;
		}
		// ���͒l��1�Ȃ�Y���W��2������Y�̓��͏������I��
		else if(tmp_y == '3') {
			pos.m_y = 2;
			break;
		}
		// ���̗͂�O����
		else {
			printf("���͂��s���ł��A������x���͂��Ȃ����ĉ�����\n");
		}
	}
	printf("\n");
	// ���͂��ꂽ����Ԃ�
	return pos;
}
