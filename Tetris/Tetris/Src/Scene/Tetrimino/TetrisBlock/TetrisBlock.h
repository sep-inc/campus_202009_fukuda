#ifndef TETRIS_BLOCK_H_
#define TETRIS_BLOCK_H_

#include "../../../Utility/Utility.h"

/**
* @class TetrisBlock
* @brief テトリスのブロッククラス
*/
class TetrisBlock 
{
public:
	TetrisBlock();
	~TetrisBlock();

	/**
	* @brief 座標取得関数
	*/
	inline Vec2_Float GetPos()const { return m_pos; }

	/**
	* @brief 座標セット関数
	*/
	inline void SetPos(Vec2_Float pos_) { m_pos = pos_; }

private:
	Vec2_Float m_pos;	//! ブロックの座標

};

#endif
