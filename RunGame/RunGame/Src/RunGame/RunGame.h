#ifndef RUNGAME_H_
#define RUNGAME_H_

/**
* @file RunGame.h
* @brief RunGameクラスのヘッダ
*/

#include "../GameMap/GameMap.h"
#include "../FrameCounter/FrameCounter.h"
#include "../Player/Player.h"
#include "../Draw/DrawerBase.h"

/**
* @class RunGame
* @brief Runゲーム本体
*/
class RunGame
{
public:
	static RunGame* Instance();

	/**
	* @breif ゲーム本体の更新関数
	*/
	void Update();

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_);

	/**
	* @brief 勝敗情報のセット関数
	*/
	void SetResult(DrawerBase* drawer_);

	/**
	* @brief ゲーム終了判定関数
	* @return bool ゲーム終了ならtrue
	*/
	inline bool IsGameFinish()const { return m_is_game_finish; }


public:
	//! 各オブジェクトのポインタ変数群
	GameMap* m_p_map;
	FrameCounter* m_p_frame_counter;
	Player* m_p_player;

private:
	RunGame();
	~RunGame();

	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DestroyObjects();

	static RunGame* p_instance;


private:
	//! 処理ステップの種類
	enum class RunGameStep : int {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_END			//! 終了ステップ
	};

	//! 勝敗の種類
	enum class RunGameResult : int {
		NONE,	//! なし
		WIN,	//! 勝利
		LOSE	//! 敗北
	};

	RunGameStep m_step;		//! 現在のステップ

	RunGameResult m_result;	//! 勝敗状況
	bool m_is_game_finish;	//! ゲーム終了フラグ

};

#endif

