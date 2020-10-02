#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>


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

#endif

