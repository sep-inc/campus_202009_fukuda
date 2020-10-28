#ifndef PACMEN_ITEM_H_
#define PACMEN_ITEM_H_

#include "PacMenGameObject.h"

/**
* @class Item
* @brief Itemの処理クラス
*/
class PacMenItem : public PacMenGameObject
{
public:
	PacMenItem(int number_);
	~PacMenItem();

	/**
	* @brief 初期化関数
	* ランダムに生成位置を決めて初期化
	*/
	void Init(PacMenGameMap* map_)override;

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

