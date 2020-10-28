#ifndef PACMEN_GAMEOBJECT_H_
#define PACMEN_GAMEOBJECT_H_

#include "../PacMenGameDefinition.h"
#include "../PacMenGameMap/PacMenGameMap.h"
#include "../../../Draw/Drawers/DrawerBase.h"

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
	virtual void Init(PacMenGameMap* map_);

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
	PacMenGameMap* m_p_game_map;

	bool m_is_delete;	// 死亡フラグ
};

#endif
