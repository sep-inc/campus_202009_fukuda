#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

#include "DrawerBase.h"
#include "../TetrisDefinition.h"

/**
* @class DrawerManager
* @brief Drawerクラスをゲームごとに切り替えるシングルトンクラス
*/
class DrawerManager
{
public:
	static DrawerManager* Instance();

	/**
	* @brief 描画関数
	*/
	void Draw();

	/**
	* @brief 描画情報クリア関数
	*/
	void Clear();

	/**
	* @brief Drawerのインスタンスを返す関数
	*/
	inline DrawerBase* GetDrawerInstance()const { return m_p_drawer; }

	/**
	* @brief Drawerクラス生成関数
	*
	* @param game_type_ 生成するDrawerの種類
	*/
	void CreateDrawer();

	/**
	* @brief Drawerクラス破棄関数
	*/
	void DestroyDrawer();


private:
	//! Drawerクラスのポインタ変数
	DrawerBase* m_p_drawer;


private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;
};

#endif
