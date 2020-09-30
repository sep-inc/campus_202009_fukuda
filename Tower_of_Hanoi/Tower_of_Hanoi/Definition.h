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
#define DRAW_BUFFER_WIDTH  21
#define DRAW_BUFFER_HEIGHT 7


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
	Type_Disk		//! 円盤
};


#endif

