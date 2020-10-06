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
	Vec2 m_range_center_pos;
	int m_move_range[MOVE_RANGE_WIDTH][MOVE_RANGE_HEIGHT];
	ObjectType m_obj_type;
	std::string m_draw_string;
	PlayerType m_owner;		//! 自身の保有者
};

#endif

