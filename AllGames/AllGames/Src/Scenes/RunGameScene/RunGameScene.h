#ifndef RUNGAME_SCENE_H_
#define RUNGAME_SCENE_H_

#include "../SceneBase.h"
#include "RunGameMap/RunGameMap.h"
#include "RunGamePlayer/RunGamePlayer.h"
#include "FrameCounter/FrameCounter.h"
#include "../../Draw/Drawers/DrawerBase.h"

/**
* @class RunGame
* @brief Runゲーム本体
*/
class RunGameScene : public SceneBase
{
public:
	RunGameScene();
	~RunGameScene();

	/**
	* @breif ゲーム本体の更新関数
	*/
	void Update()override;

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief 勝敗情報のセット関数
	*/
	void SetResult(DrawerBase* drawer_);

	/**
	* @brief インスタンス生成関数
	*/
	static SceneBase* InstanceRunGameScene();


public:
	//! 各オブジェクトのポインタ変数群
	RunGameMap* m_p_map;
	FrameCounter* m_p_frame_counter;
	RunGamePlayer* m_p_player;

private:
	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DestroyObjects();

	/**
	* @brief ゲーム開始処理関数
	*
	* @return bool Spaceキー入力でtrue
	*/
	bool StartRunGame();

	/**
	* @brief 終了処理の選択関数
	* 入力情報に従って処理を行う
	*/
	void SelectGameEnd();


private:
	//! 処理ステップの種類
	enum class RunGameSceneStep : int {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_GAME_START,	//! ゲームの開始ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_GAME_END,		//! ゲームの終了ステップ
		STEP_END			//! 終了ステップ
	};

	//! 勝敗の種類
	enum class RunGameResult : int {
		NONE,	//! なし
		WIN,	//! 勝利
		LOSE	//! 敗北
	};

	RunGameSceneStep m_step;		//! 現在のステップ

	RunGameResult m_result;	//! 勝敗状況
	
};

#endif

