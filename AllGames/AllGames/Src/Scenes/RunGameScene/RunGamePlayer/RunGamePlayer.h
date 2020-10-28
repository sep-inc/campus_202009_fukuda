#ifndef RUNGAME_PLAYER_H_
#define RUNGAME_PLAYER_H_

#include "../RunGameDefinition.h"
#include "../RunGameMap/RunGameMap.h"

/**
* @class Player
* Playerの処理クラス
*/
class RunGamePlayer
{
public:
	RunGamePlayer();
	~RunGamePlayer();

	/**
	* @brief 更新処理関数（毎フレーム行う）
	*/
	void Update();

	/**
	* @brief 初期化関数
	*/
	void Init(RunGameMap* map_);

	/**
	* @brief 指定フレームのみ行う更新処理関数
	* @param is_count_max_ カウントが指定フレームに達しているか
	*/
	void FixedUpdate(bool is_count_max_);

	/**
	* @brief 描画処理関数
	* マップクラスに自身の情報をセットする
	*/
	void Draw();

	/**
	* @brief クリアフラグを返す関数
	*
	* @return bool 自身がクリア条件を満たしていたらtrueを返す
	*/
	bool IsClear();

	/**
	* @brief 死亡フラグを返す関数
	*
	* @return 死亡したらtrueを返す
	*/
	bool IsDead();

private:
	//! プレイヤーの状態の種類
	enum class PlayerState : int {
		RUN,
		JUMP,
		FALL
	};

	RunGameObjectParam m_my_param;		//! 自身のパラメータ
	RunGameObjectParam m_head_param;	//! 上半身のパラメータ

	Vec2_Int m_pos;					//! 現在地
	int m_speed;				//! 移動速度
	int m_now_jump_height;		//! ジャンプの高さ
	PlayerState m_now_state;	//! 現在の状態

	//! 参照用
	RunGameMap* m_p_map;

};

#endif

