#ifndef DEFINITION_H_
#define DEFINITION_H_

#include <cinttypes>

/**
* @file Definition.h
* @brief 定義をまとめたヘッダ
*/

//! 杭のサイズ
#define PILE_SIZE 3

//! 杭の数
#define PILE_NUM 3

//! 描画バッファのサイズ
#define DRAW_BUFFER_WIDTH  19
#define DRAW_BUFFER_HEIGHT 6

//! 描画バッファ上での左杭のX座標
#define LEFT_PILE_POS_X 1

//! 描画バッファ上での真ん中杭のX座標
#define CENTER_PILE_POS_X 7

//! 描画バッファ上での右杭のX座標
#define RIGHT_PILE_POS_X 13

//! 描画バッファ上での杭のY座標
#define PILE_POS_Y 2


//! 処理ステップの種類
enum class Step :uint8_t {
	Step_Initialize,	//! 初期化ステップ
	Step_Update,		//! 更新ステップ
	Step_End			//! 解放ステップ
};


/**
* @brief 円盤の種類
* 上から順にサイズの小さい順
*/
enum class DiskType :uint8_t {
	Disk_Empty,		//! 空
	Small_Disk,		//! ディスク小
	Normal_Disk,	//! ディスク中
	Large_Disk		//! ディスク大
};


//! 描画タイプ
enum class DrawType :uint8_t {
	Type_Empty,		//! 空白
	Type_Pile,		//! 杭
	Type_Disk,		//! 円盤
	Type_Number1,	//! 1
	Type_Number2,	//! 2
	Type_Number3	//! 3
};


#endif

