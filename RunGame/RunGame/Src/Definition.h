#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! Runゲームの描画用バッファサイズ
#define RUNGAME_DRAW_BUFFER_WIDTH  11
#define RUNGAME_DRAW_BUFFER_HEIGHT 10

//! 描画する文字列のサイズ
#define DRAW_STRING_SIZE 8

/* 列挙群 */

/* 構造体群 */

struct Vec2
{
	int m_x;
	int m_y;
};

#endif
