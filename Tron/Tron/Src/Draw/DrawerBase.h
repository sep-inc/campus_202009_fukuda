#ifndef DRAWER_BASE_H_
#define DRAWER_BASE_H_

/**
* @file DrawerBase.h
* @brief DrawerBaseクラスのヘッダ
*/

#include "../Definition.h"
#include <string>

/**
* @class DrawerBase
* @brief Drawerクラスの基底クラス
*/
class DrawerBase {
public:
	DrawerBase();
	virtual ~DrawerBase();

	/**
	* @brief 描画関数
	*/
	void Draw();

	/**
	* @brief 描画情報のクリア関数
	* 描画に使用した
	*/
	void Clear();

	//! 描画用バッファのセット関数
	virtual void SetDrawBuffer(Vec2 pos_, char* string_) = 0;

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
