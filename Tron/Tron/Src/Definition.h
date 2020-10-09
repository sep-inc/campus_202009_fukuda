#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>

//! トロンの描画用バッファサイズ
#define TRON_DRAW_BUFFER_WIDTH  20
#define TRON_DRAW_BUFFER_HEIGHT 14

//! 描画する文字列のサイズ
#define DRAW_STRING_SIZE 8

struct Vec2
{
	int m_x;
	int m_y;
};

//! ゲームの種類
enum class GameType : uint8_t 
{
	TYPE_NONE,	//! タイプ無し
	TRON,		//! トロン

	MAX_TYPE
};

#endif

