#ifndef TRON_CHARACTER_BASE_H_
#define TRON_CHARACTER_BASE_H_

#include "../../../Utility/Utility.h"
#include "../TronGameDefinition.h"
#include "../TronGameMap/TronGameMap.h"

/**
* @class CharacterBase
* @brief キャラクターの基底クラス
*/
class TronCharacterBase
{
public:
	TronCharacterBase();
	virtual ~TronCharacterBase();

	//! 初期化関数
	virtual void Init(TronGameMap* map_) = 0;

	/**
	* @brief 更新関数
	*/
	virtual void Update();

	/**
	* @brief 自身のパラメータを返す関数
	* @return 自身のパラメータ
	*/
	inline TronCharacterParam GetMyParam()const { return m_param; }

	/**
	* @brief 移動する座標を返す関数
	* @return 移動する座標
	*/
	inline Vec2_Int GetMovePos()const { return m_current_pos; }


protected:
	//! 移動する方向を選択する関数
	virtual void SelectMoveDirection() = 0;


protected:
	TronCharacterParam m_param;	//! 自身のタイプと描画文字のデータ
	Vec2_Int m_current_pos;		//! 現在の位置
	TronGameMap* m_p_map;		//! ゲームマップのポインタ変数
};

#endif

