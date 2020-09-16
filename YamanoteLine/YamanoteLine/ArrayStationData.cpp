#include "ArrayStationData.h"
#include "Global.h"
#include <cstdio>
#include <cstring>

ArrayStationData::ArrayStationData():
	m_station_data_array{},
	m_departure_station{},
	m_departure_station_data_id(0),
	m_arrival_station{},
	m_arrival_station_data_id(0)
{
}

ArrayStationData::~ArrayStationData()
{
}

void ArrayStationData::Update()
{
	g_drawer.SetClockWiseTime(CalcClockWiseTime());
	g_drawer.SetCounterClockWiseTime(CalcCounterClockWiseTime());
}

void ArrayStationData::SetLoadData(LoadDataParam *data, int data_size)
{
	for (int i = 0; i < data_size; i++) {
		// 駅名格納処理
		strcpy(m_station_data_array[i].m_station_name, data[i].m_station_name);
		// 右隣の駅への時間格納処理
		m_station_data_array[i].m_right_station_time = data[i].m_right_station_time;
		// 左隣の駅への時間格納処理
		if (i == 0) {
			m_station_data_array[i].m_left_station_time = data[data_size - 1].m_right_station_time;
		}
		else {
			m_station_data_array[i].m_left_station_time = m_station_data_array[i - 1].m_right_station_time;
		}
	}
}

bool ArrayStationData::SetDepartureStation(char* name)
{
	// 入力された駅名がデータにあればtrueを返す
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		if (strcmp(name, m_station_data_array[i].m_station_name) == 0) {
			strcpy(m_departure_station, name);
			m_departure_station_data_id = i;
			return true;
		}
	}
	return false;
}

bool ArrayStationData::SetArrivalStation(char* name)
{
	// 出発駅と同じ駅名が入力された場合
	if (strcmp(name, m_departure_station) == 0) {
		return false;
	}
	// 入力された駅名がデータにあればtrueを返す
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		if (strcmp(name, m_station_data_array[i].m_station_name) == 0) {
			strcpy(m_arrival_station, name);
			m_arrival_station_data_id = i;
			return true;
		}
	}
	return false;
}

int ArrayStationData::CalcClockWiseTime()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;

	while (start_id != m_arrival_station_data_id) {
		sum_time += m_station_data_array[start_id].m_right_station_time;
		start_id++;
		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	
	return sum_time;
}

int ArrayStationData::CalcCounterClockWiseTime()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;

	while (start_id != m_arrival_station_data_id) {
		sum_time += m_station_data_array[start_id].m_left_station_time;
		start_id--;
		if (start_id < 0) {
			start_id = MAX_DATA_NUM - 1;
		}
	}

	return sum_time;
}
