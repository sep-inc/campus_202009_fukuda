#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "SceneBase.h"
#include "../Draw/Drawers/DrawerBase.h"
#include "../AllDefinition.h"
#include <cinttypes>

/**
* @class SceneManager
* @brief Sceneを管理するクラス
*/
class SceneManager
{
public:
	static SceneManager* Instance();

	/**
	* @brief ゲーム全体の更新関数
	*/
	void Update();

	/**
	* @brief 描画情報をセットする関数
	*/
	void Draw(DrawerBase* drawer_);


private:
	/**
	* @brief シーン生成関数
	* 
	* @param scene_ 生成するシーン 
	*/
	void CreateScene(SceneType scene_);

	/**
	* @brief シーン破棄関数
	*/
	void DestroyScene();

private:
	//! 更新処理のステップ
	enum class SceneStep : uint8_t {
		STEP_INITIALIZE,
		STEP_UPDATE,
		STEP_END
	};

	//! シーンのポインタ変数
	SceneBase* m_p_scene;
	//! 現在のステップ
	SceneStep m_step;
	//! 現在のシーン
	SceneType m_now_scene;

private:
	SceneManager();
	~SceneManager();

	static SceneManager* p_instance;
};

#endif