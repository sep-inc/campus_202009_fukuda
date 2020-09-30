#ifndef PLAYER_H_
#define PLAYER_H_

/**
* @file Player.h
* @brief プレイヤークラスのヘッダ
*/


#include "Definition.h"

/**
* @class Player
* @brief Playerの処理をまとめたクラス
*/
class Player 
{
public:
	Player();
	~Player();

	/**
	* @brief ステップ処理関数
	* ステップごとの処理を行う、この関数をメインで呼び出す
	*/
	void UpdateStep();

	/**
	* @brief 入力処理関数
	* Inputクラスから入力関数を呼び出す
	*/
	void Input();
	

private:
	Step m_step;				// 現在のステップ
	int m_source_pile_num;		// 移動させる円盤のある杭の番号
	int m_destination_pile_num;	// 移動先の杭の番号

};

#endif
