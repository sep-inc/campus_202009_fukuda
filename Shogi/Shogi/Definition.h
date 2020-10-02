#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>


struct Vec2 {
	int m_x;
	int m_y;
};

//! オブジェクトの種類
enum class ObjectType :uint8_t {
	Type_None,		//! タイプなし
	King,			//! 玉
	Pawn,			//! 歩
	GoldGeneral,	//! 金
	Knight			//! 桂馬
};

//! 描画バッファのサイズ
#define DRAW_BUFFER_WIDTH  10
#define DRAW_BUFFER_HEIGHT 12

//! 駒の動ける範囲のサイズ
#define MOVE_RANGE_WIDTH  3
#define MOVE_RANGE_HEIGHT 3

#endif

