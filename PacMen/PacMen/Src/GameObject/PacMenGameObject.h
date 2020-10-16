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

	//! 初期化処理
	virtual void Init(GameMap* map_);

	/**
	* @brief 更新処理関数
	*/
	virtual void Update();

	/**
	* @brief 描画処理
	*/
	virtual void Draw(DrawerBase* drawer_);

	/**
	* @brief 自身の種類を返す関数
	* @return 自身の種類
	*/
	inline PacMenObjectParam GetMyParam()const { return m_param; }

	virtual bool CheckHit();

	/**
	* @brief 死亡フラグを立てる関数
	*/
	inline void OnDeleteFlag() { m_is_delete = true; }

	/**
	* @brief 死亡フラグ取得関数
	* @return 死亡フラグ
	*/
	inline bool GetDeleteFlag() { return m_is_delete; }


protected:
	// 自身のパラメータ
	PacMenObjectParam m_param;
	GameMap* m_p_game_map;

	bool m_is_delete;	// 死亡フラグ
};

#endif

