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
