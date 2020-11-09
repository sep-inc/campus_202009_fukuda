#ifndef TETRIS_DEFINITION_H_
#define TETRIS_DEFINITION_H_

/**
* @file TetrisDefinition.h
* @brief Tetrisで使用する定義をまとめたヘッダ
*/

#include "Utility/Utility.h"
#include <cinttypes>

/* 定数群 */

//! 描画バッファのサイズ
#define TETRIS_DRAW_WIDTH  12
#define TETRIS_DRAW_HEIGHT 21

//! 描画文字のサイズ
#define TETRIS_DRAW_STRING_SIZE 8

//! テトリスのゲームマップのサイズ
#define TETRIS_GAME_MAP_WIDTH  10
#define TETRIS_GAME_MAP_HEIGHT 23

//! テトリミノのサイズ
#define TETRIMINO_WIDTH  5
#define TETRIMINO_HEIGHT 5


/* 列挙群 */

//! キーの種類
enum KeyType
{
	NULL_KEY = 0x00,		//! NULL
	ENTER_KEY = 0x0d,		//! Enter
	SO_KEY = 0xe0,		//! シフトアウト
	ESCAPE_KEY = 0x1b,		//! Esc
	SPACE_KEY = 0x20,		//! Space

	LEFT_KEY = 0x4b,		//! 左矢印キー
	RIGHT_KEY = 0x4d,		//! 右矢印キー
	UP_KEY = 0x48,		//! 上矢印キー
	DOWN_KEY = 0x50,		//! 下矢印キー

	A_KEY = 0x41,		//! Aキー
	B_KEY = 0x42,		//! Bキー
	C_KEY = 0x43,		//! Cキー
	D_KEY = 0x44		//! Dキー
};

//! Tetrisで使用するオブジェクトの種類
enum class TetrisObjectType : uint8_t
{
	TYPE_NONE,	//! タイプ無し
	EMPTY,		//! 空
	BLOCK,		//! ブロック
	FRAME		//! 枠
};


/* 構造体群 */

struct TetrisObjectParam
{
	Vec2_Float m_pos;			//! 自身の座標
	TetrisObjectType m_type;	//! 自身の種類
	char m_draw_string[TETRIS_DRAW_STRING_SIZE];	//! 描画情報

	TetrisObjectParam():
		m_pos{},
		m_type(TetrisObjectType::EMPTY),
		m_draw_string("　")
	{}
};


#endif

