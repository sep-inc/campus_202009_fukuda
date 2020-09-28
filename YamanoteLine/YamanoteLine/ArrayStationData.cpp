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
	// 各計算時間結果をDrawerクラスに反映
	g_drawer.SetClockWiseTime(CalcClockWiseTime(m_departure_station_data_id, m_arrival_station_data_id));
	g_drawer.SetCounterClockWiseTime(CalcCounterClockWiseTime(m_departure_station_data_id, m_arrival_station_data_id));
	g_drawer.SetClockWiseTime2(CalcClockWiseTime2());
	g_drawer.SetCounterClockWiseTime2(CalcCounterClockWiseTime2());
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
		// 新宿か神田が配列に入った際は、中央線フラグをtrueにする
		if (strcmp(m_station_data_array[i].m_station_name, "新宿") == 0) {
			m_shinjuku_data_id = i;
		}
		else if(strcmp(m_station_data_array[i].m_station_name, "神田") == 0){
			m_kanda_data_id = i;
		}
	}
}

bool ArrayStationData::SetDepartureStation(char* name)
{
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		// 入力された駅名がデータにあればtrueを返す
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
	
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		// 入力された駅名がデータにあればtrueを返す
		if (strcmp(name, m_station_data_array[i].m_station_name) == 0) {
			strcpy(m_arrival_station, name);
			m_arrival_station_data_id = i;
			return true;
		}
	}
	return false;
}

int ArrayStationData::CalcClockWiseTime(int start_station_id, int end_station_id)
{
	int sum_time = 0;	// 通った時間の合計値
	int start_id = start_station_id;	// 現在地のID

	// 現在地が到着駅と一致するまで
	while (start_id != end_station_id) {
		// 右隣の駅の時間を足す
		sum_time += m_station_data_array[start_id].m_right_station_time;
		// 現在地を１つ進める
		start_id++;
		// 現在地がデータIDの最後になったらIDを0に戻す
		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	
	return sum_time;
}

int ArrayStationData::CalcCounterClockWiseTime(int start_station_id, int end_station_id)
{
	int sum_time = 0;	// 通った時間の合計値
	int start_id = start_station_id;	// 現在地のID

	// 現在地が到着駅と一致するまで
	while (start_id != end_station_id) {
		// 右隣の駅の時間を足す
		sum_time += m_station_data_array[start_id].m_left_station_time;
		// 現在地を１つ進める（反時計に進むため、1つマイナスする）
		start_id--;
		// 現在地がデータIDの最後になったらIDを0に戻す
		if (start_id < 0) {
			start_id = MAX_DATA_NUM - 1;
		}
	}

	return sum_time;
}

int ArrayStationData::CalcClockWiseTime2()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;
	bool is_passed_chuo_line = false;	// 中央線を通過したかのフラグ

	while (start_id != m_arrival_station_data_id) {
		// 中央線を通過していない場合の処理
		if (is_passed_chuo_line == false) {
			// 新宿駅から中央線に入る処理
			if (start_id == m_shinjuku_data_id) {
				// 中央線の時間を足す
				sum_time += CHUO_LINE_TIME;
				// 神田駅に移動
				start_id = m_kanda_data_id;
				// 通過フラグを立てる
				is_passed_chuo_line = true;
			}
			// 神田駅から中央線に入る処理
			else if (start_id == m_kanda_data_id) {
				// 中央線の時間を足す
				sum_time += CHUO_LINE_TIME;
				// 新宿駅へ移動
				start_id = m_shinjuku_data_id;
				// 通過フラグを立てる
				is_passed_chuo_line = true;
			}
			else {
				sum_time += m_station_data_array[start_id].m_right_station_time;
				start_id++;
			}
		}
		// 中央線を通過している場合の処理
		else {
			// 中央線を降りた駅から到着駅まで、時計回りと反時計回りではどちらが速いかの比較
			if (CalcClockWiseTime(start_id, m_arrival_station_data_id) < CalcCounterClockWiseTime(start_id, m_arrival_station_data_id)) {
				// 合計時間に時計回りの時間を足して計算終了
				sum_time += CalcClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
			else {
				// 合計時間に反時計回りの時間を足して計算終了
				sum_time += CalcCounterClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
		}

		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	return sum_time;
}

int ArrayStationData::CalcCounterClockWiseTime2()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;
	bool is_passed_chuo_line = false;	// 中央線を通過したかのフラグ

	while (start_id != m_arrival_station_data_id) {
		// 中央線を通過していない場合の処理
		if (is_passed_chuo_line == false) {
			// 新宿駅から中央線に入る処理
			if (start_id == m_shinjuku_data_id) {
				// 中央線の時間を足す
				sum_time += CHUO_LINE_TIME;
				// 神田駅に移動
				start_id = m_kanda_data_id;
				// 通過フラグを立てる
				is_passed_chuo_line = true;
			}
			// 神田駅から中央線に入る処理
			else if (start_id == m_kanda_data_id) {
				// 中央線の時間を足す
				sum_time += CHUO_LINE_TIME;
				// 新宿駅へ移動
				start_id = m_shinjuku_data_id;
				// 通過フラグを立てる
				is_passed_chuo_line = true;
			}
			else {
				sum_time += m_station_data_array[start_id].m_left_station_time;
				start_id--;
			}
		}
		// 中央線を通過している場合の処理
		else {
			// 中央線を降りた駅から到着駅まで、時計回りと反時計回りではどちらが速いかの比較
			if (CalcClockWiseTime(start_id, m_arrival_station_data_id) < CalcCounterClockWiseTime(start_id, m_arrival_station_data_id)) {
				// 合計時間に時計回りの時間を足して計算終了
				sum_time += CalcClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
			else {
				// 合計時間に反時計回りの時間を足して計算終了
				sum_time += CalcCounterClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
		}

		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	return sum_time;
}
