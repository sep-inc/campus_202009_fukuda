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

private:
	// 右回り時間計算関数
	void CalcClockWiseTime();
	// 左回り時間計算関数
	void CalCounterClockWiseTime();

private:
	StationData m_station_data_array;	// 駅データを格納する配列
	char m_departure_station;			// 出発駅名
	char m_arrival_station;				// 到着駅名

	Step m_step;						// 現在のステップ

};

#endif

