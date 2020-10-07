#ifndef PIECEBASE_H_
#define PIECEBASE_H_

/**
* @file PieceBase.h
* @brief PieceBaseクラスのヘッダ
*/

#include "../Definition.h"
#include <string>

/**
* @class PieceBase
* @brief Pieceクラスの基底クラス
*/
class PieceBase {
public:
	PieceBase();
	virtual ~PieceBase();

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	bool CanMove(Vec2 now_pos, Vec2 move_pos);

	/**
	* @brief オブジェクトの種類を返す関数
	* @return 自身の種類
	*/
	inline ObjectType GetObjectType()const { return m_obj_type; }

	/**
	* @brief 自身の保持者を返す関数
	*/
	inline PlayerType GetMyOwner()const { return m_owner; }

	/**
	* @brief 描画文字取得関数
	*/
	std::string GetDrawString() { return m_draw_string.c_str(); }

protected:
	int(*m_p_range)[MOVE_RANGE_HEIGHT];	//! 移動可能範囲の2次配列のポインタ
	ObjectType m_obj_type;				//! 自身の種類
	PlayerType m_owner;					//! 自身の保有者
	std::string m_draw_string;			//! 自身の描画情報

private:
	static Vec2 m_range_center_pos;			//! 移動可能範囲の配列における中心位置
};

#endif

