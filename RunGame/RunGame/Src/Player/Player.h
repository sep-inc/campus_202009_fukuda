#ifndef PLAYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief Playerクラスのヘッダ
*/

#include "../Definition.h"
#include "../GameMap/GameMap.h"

/**
* @class Player
* Playerの処理クラス
*/
class Player
{
public:
	Player();
	~Player();

	/**
	* @brief 更新処理関数（毎フレーム行う）
	*/
	void Update();

	/**
	* @brief 初期化関数
 	*/
	void Init(GameMap* map_);

	/**
	* @brief 指定フレームのみ行う更新処理関数
	* @param is_count_max_ カウントが指定フレームに達しているか
	*/
	void FixedUpdate(bool is_count_max_);

	void Draw();

	bool IsClear();

	bool IsDead();

private:
	//! プレイヤーの状態の種類
	enum class PlayerState : int {
		RUN,
		JUMP,
		FALL
	};

	ObjectParam m_my_param;		//! 自身のパラメータ
	ObjectParam m_head_param;	//! 上半身の情報
	Vec2 m_pos;					//! 現在地
	int m_speed;				//! 移動速度
	int m_now_jump_height;		//! ジャンプの高さ
	bool m_is_dead;				//! 死亡フラグ
	PlayerState m_now_state;	//! 現在の状態

	//! 参照用
	GameMap* m_p_map;

};


#endif

