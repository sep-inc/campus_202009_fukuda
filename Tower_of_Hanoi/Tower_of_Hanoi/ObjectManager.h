#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_
/**
* @file ObjectManager.h
* @brief ObjectManagerクラスのヘッダ
*/


#include "Player.h"
#include "GameStageManager.h"
#include "Input.h"
#include "Drawer.h"


/**
* @class ObjectManager
* @brief ゲームに必要なオブジェクトの生成と破棄を行うシングルトンクラス
*/
class ObjectManager
{
public:
	/**
	* @brief オブジェクトマネージャーを呼び出す関数
	*
	* @return 実体化したオブジェクトマネージャークラスのポインタを返す
	*/
	static ObjectManager* Instance();


	/**
	* @brief オブジェクト生成関数
	* ゲームに必要なオブジェクトを生成し、各ポインタ変数に格納する
	*/
	void CreateObjects();
	

	/**
	* @brief オブジェクト破棄関数
	* 各ポインタ変数に格納されたオブジェクトを破棄する
	*/
	void DeleteObjects();

public:
	Player* m_p_player;
	GameStageManager* m_p_game_stage_manager;
	Input* m_p_input;
	Drawer* m_p_drawer;

private:
	ObjectManager();
	~ObjectManager();

private:
	static ObjectManager* p_instance;
};

#endif