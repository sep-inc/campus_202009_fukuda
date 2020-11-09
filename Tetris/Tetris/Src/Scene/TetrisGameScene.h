#ifndef TETRIS_GAME_SCENE_H_
#define TETRIS_GAME_SCENE_H_

#include "SceneBase.h"
#include "TetrisGameMap/TetrisGameMap.h"

/**
* @class SceneBase
* @brief Tetrisの本体クラス
*/
class TetrisGameScene : public SceneBase
{
public:
	TetrisGameScene();
	~TetrisGameScene();

	/**
	* @brief 更新処理関数
	*/
	void Update()override;

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_)override;


private:
	/**
	* @brief 初期化関数
	*/
	void Init();

	/**
	* @brief ゲームオブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief ゲームオブジェクト破棄関数
	*/
	void DestroyObjects();

private:
	TetrisGameMap* m_p_map;

private:
	//! シーンのステップ
	enum class TetrisGameSceneStep
	{
		STEP_INITIALIZE,
		STEP_GAME_START,
		STEP_UPDATE,
		STEP_GAME_END,
		STEP_END
	};

	TetrisGameSceneStep m_step;

};

#endif
