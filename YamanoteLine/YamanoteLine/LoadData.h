#ifndef LOADDATA_H_
#define LOADDATA_H_

#include "Definition.h"

// ファイル読み込みクラス
class LoadData {
public:
	LoadData();
	~LoadData();

	// 更新関数
	void Update();

private:
	// ファイルオープン関数
	void OpenFile();	
	// ファイル読み込み関数
	void LoadFile();	
	// ファイル終了関数
	void CloseFile();

private:
	StationData m_load_data;	// 読み込んだデータの格納配列
	Step m_step;				// 現在のステップ

};

#endif

