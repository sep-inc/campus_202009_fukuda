#ifndef PLAYER_H_
#define PLAYER_H_

#include "Definition.h"

/**
* @file Player.h
* @brief Playerクラスのヘッダ
*/


/**
* @class Player
* @brief Player関係の処理を行うクラス
*/
class Player{
public:
	Player();
	~Player();

	/**
	* Playerクラス初期化関数
	* Step_Initialize中に呼び出される
	*/
	void Init();

	/**
	* ステップ処理更新関数
	* ステップごとに処理を呼び出す
	*/
	void Update();

private:
	//! 現在の処理ステップ
	Step m_step;
	//! 描画タイプ
	DrawType m_draw_type;
	//! 入力した座標保存変数
	Vec2 m_input_pos;

};

#endif

