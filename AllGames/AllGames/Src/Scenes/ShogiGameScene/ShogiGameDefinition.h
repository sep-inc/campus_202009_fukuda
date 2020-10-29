#ifndef SHOGIGAME_DEFINITION_H_
#define SHOGIGAME_DEFINITION_H_

/**
* @file ShogiGameDefinition.h
* @brief ShogiGameで使用する定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! 描画バッファのサイズ
#define SHOGIGAME_DRAW_WIDTH  10
#define SHOGIGAME_DRAW_HEIGHT 12

//! 将棋盤のサイズ
#define SHOGI_BOARD_WIDTH  4
#define SHOGI_BOARD_HEIGHT 5

//! 駒の動ける範囲のサイズ
#define SHOGIGAME_MOVE_RANGE_WIDTH  5
#define SHOGIGAME_MOVE_RANGE_HEIGHT 3


/* 列挙群 */

//! オブジェクトの種類
enum class ShogiGameObjectType :uint8_t {
	TYPE_EMPTY,		//! タイプなし
	KING1,			//! 玉1
	PAWN1,			//! 歩1
	GOLD_GENERAL1,	//! 金1
	KNIGHT1,		//! 桂馬1
	KING2,			//! 玉2
	PAWN2,			//! 歩2
	GOLD_GENERAL2,	//! 金2
	KNIGHT2,		//! 桂馬2

	MAX_TYPE_NUM
};

//! プレイヤータイプ
enum class ShogiPlayerType :uint8_t {
	TYPE_NONE,
	PLAYER1,
	PLAYER2
};

//! ゲーム終了結果の種類
enum class ShogiResultType :uint8_t {
	NONE_RESULT,	//! 結果無し
	WIN_PLAYER1,	//! プレイヤー1の勝利
	WIN_PLAYER2		//! プレイヤー2の勝利
};


#endif