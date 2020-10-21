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

//! マップのサイズ
#define RUNGAME_MAP_WIDTH  50
#define RUNGAME_MAP_HEIGHT 10

//! マップのパーツのサイズ
#define RUNGAME_MAP_PARTS_WIDTH 5

//! マップのパーツの数
#define RUNGAME_MAP_PARTS_NUM 4

/* 列挙群 */

//! オブジェクトの種類
enum class ObjectType : uint8_t
{
	TYPE_NONE,	//! タイプ無し
	PLAYER,		//! プレイヤー
	GROUND,		//! 地面

	MAX_TYPE
};


/* 構造体群 */

struct Vec2
{
	int m_x;
	int m_y;
};

//! オブジェクトのパラメータ
struct ObjectParam
{
	ObjectType m_type;						//! 自身の種類
	char m_draw_string[DRAW_STRING_SIZE];	//! 描画文字列

	ObjectParam() :
		m_type(ObjectType::TYPE_NONE),
		m_draw_string("　")
	{}
};

#endif
