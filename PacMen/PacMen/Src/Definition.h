#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

#define SAFE_DELETE(p) if(p != nullptr){delete (p); (p) = nullptr;}

//! パックマンの描画用バッファサイズ
#define PACMEN_DRAW_BUFFER_WIDTH  13
#define PACMEN_DRAW_BUFFER_HEIGHT 13

//! 描画する文字列のサイズ
#define DRAW_STRING_SIZE 8

//! ゲームに必要なオブジェクトの数
//! キャラクター
#define PACMEN_CHARACTER_NUM 4
//! アイテム
#define PACMEN_ITEM_NUM 5

//! プレイヤーの初期座標
#define PLAYER_INIT_POS_WIDTH 2
#define PLAYER_INIT_POS_HEIGHT 5


/* 列挙群 */

//! ゲームオブジェクトの種類
enum class PacMenObjectType: uint8_t {
	TYPE_EMPTY,	//! 種類無し
	PLAYER,		//! プレイヤー
	MONSTER,	//! モンスター
	ITEM,		//! アイテム
	WALL,		//! 壁

	MAX_TYPE
};

/* 構造体群 */

struct Vec2
{
	int m_x;
	int m_y;
};

//! ゲームオブジェクトの必要パラメータ
struct PacMenObjectParam {
	Vec2 m_pos;
	PacMenObjectType m_type;
	char m_draw_string[DRAW_STRING_SIZE];

	PacMenObjectParam():
		m_pos{},
		m_type(PacMenObjectType::TYPE_EMPTY),
		m_draw_string("　")
	{}
};


#endif
