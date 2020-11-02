#ifndef TOWER_OF_HANOI_DRAWER_H_
#define TOWER_OF_HANOI_DRAWER_H_

#include "DrawerBase.h"
#include "../../Scenes/TowerOfHanoiGameScene/TowerOfHanoiDefinition.h"

/**
* @class TowerOfHanoiDrawer
* @brief TowerOfHanoiで使用するDrawer
*/
class TowerOfHanoiDrawer : public DrawerBase
{
public:
	TowerOfHanoiDrawer();
	~TowerOfHanoiDrawer();

	/**
	* @brief 描画用バッファのセット関数
	* @param pos_ セットしたい位置
	* @param string_ セットする文字列
	*/
	void SetDrawBuffer(Vec2_Int pos_, char* string_)override;


private:
	/**
	* @brief 描画用バッファのクリア関数
	*/
	void BufferClear()override;

	/**
	* @brief 描画バッファを連結して１つの文字列へ変換する関数
	*/
	void LinkDrawBuffer()override;

private:
	//! 初期化用バッファ
	char m_blank_buffer[TOWER_OF_HANOI_DRAW_HEIGHT][TOWER_OF_HANOI_DRAW_WIDTH][TOWER_OF_HANOI_DRAW_STRING_SIZE];
	//! 描画用バッファ
	char m_draw_buffer[TOWER_OF_HANOI_DRAW_HEIGHT][TOWER_OF_HANOI_DRAW_WIDTH][TOWER_OF_HANOI_DRAW_STRING_SIZE];

};

#endif