#ifndef ALL_DEFINITION_H_
#define ALL_DEFINITION_H_

/**
* @file AllDefinition.h
* @brief 全てのゲームで使用する定義をまとめたヘッダ
*/

#include <cinttypes>

/* ゲームの総数 */
#define ALL_GAME_NUM 6


/* 列挙群 */

//! ゲームの種類
enum class SceneType : uint8_t
{
	SELECT_GAME,	//! ゲーム選択シーン
	TIT_TAT_TOE,	//! マルバツゲーム
	TOWER_OF_HANOI,	//! ハノイの塔
	TRON,			//! トロン
	PACMEN,			//! パックマン
	RUN_GAME,		//! Runゲーム
	SHOGI,			//! 将棋

	MAX_SCENE_NUM,	//! シーンの最大数
	TYPE_NONE,		//! タイプ無し

};

//! キーの種類
enum KeyType
{
	NULL_KEY	= 0x00,		//! NULL
	ENTER_KEY	= 0x0d,		//! Enter
	SO_KEY		= 0x0e,		//! シフトアウト
	ESCAPE_KEY  = 0x1b,		//! Esc
	SPACE_KEY	= 0x20,		//! Space

	LEFT_KEY	= 0x4b,		//! 左矢印キー
	RIGHT_KEY	= 0x4d,		//! 右矢印キー
	UP_KEY		= 0x48,		//! 上矢印キー
	DOWN_KEY	= 0x50,		//! 下矢印キー

	ONE_KEY		= 0x31,		//! 1キー
	TWO_KEY		= 0x32,		//! 2キー
	THREE_KEY	= 0x33,		//! 3キー
	FOUR_KEY	= 0x34,		//! 4キー
	FIVE_KEY	= 0x35,		//! 5キー

	A_KEY		= 0x41,		//! Aキー
	B_KEY		= 0x42,		//! Bキー
	C_KEY		= 0x43,		//! Cキー
	D_KEY		= 0x44		//! Dキー
};


#endif
