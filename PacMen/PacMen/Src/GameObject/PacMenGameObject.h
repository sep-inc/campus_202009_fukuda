#ifndef PACMEN_GAME_OBJECT_H_
#define PACMEN_GAME_OBJECT_H_

/**
* @file PacMenGameObject.h
* @brief PacMenGameObjectクラスのヘッダ
*/

#include "../Definition.h"
#include "../GameMap/GameMap.h"
#include "../Draw/DrawerBase.h"

/**
* @class PacMenGameObject
* @brief PacMenGameに必要なすべてのゲームオブジェクトの基底クラス
*/
class PacMenGameObject
{
public:
	PacMenGameObject();
	virtual ~PacMenGameObject();

	//! 初期化処理関数
	virtual void Init(GameMap* map_);

	/**
	* @brief 更新処理関数
	*/
	virtual void Update();

	/**
	* @brief 描画処理関数
	*/
	virtual void Draw(DrawerBase* drawer_);

	//! 当たり判定処理関数
	virtual bool CheckHit();


protected:
	// 自身のパラメータ
	PacMenObjectParam m_param;
	GameMap* m_p_game_map;

	bool m_is_delete;	// 死亡フラグ
};

#endif

