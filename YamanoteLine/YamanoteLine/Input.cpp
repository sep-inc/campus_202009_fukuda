#include "Input.h"
#include "Global.h"
#include <cstdio>

Input::Input()
{
}

Input::~Input()
{
}

void Input::InputName()
{
	// �o���w�����͏���
	while (true) {
		printf("�o���w������ : ");
		char departure_station[MAX_STATION_NAME_NUM];
		scanf_s("%s", departure_station, MAX_STATION_NAME_NUM);

		// ���͉w�������������ǂ����A��������΂��̂܂܃f�[�^�Ǘ��N���X�ɃZ�b�g����
		if (g_array_station_data.SetDepartureStation(departure_station) == false) {
			printf("���̉w���͓��͂ł��܂���A������x���͂��Ȃ����Ă�������\n");
		}
		else {
			break;
		}
	}
	
	// �����w�����͏���
	while (true) {
		printf("�����w������ : ");
		char arrival_station[MAX_STATION_NAME_NUM];
		scanf_s("%s", arrival_station, MAX_STATION_NAME_NUM);

		// ���͉w�������������ǂ����A��������΂��̂܂܃f�[�^�Ǘ��N���X�ɃZ�b�g����
		if (g_array_station_data.SetArrivalStation(arrival_station) == false) {
			printf("���̉w���͓��͂ł��܂���A������x���͂��Ȃ����Ă�������\n");
		}
		else {
			break;
		}
	}
}
