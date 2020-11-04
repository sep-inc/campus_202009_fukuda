#ifndef TOWER_OF_HANOI_PLAYER_H_
#define TOWER_OF_HANOI_PLAYER_H_

#include "../TowerOfHanoiDefinition.h"

/**
* @class TowerOfHanoiPlayer
* @brief Playerの処理をまとめたクラス
*/
class TowerOfHanoiPlayer
{
public:
	TowerOfHanoiPlayer();
	~TowerOfHanoiPlayer();

	/**
	* @brief ステップ処理関数
	* ステップごとの処理を行う、この関数をメインで呼び出す
	*/
	void Update();

	/**
	* @brief 入力処理関数
	* Inputクラスから入力関数を呼び出す
	*/
	void InputPlayer();


private:
	int m_source_pile_num;		// 移動させる円盤のある杭の番号
	int m_destination_pile_num;	// 移動先の杭の番号

};


#endif
