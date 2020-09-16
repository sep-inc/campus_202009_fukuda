#ifndef ARRAYSTATIONDATA_H_
#define ARRAYSTATIONDATA_H_

#include "Definition.h"

// 駅データ格納クラス
class ArrayStationData {
public:
	ArrayStationData();
	~ArrayStationData(); 

	// 更新関数
	void Update();

	// セット関数群
	// 読み込んだデータを格納配列にセットする関数
	void SetLoadData(LoadDataParam* data, int data_size);
	// 入力された出発駅名をセットする関数
	bool SetDepartureStation(char* name);
	// 入力された到着駅名をセットする関数
	bool SetArrivalStation(char* name);

private:
	// 右回り時間計算関数
	int CalcClockWiseTime();
	// 左回り時間計算関数
	int CalcCounterClockWiseTime();

private:
	StationData m_station_data_array[MAX_DATA_NUM];	// 駅データを格納する配列
	char m_departure_station[MAX_STATION_NAME_NUM];	// 出発駅名
	int m_departure_station_data_id;				// 出発駅のデータID		
	char m_arrival_station[MAX_STATION_NAME_NUM];	// 到着駅名
	int m_arrival_station_data_id;					// 到着駅のデータID

};

#endif

