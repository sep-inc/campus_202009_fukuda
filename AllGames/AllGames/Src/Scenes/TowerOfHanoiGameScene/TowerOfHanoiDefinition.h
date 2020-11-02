#ifndef TOWER_OF_HANOI_DEFINITION_H_
#define TOWER_OF_HANOI_DEFINITION_H_

/**
* @file TowerOfHanoiDefinition.h
* @brief TowerOfHanoiで使用する定義をまとめたヘッダ
*/

#include <cinttypes>

/* 定数群 */

//! 杭のサイズ
#define TOWER_OF_HANOI_PILE_SIZE 3

//! 杭の数
#define TOWER_OF_HANOI_PILE_NUM 3

//! 描画バッファのサイズ
#define TOWER_OF_HANOI_DRAW_WIDTH  19
#define TOWER_OF_HANOI_DRAW_HEIGHT 6

//! 描画する文字列のサイズ
#define TOWER_OF_HANOI_DRAW_STRING_SIZE 8

//! 描画バッファ上での左杭のX座標
#define TOWER_OF_HANOI_LEFT_PILE_POS_X 1

//! 描画バッファ上での真ん中杭のX座標
#define TOWER_OF_HANOI_CENTER_PILE_POS_X 7

//! 描画バッファ上での右杭のX座標
#define TOWER_OF_HANOI_RIGHT_PILE_POS_X 13

//! 描画バッファ上での杭のY座標
#define TOWER_OF_HANOI_PILE_POS_Y 2


/* 列挙群 */

/**
* @brief 円盤の種類
* 上から順にサイズの小さい順
*/
enum class TowerOfHanoiDiskType :uint8_t {
	DISK_EMPTY,		//! 空
	SMALL_DISK,		//! ディスク小
	NORMAL_DISK,	//! ディスク中
	LARGE_DISK		//! ディスク大
};


//! 描画タイプ
enum class TowerOfHanoiObjectType :uint8_t {
	TYPE_EMPTY,	//! 空白
	PILE,		//! 杭
	DISK,		//! 円盤
	NUMBER1,	//! 1
	NUMBER2,	//! 2
	NUMBER3		//! 3
};

#endif