#ifndef DEFINITION_H_
#define DEFINITION_H_

// 読み込むデータの数　※動的にサイズを確保する処理ができ次第、消す
#define MAX_DATA_NUM 29

// 駅名の最大文字数
#define MAX_STATION_NAME_NUM 32


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
	char m_station_name[MAX_STATION_NAME_NUM];	// 駅名変数
	int m_right_station_time;	// 右隣の駅までの時間
	int m_left_station_time;	// 左隣の駅までの時間
};

// 読み込むデータ用の構造体
struct LoadDataParam {
	char m_station_name[MAX_STATION_NAME_NUM];
	int m_right_station_time;
};



#endif

