#ifndef DEFINITION_H_
#define DEFINITION_H_

#include <cstdint>

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/


/**
* @brief 描画用バッファのサイズ
*/
#define DRAW_BUFFER_WIDTH 8
#define DRAW_BUFFER_HEIGHT 8


/**
* @brief ゲームマップのサイズ
*/
#define GAME_MAP_WIDTH 3
#define GAME_MAP_HEIGHT 3


/**
* @brief 最大ターン数
*/
#define MAX_TURN_NUM 4


/**
* @brief ゲームで使用するx,y座標用構造体
*/
struct Vec2 {
	int8_t m_x;
	int8_t m_y;
};


/**
* @brief 描画する際に、判別で使う描画タイプ
*/
enum class DrawType :uint8_t {
	TypeNone,			//! タイプ無し
	Player,				//! プレイヤー：〇
	Enemy,				//! 相手：×
	HalfWidthSpace,		//! 半角スペース
	HalfWidthSpace2,	//! 半角スペース２つ分
	UpperLeft,			//! 左上角：┏
	UpperRight,			//! 右上角：┓
	LowerLeft,			//! 左下角：┗
	LowerRight,			//! 右下角：┛
	UpperMiddle,		//! 上中央：┳
	LowerMiddle,		//! 下中央：┻
	MiddleLeft,			//! 左中央：┣
	MiddleRight,		//! 右中央：┫
	Middle,				//! 中央：╋
	VerticalLine,		//! 縦線：┃
	HorizontalLine,		//! 横線：━
	CharA,				//! 文字：A
	CharB,				//! 文字：B
	CharC,				//! 文字：C
	Num1,				//! 数字：１
	Num2,				//! 数字：２
	Num3,				//! 数字：３

	MAX_TYPE
};


/**
* @brief 処理ステップの列挙
*/
enum class Step :uint8_t {
	Step_Initialize,	//! 初期化ステップ
	Step_Run,			//! 処理ステップ
	Step_End,			//! 解放ステップ			

	MAX_STEP
};


/**
* @brief 勝敗結果の列挙
*/
enum class MatchResult :uint8_t {
	None,	
	Win,	//! 勝利
	Lose,	//! 敗北
	Draw	//! 引き分け
};

#endif

