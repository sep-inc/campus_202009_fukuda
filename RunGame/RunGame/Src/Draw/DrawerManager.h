#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

/**
* @file DrawerManager.h
* @brief DrawerManagerクラスのヘッダ
*/

#include "DrawerBase.h"
#include "../Definition.h"

/**
* @class DrawerManager
* @brief Drawerクラスをゲームごとに切り替えるシングルトンクラス
*/
class DrawerManager {
public:
	static DrawerManager* Instance();

	/**
	* @brief Drawerクラスの生成関数
	* 指定されたゲームごとのDrawerクラスを生成する　※現在は1種類のみの生成
	*/
	void CreateDrawer();

	/**
	* @brief Drawerクラスの破棄関数
	*/
	void DeleteDrawer();

	//! Draewrクラスのポインタ
	DrawerBase* m_p_drawer;

private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;

};

#endif
