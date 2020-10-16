#ifndef ITEM_H_
#define ITEM_H_

/**
* @file Item.h
* @brief Itemクラスのヘッダ
*/

#include "PacMenGameObject.h"

/**
* @class Item
* @brief Itemの処理クラス
*/
class Item : public PacMenGameObject
{
public:
	Item(int number_);
	~Item();

	/**
	* @brief 初期化関数
	* ランダムに生成位置を決めて初期化
	*/
	void Init(GameMap* map_)override;

	/**
	* @brief 更新処理関数
	* フラグを参照して、立っていなかったら自身の座標をセットする
	*/
	void Update()override;

	/**
	* @brief 描画処理関数
	* 自身のフラグをみて描画するかどうかを決める
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief 当たり判定処理関数
	* @return bool Playerと当たっていたらtrue
	*/
	bool CheckHit()override;

};

#endif