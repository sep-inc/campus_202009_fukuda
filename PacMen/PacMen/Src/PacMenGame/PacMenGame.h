#ifndef PACMEN_GAME_H_
#define PACMEN_GAME_H_

/**
* @file PacMenGame.h
* brief PacMenGameクラスのヘッダ
*/

#include "../GameObject/PacMenGameObject.h"
#include "../GameMap/GameMap.h"
#include <vector>

/**
* @class PacMenGame
* @brief ゲーム本体
*/
class PacMenGame 
{
public:
	static PacMenGame* Instance();

	/**
	* @brief ゲーム本体の更新関数
	*/
	void Update();

	/**
	* @brief ゲームマップの書き込み関数
	*/
	void Draw();

	/**
	* @brief 勝敗情報のセット関数
	*/
	void SetResult();

	/**
	* @brief ゲーム終了判定関数
	* @return trueでゲーム終了
	*/
	inline bool IsGameFinish()const { return m_is_game_finish; }

public:
	//! 各オブジェクトのポインタ変数群
	GameMap* m_p_game_map;
	PacMenGameObject* m_p_player;
	std::vector<PacMenGameObject*> m_p_monsters;
	PacMenGameObject* m_p_items[PACMEN_ITEM_NUM];

private:
	PacMenGame();
	~PacMenGame();

	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DestroyObjects();

	bool CheckHitPlayer();

	bool CheckHitItems();

	static PacMenGame* p_instance;

private:
	//! 処理ステップ
	enum class PacMenGameStep {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_END			//! 終了ステップ
	};

	PacMenGameStep m_step;	//! 現在のステップ

	PacMenResult m_result;	//! 勝敗状況
	int m_item_delete_counter;

	bool m_is_game_finish;	//! ゲーム終了フラグ

};


#endif

