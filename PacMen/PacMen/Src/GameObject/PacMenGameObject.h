#ifndef PACMEN_GAME_OBJECT_H_
#define PACMEN_GAME_OBJECT_H_

/**
* @file PacMenGameObject.h
* @brief PacMenGameObjectクラスのヘッダ
*/

#include "../Definition.h"

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
	virtual void Init() = 0;

	/**
	* @brief 更新処理関数
	*/
	virtual void Update();

	/**
	* @brief 描画処理
	*/
	virtual void Draw();

	/**
	* @brief 自身の種類を返す関数
	* @return 自身の種類
	*/
	inline PacMenObjectParam GetMyParam()const { return m_param; }

protected:
	PacMenObjectParam m_param;
};

#endif

