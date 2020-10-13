#ifndef TRON_GAME_H_
#define TRON_GAME_H_

/**
* @file TronGame.h
* @brief TronGameクラスのヘッダ
*/

#include "../Character/CharacterBase.h"
#include "../GameMap/GameMap.h"

/**
* @class TronGame
* @brief ゲーム本体
*/
class TronGame
{
public:
	static TronGame* Instance();

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
	CharacterBase* m_p_player;
	CharacterBase* m_p_enemy;
	GameMap* m_p_game_map;


private:
	TronGame();
	~TronGame();

	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DestroyObjects();
	
	static TronGame* p_instance;


private:
	//! 処理ステップ
	enum class TronGameStep {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_END			//! 終了ステップ
	};

	TronGameStep m_step;	//! 現在のステップ

	bool m_cannot_move_player;	//! プレイヤーが動けなくなったかどうか
	bool m_cannot_move_enemy;	//! エネミーが動けなくなったかどうか
	bool m_is_game_finish;		//! ゲーム終了フラグ
};


#endif

