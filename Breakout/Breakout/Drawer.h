#ifndef DRAWER_H_
#define DRAWER_H_

#include "Definition.h"

// 1マスのサイズ
#define UNIT_X 16
#define UNIT_Y 16
// 描画サイズ
#define DRAW_X GAME_WIDTH / UNIT_X + 2
#define DRAW_Y GAME_HEIGHT / UNIT_Y + 2


// 描画クラス
class Drawer {
public:
	Drawer();
	~Drawer();

	// 初期化関数
	void Init();
	// 描画関数
	void DrawTable();
	// 描画バッファクリア
	void BufferClear();
	// フレーム配列と仮想座標配列の合成
	void ComposeMap();
	// 描画バッファへ書き込む関数 ※サイズ指定は自由
	void SetBlankBuffer(float x, float y, Kind kind, float width = 0.f , float height = 0.f);

private:
	// 描画用パラメータ
	struct DrawerParam {
		char m_kind;
	};

	DrawerParam m_blank_buffer[DRAW_X][DRAW_Y];				// 初期化用配列
	DrawerParam m_draw_array[DRAW_X][DRAW_Y];				// 書き込み用配列
};

#endif

