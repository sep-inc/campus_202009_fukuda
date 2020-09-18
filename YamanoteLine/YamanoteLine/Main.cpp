﻿#include "Global.h"


int main() {
	// データの読み込み
	g_load_data.Load();
	while (true) {
		
		// 駅名入力
		g_input.InputName();
		// データの計算処理
		g_array_station_data.Update();
		// 結果出力
		g_drawer.Draw();

		// 続けるか終了するかの判定
		if (g_input.InputContinueOrEnd()) {
			break;
		}
	}
	
	return 0;
}