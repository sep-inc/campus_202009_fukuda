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
	// 出発駅名入力処理
	while (true) {
		printf("出発駅名入力 : ");
		char departure_station[MAX_STATION_NAME_NUM];
		scanf_s("%s", departure_station, MAX_STATION_NAME_NUM);

		// 入力駅名が正しいかどうか、正しければそのままデータ管理クラスにセットする
		if (g_array_station_data.SetDepartureStation(departure_station) == false) {
			printf("その駅名は入力できません、もう一度入力しなおしてください\n");
		}
		else {
			break;
		}
	}
	
	// 到着駅名入力処理
	while (true) {
		printf("到着駅名入力 : ");
		char arrival_station[MAX_STATION_NAME_NUM];
		scanf_s("%s", arrival_station, MAX_STATION_NAME_NUM);

		// 入力駅名が正しいかどうか、正しければそのままデータ管理クラスにセットする
		if (g_array_station_data.SetArrivalStation(arrival_station) == false) {
			printf("その駅名は入力できません、もう一度入力しなおしてください\n");
		}
		else {
			break;
		}
	}
}
