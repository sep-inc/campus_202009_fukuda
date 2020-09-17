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
	// 時間計算関数群
	// 右回り時間計算関数（第１引数：出発駅ID, 第２引数：到着駅ID）
	int CalcClockWiseTime(int start_station_id, int end_station_id);
	// 左回り時間計算関数（第１引数：出発駅ID, 第２引数：到着駅ID）
	int CalcCounterClockWiseTime(int start_station_id, int end_station_id);
	// 右回りかつ中央線ありの計算
	int CalcClockWiseTime2();
	// 左回りかつ中央線ありの計算
	int CalcCounterClockWiseTime2();

private:
	StationData m_station_data_array[MAX_DATA_NUM];	// 駅データを格納する配列

	char m_departure_station[MAX_STATION_NAME_NUM];	// 出発駅名
	int m_departure_station_data_id;				// 出発駅のデータID		

	char m_arrival_station[MAX_STATION_NAME_NUM];	// 到着駅名
	int m_arrival_station_data_id;					// 到着駅のデータID

	int m_shinjuku_data_id;		// 新宿のデータID保存変数
	int m_kanda_data_id;		// 神田のデータID保存変数　※中央線の処理に使用
};

#endif

