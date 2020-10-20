#ifndef RUN_GAME_DRAWER_H_
#define RUN_GAME_DRAWER_H_

/**
* @file PacMenDrawer.h
* @brief PacMenDrawerクラスのヘッダ
*/

#include "DrawerBase.h"

/**
* @class PacMenDrawer
* @brief PacMenゲームのDrawerクラス
*/
class RunGameDrawer : public DrawerBase
{
public:
	RunGameDrawer();
	~RunGameDrawer();

	/**
	* @brief 描画用バッファのセット関数
	* @param pos_ セットしたい位置
	* @param string_ セットする文字列
	*/
	void SetDrawBuffer(Vec2 pos_, char* string_)override;


private:
	/**
	* @brief 描画用バッファのクリア関数
	*/
	void BufferClear()override;

	/**
	* @brief 描画バッファを連結して１つの文字列へ変換する関数
	*/
	void LinkDrawBuffer()override;


private:
	//! 初期化用バッファ
	char m_blank_buffer[RUNGAME_DRAW_BUFFER_HEIGHT][RUNGAME_DRAW_BUFFER_WIDTH][DRAW_STRING_SIZE];
	//! 描画用バッファ
	char m_draw_buffer[RUNGAME_DRAW_BUFFER_HEIGHT][RUNGAME_DRAW_BUFFER_WIDTH][DRAW_STRING_SIZE];


};

#endif

