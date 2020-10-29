#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_

#include "../AllDefinition.h"
#include "../Draw/Drawers/DrawerBase.h"

/**
* @class SceneBase
* @brief 各Sceneの基底クラス
*/
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	//! 更新処理関数
	virtual void Update() = 0;

	//! 描画処理関数
	virtual void Draw(DrawerBase* drawer_) = 0;

	/**
	* @brief ゲーム開始処理関数
	*
	* @return bool Spaceキー入力でtrue
	*/
	virtual bool GameStart();

	/**
	* @brief 終了処理の選択関数
	* 入力情報に従って処理を行う
	*
	* @return bool 選択が決定したらtrue
	*/
	virtual bool SelectGameEnd();

	inline SceneType GetNextScene()const { return m_next_scene; }

	/**
	* @brief シーンの終了フラグを返す関数
	*/
	bool IsGameFinish();

protected:
	SceneType m_next_scene;		//! 次のシーン
	bool m_is_scene_finish;		//! シーン終了フラグ

};


#endif
