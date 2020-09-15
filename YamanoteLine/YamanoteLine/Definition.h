#ifndef DEFINITION_H_
#define DEFINITION_H_

// 処理ステップ
enum class Step :int {
	STEP_NONE,
	STEP_INITIALIZE,	// 初期化ステップ
	STEP_UPDATE,		// 更新ステップ
	STEP_END,			// 破棄ステップ

	STEP_MAX
};

// 駅データ構造体
struct StationData {
	char m_station_name;		// 駅名変数
	int m_right_station_time;	// 右隣の駅までの時間
	int m_left_station_time;	// 左隣の駅までの時間
};




#endif

