#ifndef TRONGAME_DEFINITION_H_
#define TRONGAME_DEFINITION_H_

/**
* @file TronGameDefinition.h
* @brief TronGameで使用する定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! トロンの描画用バッファサイズ
#define TRON_DRAW_WIDTH  20
#define TRON_DRAW_HEIGHT 14

//! 描画する文字列のサイズ
#define TRON_DRAW_STRING_SIZE 8

//! プレイヤーの初期位置
#define TRON_INIT_PLAYER_POS_X 3
#define TRON_INIT_PLAYER_POS_Y 3

//! エネミーの初期位置
#define TRON_INIT_ENEMY_POS_X 15
#define TRON_INIT_ENEMY_POS_Y 8

//! 移動可能範囲リストの配列のサイズ
#define TRON_CAN_MOVE_LIST_SIZE 4


/* 列挙群 */

//! マップ上のオブジェクトの種類
enum class TronGameObjectType : uint8_t
{
	TYPE_EMPTY,	//! 空
	PLAYER,		//! プレイヤー
	ENEMY,		//! エネミー
	FRAME,		//! 外枠

	MAX_TYPE
};


/* 構造体群 */

//! キャラクターに必要なパラメータ群
struct TronCharacterParam
{
	TronGameObjectType m_type;						//! 自身の種類
	char m_draw_string[TRON_DRAW_STRING_SIZE];	//! 描画の文字

	//! 空で初期化
	TronCharacterParam() :
		m_type(TronGameObjectType::TYPE_EMPTY),
		m_draw_string("　")
	{}
};

#endif
