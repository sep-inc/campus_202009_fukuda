#ifndef SHOGI_PIECE_BASE_H_
#define SHOGI_PIECE_BASE_H_

#include "../ShogiGameDefinition.h"
#include "../../../Utility/Utility.h"
#include <string>

/**
* @class ShogiPieceBase
* @brief Pieceクラスの基底クラス
*/
class ShogiPieceBase {
public:
	ShogiPieceBase();
	virtual ~ShogiPieceBase();

	/**
	* @brief 指定された範囲に駒が動けるかを判別する関数
	*/
	bool CanMove(Vec2_Int now_pos, Vec2_Int move_pos);

	/**
	* @brief オブジェクトの種類を返す関数
	* @return 自身の種類
	*/
	inline ShogiGameObjectType GetObjectType()const { return m_obj_type; }

	/**
	* @brief 自身の保持者を返す関数
	*/
	inline ShogiPlayerType GetMyOwner()const { return m_owner; }

	/**
	* @brief 描画文字取得関数
	*/
	std::string GetDrawString() { return m_draw_string.c_str(); }

protected:
	int(*m_p_range)[SHOGIGAME_MOVE_RANGE_HEIGHT];	//! 移動可能範囲の2次配列のポインタ
	ShogiGameObjectType m_obj_type;		//! 自身の種類
	ShogiPlayerType m_owner;			//! 自身の保有者
	std::string m_draw_string;			//! 自身の描画情報

private:
	static Vec2_Int m_range_center_pos;			//! 移動可能範囲の配列における中心位置
};

#endif
