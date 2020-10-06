#ifndef DEFINITION_H_
#define DEFINITION_H_

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

#include <cinttypes>


struct Vec2 {
	int m_x;
	int m_y;
};

//! 処理ステップの種類
enum class Step :uint8_t {
	Initialize,	//! 初期化ステップ
	Update,		//! 更新ステップ
	End			//! 解放ステップ
};

//! オブジェクトの種類
enum class ObjectType :uint8_t {
	Type_Empty,		//! タイプなし
	King1,			//! 玉1
	Pawn1,			//! 歩1
	GoldGeneral1,	//! 金1
	Knight1,		//! 桂馬1
	King2,			//! 玉2
	Pawn2,			//! 歩2
	GoldGeneral2,	//! 金2
	Knight2			//! 桂馬2
};

//! プレイヤータイプ
enum class PlayerType :uint8_t {
	Type_None,
	Player1,
	Player2
};

//! ゲーム終了結果の種類
enum class ResultType :uint8_t {
	Result_None,	//! 結果無し
	Win_Player1,	//! プレイヤー1の勝利
	Win_Player2		//! プレイヤー2の勝利
};

//! 描画バッファのサイズ
#define DRAW_BUFFER_WIDTH  10
#define DRAW_BUFFER_HEIGHT 12

//! 将棋盤のサイズ
#define SHOGI_BOARD_WIDTH  4
#define SHOGI_BOARD_HEIGHT 5

//! 駒の動ける範囲のサイズ
#define MOVE_RANGE_WIDTH  3
#define MOVE_RANGE_HEIGHT 3

#endif

