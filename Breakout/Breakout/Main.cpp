#include "Global.h"
#include <cstdio>
#include <cstdlib>

/*
	バーの追尾処理、それに伴った当たり判定の設計を今後変更予定
*/

int main() {
	g_drawer.Init();

	while (true) {
		getchar();
		system("cls");

		/* ステップ更新 */
		g_block_array.Update();
		g_bar.Update();
		g_ball.Update();
		
		/* 描画処理 */
		g_drawer.BufferClear();
		g_block_array.SetUpDrawBuffer();
		g_bar.SetUpDrawBuffer();
		g_ball.SetUpDrawBuffer();
		g_drawer.DrawTable();
	}

	return 0;
}