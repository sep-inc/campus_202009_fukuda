﻿#ifndef DRAWER_BASE_H_
#define DRAWER_BASE_H_

#include "../Utility/Utility.h"
#include <string>

/**
* @class DrawerBase
* @brief Drawerクラスの基底クラス
*/
class DrawerBase
{
public:
	DrawerBase();
	virtual ~DrawerBase();

	/**
	* @brief 描画関数
	*/
	virtual void Draw();

	/**
	* @brief 描画情報のクリア関数
	* 描画に使用した
	*/
	virtual void Clear();

	//! 描画用バッファのセット関数
	virtual void SetDrawBuffer(Vec2_Int pos_, char* string_) = 0;

	//! 文字列になっているマップ情報のセット関数
	virtual void SetDrawMapString(std::string map_);

	/**
	* @brief リザルト情報をセットする関数
	* @param result_ 出力する結果の文字列
	*/
	void SetResultString(std::string result_);


protected:
	//! 描画バッファのクリア
	virtual void BufferClear() = 0;

	//! 描画バッファを連結して１つの文字列へ変換する関数
	virtual void LinkDrawBuffer() = 0;

protected:
	//! 描画用文字列
	std::string m_draw_string;
	//! リザルト描画用文字列
	std::string m_result_string;
};

#endif
