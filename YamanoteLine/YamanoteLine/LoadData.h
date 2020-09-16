#ifndef LOADDATA_H_
#define LOADDATA_H_

#include "Definition.h"
#include <cstdio>
#include <vector>

// ファイル読み込みクラス
class LoadData {
public:
	LoadData();
	~LoadData();

	// 読み込み処理関数
	void Load();

private:
	// ファイルオープン関数
	void OpenFile();	
	// ファイル読み込み関数
	void LoadFile();	
	// ファイル終了関数
	void CloseFile();

private:
	// 読み込んだ駅データ　※ファイル読み込み処理が動いたら消す
	LoadDataParam m_load_data[MAX_DATA_NUM] = {
	{"新宿"		,2},
	{"新大久保"	,2},
	{"高田馬場"	,2},
	{"目白"		,3},
	{"池袋"		,2},
	{"大塚"		,2},
	{"巣鴨"		,2},
	{"駒込"		,2},
	{"田端"		,2},
	{"西日暮里"	,1},
	{"日暮里"	,2},
	{"鶯谷"		,2},
	{"上野"		,2},
	{"御徒町"	,2},
	{"秋葉原"	,2},
	{"神田"		,1},
	{"東京"		,2},
	{"有楽町"	,2},
	{"新橋"		,2},
	{"浜松町"	,2},
	{"田町"		,2},
	{"品川"		,3},
	{"大崎"		,2},
	{"五反田"	,2},
	{"目黒"		,3},
	{"恵比寿"	,2},
	{"渋谷"		,2},
	{"原宿"		,2},
	{"代々木"	,2}
	};
	

	FILE* m_fp;				// ファイルポインタ変数
	// LoadDataParam m_load_data[MAX_DATA_NUM];	// 読み込んだデータの格納配列
};

#endif

