#ifndef PACMENGAME_DEFINITION_H_
#define PACMENGAME_DEFINITION_H_

/**
* @file PacMenGameDefinition.h
* @brief PacMenGameで使用する定義をまとめたヘッダ
*/

#include "../../Utility/Utility.h"
#include <cinttypes>

/* 定数群 */

//! パックマンの描画用バッファサイズ
#define PACMEN_DRAW_WIDTH  13
#define PACMEN_DRAW_HEIGHT 13

//! 描画する文字列のサイズ
#define PACMEN_DRAW_STRING_SIZE 8


//! プレイヤーの初期座標
#define PACMEN_PLAYER_INIT_POS_X 3
#define PACMEN_PLAYER_INIT_POS_Y 6
//! キャラクターの移動可能範囲の最大数
#define PACMEN_CAN_CHARACTER_MOVE_POS_LIST 4

//! 生成可能場所の最大数
#define PACMEN_CAN_CREATE_POS_NUM 121

//! モンスターの生成数
#define PACMEN_MONSTER_NUM 3

//! アイテムの生成数
#define PACMEN_ITEM_NUM 5


/* 列挙群 */

//! ゲームオブジェクトの種類
enum class PacMenObjectType : uint8_t {
	TYPE_EMPTY,	//! 種類無し
	PLAYER,		//! プレイヤー
	MONSTER,	//! モンスター
	ITEM,		//! アイテム
	WALL,		//! 壁

	MAX_TYPE
};

//! 勝敗の種類
enum class PacMenResult : uint8_t {
	NONE,
	PLAYER_WIN,
	PLAYER_LOSE
};


/* 構造体群 */

//! ゲームオブジェクトの必要パラメータ
struct PacMenObjectParam {
	Vec2_Int m_pos;								//! 現在の座標
	PacMenObjectType m_type;				//! オブジェクトの種類
	char m_draw_string[PACMEN_DRAW_STRING_SIZE];	//! 描画文字

	PacMenObjectParam() :
		m_pos{},
		m_type(PacMenObjectType::TYPE_EMPTY),
		m_draw_string("　")
	{}
};

#endif
