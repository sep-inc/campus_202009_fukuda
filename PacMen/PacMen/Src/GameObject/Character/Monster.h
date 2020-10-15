#ifndef MONSTER_H_
#define MONSTER_H_

/**
* @file Monster.h
* @brief Monsterクラスのヘッダ
*/

#include "CharacterBase.h"

/**
* @class Monster
* @brief Monsterの処理クラス
*/
class Monster : public CharacterBase
{
public:
	Monster();
	~Monster();

	/**
	* @brief 初期化関数
	* 初期化時に自身の生成座標をランダムに選択する
	*/
	void Init(GameMap* map_)override;

	/**
	* @brief 移動座標選択関数
	* 移動可能範囲からランダムで移動座標を選択する
	*
	* @return 選択した座標
	*/
	void SelectMovePos();
};

#endif
