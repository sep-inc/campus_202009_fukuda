#ifndef CHARACTER_BASE_H_
#define CHARACTER_BASE_H_

/**
* @file CharacterBase.h
* @brief CharacterBaseクラスのヘッダ
*/

#include "../Definition.h"
#include "../GameMap/GameMap.h"

/**
* @class CharacterBase
* @brief キャラクターの基底クラス
*/
class CharacterBase 
{
public:
	CharacterBase();
	virtual ~CharacterBase();

	//! 初期化関数
	virtual void Init(GameMap* map_);

	/**
	* @brief 更新関数
	*/
	virtual void Update();
	
	/**
	* @brief 自身のパラメータを返す関数
	* @return 自身のパラメータ
	*/
	inline CharacterParam GetMyParam()const { return m_param; }

	/**
	* @brief 移動する座標を返す関数
	* @return 移動する座標
	*/
	inline Vec2 GetMovePos()const { return m_current_pos; }


protected:
	//! 移動する方向を選択する関数
	virtual void SelectMoveDirection() = 0;


protected:
	CharacterParam m_param;	//! 自身のタイプと描画文字のデータ
	Vec2 m_current_pos;		//! 現在の位置
	GameMap* m_p_map;		//! ゲームマップのポインタ変数
};

#endif

