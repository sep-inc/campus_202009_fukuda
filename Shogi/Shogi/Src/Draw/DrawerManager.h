#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

/**
* @file DrawerManager.h
* @brief DrawerManagerクラスのヘッダ
*/

#include "DrawerBase.h"

/*
* @class DrawerManager
* @brief ゲームごとの描画クラスの管理を行うクラス
*/
class DrawerManager {
public:
	static DrawerManager* Instance();

	/**
	* @brief Drawerクラス生成関数
	* 各ゲームごとのDrawerクラスを生成する
	*/
	void CreateDrawer();

	/**
	* @brief 生成したDrawerクラスのポインタを返す
	*/
	inline DrawerBase* GetDrawerInstance()const { return m_drawer; }

private:
	DrawerBase* m_drawer;

private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;

};

#endif
