#ifndef TRON_DRAWER_H_
#define TRON_DRAWER_H_

#include "DrawerBase.h"
#include "../../Scenes/TronGameScene/TronGameDefinition.h"

/**
* @class TronDrawer
* @brief TronゲームのDrawerクラス
*/
class TronDrawer : public DrawerBase
{
public:
	TronDrawer();
	~TronDrawer()override;

	/**
	* @brief 描画用バッファのセット関数
	* @param pos_ セットしたい位置
	* @param string_ セットする文字列
	*/
	void SetDrawBuffer(Vec2_Int pos_, char* string_)override;

	/**
	* @brief インスタンス生成関数
	*/
	static DrawerBase* InstanceTronGameDrawer();


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
	char m_blank_buffer[TRON_DRAW_HEIGHT][TRON_DRAW_WIDTH][TRON_DRAW_STRING_SIZE];
	//! 描画用バッファ
	char m_draw_buffer[TRON_DRAW_HEIGHT][TRON_DRAW_WIDTH][TRON_DRAW_STRING_SIZE];

};

#endif
