#ifndef RUN_GAME_DEFINITION_H_
#define RUN_GAME_DEFINITION_H_

/**
* @file RunGameDefinition.h
* @brief RunGameで使用する定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! Runゲームの描画用バッファサイズ
#define RUNGAME_DRAW_WIDTH  11
#define RUNGAME_DRAW_HEIGHT 10

//! 描画する文字列のサイズ
#define RUNGAME_DRAW_STRING_SIZE 8

//! マップのサイズ
#define RUNGAME_MAP_WIDTH  50
#define RUNGAME_MAP_HEIGHT 10

//! マップのパーツのサイズ
#define RUNGAME_MAP_PARTS_WIDTH 5

//! マップのパーツの数
#define RUNGAME_MAP_PARTS_NUM 4

//! 更新フレーム数
#define UPDATE_FRAME_NUM 5

//! プレイヤーの初期位置
#define RUNGAME_PLAYER_INIT_POS_X 1
#define RUNGAME_PLAYER_INIT_POS_Y 5

//! プレイヤーの移動速度
#define RUNGAME_PLAYER_MOVE_SPEED 1

//! プレイヤーのジャンプの高さ
#define RUNGAME_PLAYER_JUMP_HEIGHT 2


/* 列挙群 */

//! オブジェクトの種類
enum class RunGameObjectType : uint8_t
{
	TYPE_NONE,	//! タイプ無し
	PLAYER,		//! プレイヤー
	GROUND,		//! 地面

	MAX_TYPE
};


/* 構造体群 */

//! オブジェクトのパラメータ
struct RunGameObjectParam
{
	RunGameObjectType m_type;						//! 自身の種類
	char m_draw_string[RUNGAME_DRAW_STRING_SIZE];	//! 描画文字列

	RunGameObjectParam() :
		m_type(RunGameObjectType::TYPE_NONE),
		m_draw_string("　")
	{}
};

#endif
