#include "Input.h"
#include <cstdio>
#include <cstdlib>
#include <conio.h>


Input::Input()
{
}


Input::~Input()
{
}

int Input::SelectSourcePile()
{
	char tmp = 0;	// ���͂����l��ۑ�����ϐ�

	while (true) {
		printf("�������~�Ղ̂���ԍ������ : ");
		// �l�̓���
		tmp = getchar();
		// getchar�œ��͂��ꂽ�o�b�t�@�̃N���A
		while (getchar() != '\n');
		// ���͂��ꂽ�l��1�A�Q�A�R�̂����ꂩ�Ȃ�l��Ԃ�
		if (tmp == '1'|| tmp == '2' || tmp == '3') {
			return atoi(&tmp);
		}
		// ��O����
		else {
			printf("���͂����l���s���ł�\n");
		}
	}
}

int Input::SelectDestinationPile(int source_pile_num)
{
	char tmp;	// ���͂����l��ۑ�����ϐ�

	while (true) {
		printf("�~�Ղ��ړ�������ꏊ�̔ԍ������ : ");
		// �l�̓���
		tmp = getchar();
		// getchar�œ��͂��ꂽ�o�b�t�@�̃N���A
		while (getchar() != '\n');
		// ���͂��ꂽ�l���ړ����̔ԍ��Ɠ����ꍇ
		if (atoi(&tmp) == source_pile_num) {
			printf("�����ɂ͈ړ��ł��܂���\n");
		}
		// ���͂��ꂽ�l���P�A�Q�A�R�ȊO�̒l�̏ꍇ
		else if (tmp != '1' && tmp != '2' && tmp != '3') {
			printf("���͂����l���s���ł�\n");
		}
		else {
			return atoi(&tmp);
		}
	}
}
