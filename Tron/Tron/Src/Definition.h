#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! トロンの描画用バッファサイズ
#define TRON_DRAW_BUFFER_WIDTH  20
#define TRON_DRAW_BUFFER_HEIGHT 14

//! 描画する文字列のサイズ
#define DRAW_STRING_SIZE 8

//! プレイヤーの初期位置
#define INIT_PLAYER_POS_X 3
#define INIT_PLAYER_POS_Y 3

//! エネミーの初期位置
#define INIT_ENEMY_POS_X 15
#define INIT_ENEMY_POS_Y 8

//! 移動可能範囲リストの配列のサイズ
#define CAN_MOVE_LIST_SIZE 4


/* 列挙群 */

//! ゲームの種類
enum class GameType : uint8_t
{
	TYPE_NONE,	//! タイプ無し
	TRON,		//! トロン

	MAX_TYPE
};

//! マップ上のオブジェクトの種類
enum class ObjectType : uint8_t
{
	TYPE_EMPTY,	//! 空
	PLAYER,		//! プレイヤー
	ENEMY,		//! エネミー
	FRAME,		//! 外枠

	MAX_TYPE
};


/* 構造体群 */

struct Vec2
{
	int m_x;
	int m_y;
};

//! キャラクターに必要なパラメータ群
struct CharacterParam
{
	ObjectType m_type;						//! 自身の種類
	char m_draw_string[DRAW_STRING_SIZE];	//! 描画の文字

	//! 空で初期化
	CharacterParam() :
		m_type(ObjectType::TYPE_EMPTY),
		m_draw_string("　")
	{}
};



#endif

