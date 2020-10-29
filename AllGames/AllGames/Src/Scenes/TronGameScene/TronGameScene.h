#ifndef TRON_GAME_SCENE_H_
#define TRON_GAME_SCENE_H_

#include "../SceneBase.h"
#include "TronCharacter/TronCharacterBase.h"
#include "TronGameMap/TronGameMap.h"

/**
* @class TronGame
* @brief ゲーム本体
*/
class TronGameScene : public SceneBase
{
public:
	TronGameScene();
	~TronGameScene();

	/**
	* @brief ゲーム本体の更新関数
	*/
	void Update()override;

	/**
	* @brief ゲームマップの書き込み関数
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief 初期化関数
	*/
	void Init();

	/**
	* @brief 勝敗情報のセット関数
	*/
	void SetResult(DrawerBase* drawer_);

	/**
	* @brief インスタンス生成関数
	*/
	static SceneBase* InstanceTronGameScene();


public:
	//! 各オブジェクトのポインタ変数群
	TronCharacterBase* m_p_player;
	TronCharacterBase* m_p_enemy;
	TronGameMap* m_p_game_map;


private:
	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DestroyObjects();


private:
	//! 処理ステップ
	enum class TronGameSceneStep {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_GAME_START,	//! ゲームの開始ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_GAME_END,		//! ゲームの終了ステップ
		STEP_END			//! 終了ステップ
	};

	TronGameSceneStep m_step;	//! 現在のステップ

	bool m_cannot_move_player;	//! プレイヤーが動けなくなったかどうか
	bool m_cannot_move_enemy;	//! エネミーが動けなくなったかどうか
};

#endif

