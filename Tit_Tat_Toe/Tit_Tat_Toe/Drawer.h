#ifndef DRAWER_H_
#define DRAWER_H_

#include "Definition.h"

/**
* @file Drawer.h
* @brief Drawerクラスのヘッダ
*/


/**
* @brief 描画処理をするクラス
*/
class Drawer {
public:
	Drawer();
	~Drawer();

	/**
	* Drawerクラス初期化関数
	* ゲームループの前に1度だけ呼び出す
	*/
	void Init();

	/**
	* Drawerクラスの処理まとめ関数
	* 毎ループ回したい処理をまとめるための関数
	*/
	void Run();


public:
	// セット関数群

	/**
	* ゲームマップセット関数
	* Mapクラスで呼び出し、描画バッファにゲームマップを書き込む
	*
	* @param map[][] 描画バッファに書き込むゲームマップ
	*/
	void SetGameMap(DrawType map[][GAME_MAP_HEIGHT]);

	/**
	* 勝敗結果セット関数
	* Mapクラスで呼び出し、勝敗結果をセットする
	*
	* @param result セットする勝敗結果
	*/
	void SetResult(MatchResult result);


private:
	/**
	* 描画バッファクリア関数
	* 描画バッファに初期化用バッファをコピーする
	*/
	void BufferClear(); 

	/**
	* 描画関数
	* 描画用バッファを描画する関数
	*/
	void DrawBuffer();

	/**
	* 勝敗結果表示関数
	* 勝敗がついたときのみ動く関数
	*/
	void DrawResult();


private:
	//! 初期化用バッファ
	DrawType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	//! 描画用バッファ
	DrawType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	// 勝敗結果保存変数
	MatchResult m_result;

};

#endif

