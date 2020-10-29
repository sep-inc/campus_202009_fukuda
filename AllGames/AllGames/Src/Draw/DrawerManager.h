#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

#include "Drawers/DrawerBase.h"
#include "../AllDefinition.h"

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
	* @brief Drawerクラス選択関数
	* 指定されたゲームに応じて、Drawerを生成、破棄する関数
	*
	* @param game_type_ 生成するDrawerのゲームの種類
	*/
	void SelectDrawer(SceneType game_type_);

	/**
	* @brief Drawerのインスタンスを返す関数
	*/
	inline DrawerBase* GetDrawerInstance()const { return m_p_drawer; }


private:
	/**
	* @brief Drawerクラス生成関数
	*
	* @param game_type_ 生成するDrawerの種類
	*/
	void CreateDrawer(SceneType game_type_);

	/**
	* @brief Drawerクラス破棄関数
	*/
	void DestroyDrawer();

	//! 各Drawerがインスタンスを返す関数のポインタ配列
	static DrawerBase* (*s_func_ptr_array[static_cast<int>(SceneType::MAX_SCENE_NUM)])();

private:
	//! Drawerクラスのポインタ変数
	DrawerBase* m_p_drawer;


private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;
};

#endif
