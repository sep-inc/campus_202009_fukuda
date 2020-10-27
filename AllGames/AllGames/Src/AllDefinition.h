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
	TYPE_NONE,		//! タイプ無し
	SELECT_GAME,	//! ゲーム選択シーン
	TIT_TAT_TOE,	//! マルバツゲーム
	TOWER_OF_HANOI,	//! ハノイの塔
	TRON,			//! トロン
	PACMEN,			//! パックマン
	RUN_GAME,		//! Runゲーム
	SHOGI			//! 将棋

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
	DOWN_KEY	= 0x50		//! 下矢印キー
};


#endif
