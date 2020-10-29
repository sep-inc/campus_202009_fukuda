#ifndef PACMEN_GAME_SCENE_H_
#define PACMEN_GAME_SCENE_H_

#include "../SceneBase.h"
#include "../../Draw/Drawers/DrawerBase.h"
#include "PacMenGameObject/PacMenGameObject.h"
#include "PacMenGameMap/PacMenGameMap.h"
#include <vector>

/**
* @class PacMenGame
* @brief ゲーム本体
*/
class PacMenGameScene : public SceneBase
{
public:
	PacMenGameScene();
	~PacMenGameScene();

	/**
	* @brief ゲーム本体の更新関数
	*/
	void Update()override;

	/**
	* @brief ゲームマップの書き込み関数
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief 勝敗情報のセット関数
	*/
	void SetResult(DrawerBase* drawer_);

	/**
	* @brief ゲーム終了判定関数
	* @return trueでゲーム終了
	*/
	inline bool IsGameFinish()const { return m_is_game_finish; }

	/**
	* @brief インスタンス生成関数
	*/
	static SceneBase* InstancePacMenGameScene();

public:
	//! 各オブジェクトのポインタ変数群
	PacMenGameMap* m_p_game_map;
	PacMenGameObject* m_p_player;
	PacMenGameObject* m_p_monsters[PACMEN_MONSTER_NUM];
	PacMenGameObject* m_p_items[PACMEN_ITEM_NUM];

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
	bool StartPacMen();

	/**
	* @brief 終了処理の選択関数
	* 入力情報に従って処理を行う
	*/
	void SelectGameEnd();

	/**
	* @brief プレイヤーのヒット時の処理関数
	* @return bool プレイヤーの死亡フラグが立ったらtrue
	*/
	bool CheckHitPlayer();

	/**
	* @brief アイテムのヒット時の処理関数
	* @return bool 全アイテムが消えたらtrue
	*/
	bool CheckHitItems();


private:
	//! 処理ステップ
	enum class PacMenGameSceneStep {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_GAME_START,	//! ゲームの開始ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_GAME_END,		//! ゲームの終了ステップ
		STEP_END			//! 終了ステップ
	};

	PacMenGameSceneStep m_step;	//! 現在のステップ

	PacMenResult m_result;		//! 勝敗状況
	int m_item_delete_counter;	//! アイテム取得数
	bool m_is_game_finish;	//! ゲーム終了フラグ

};

#endif

