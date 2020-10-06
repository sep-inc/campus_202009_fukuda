#ifndef SHOGI_DRAWER_H_
#define SHOGI_DRAWER_H_

/**
* @file ShogiDrawer.h
* @brief ShogiDrawerクラスのヘッダ
*/

#include "DrawerBase.h"
#include "../Definition.h"

/**
* @class ShogiDrawer
* ShogiGameで使用されるDrawerクラス
*/
class ShogiDrawer : public DrawerBase {
public:
	ShogiDrawer();
	~ShogiDrawer()override;

	/**
	@ brief 描画バッファクリア関数
	*/
	void ClearBuffer()override;

	/**
	* @brief 描画バッファへ書き込む関数
	* @param x 描画時のX座標
	* @param y 描画時のY座標
	* @param type 描画する種類
	*/
	void SetDrawBuffer(int x, int y, ObjectType type);

	/**
	* @brief 初期化用バッファへ書き込む関数
	* @param x 描画時のX座標
	* @param y 描画時のY座標
	* @param type 描画する種類
	*/
	void SetBlankBuffer(int x, int y, ObjectType type);

	/**
	* @brief リザルト情報をセットする関数
	*/
	void SetResult();

private:
	//! 初期化用バッファ
	ObjectType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	//! 描画用バッファ
	ObjectType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

};

#endif
