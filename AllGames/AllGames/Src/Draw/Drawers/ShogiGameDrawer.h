#ifndef SHOGIGAME_DRAWER_H_
#define SHOGIGAME_DRAWER_H_

#include "DrawerBase.h"

/**
* @class ShogiGameDrawer
* @brief SyogiGameで使用するDrawer
*/
class ShogiGameDrawer : public DrawerBase
{
public:
	ShogiGameDrawer();
	~ShogiGameDrawer();

	/**
	* @brief 描画関数
	*/
	void Draw()override;

	/**
	* @brief 描画情報クリア関数
	*/
	void Clear()override;

	//! 使用しない
	void SetDrawBuffer(Vec2_Int pos_, char* string_)override;

	/**
	* @brief 描画用文字列に情報をセットする関数
	*/
	void SetDrawMapString(std::string map_);

	/**
	* @brief インスタンス生成関数
	*/
	static DrawerBase* InstanceSelectGameDrawer();

private:
	//! 使用しない
	void BufferClear()override;

	//! 使用しない
	void LinkDrawBuffer();

};


#endif
