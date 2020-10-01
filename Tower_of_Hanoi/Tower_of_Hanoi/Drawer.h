#ifndef DRAWER_H_
#define DRAWER_H_

/**
* @file Drawer.h
* @brief Drawerクラスのヘッダ
*/


#include "Definition.h"
#include <string>

/**
* @class Drawer.h
* @brief 描画クラス
*/
class Drawer
{
public:
	Drawer();
	~Drawer();

	/**
	* @brief 初期化関数
	*/
	void Init();

	/**
	* @brief 描画処理をまとめた関数
	* Mainではこの関数のみを呼び出す
	*/
	void Run();

	/**
	* @brief 描画関数
	* 連結した文字列を描画する
	*/
	void Print();

	/**
	* @brief ゲームクリア時に表示する関数
	*/
	void PrintClear();

	/**
	* @brief バッファクリア関数
	*/
	void BufferClear();

	/**
	* @brief 描画バッファにデータをセットする関数
	*/
	void SetDrawBuffer(int x, int y, DrawType type);

	/**
	* @brief 初期化用バッファにデータをセットする関数
	*/
	void SetBlankBuffer(int x, int y, DrawType type);

	/**
	* @brief 描画バッファ連結関数
	* 描画バッファの中身を1つの文字列に連結する
	*/
	void LinkDrawBuffer();

	/**
	* @brief クリアフラグ変更関数
	*/
	void IsClear();


private:
	//! 初期化用バッファ
	DrawType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

	//! 描画用バッファ
	DrawType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];

	//! 描画バッファ連結変数
	std::string m_draw_string;

	//! クリアフラグ
	bool m_is_game_clear;
};

#endif
