#ifndef TETRIMINO_BASE_H_
#define TETRIMINO_BASE_H_

#include "../../Utility/Utility.h"
#include "../../TetrisDefinition.h"

/**
* @class TetriminoBase
* @brief テトリミノクラス
*/
class TetriminoBase
{
public:
	TetriminoBase();
	~TetriminoBase();

	/**
	* @brief 更新処理関数
	*/
	void Update();

	/**
	* @brief 初期化関数
	*/
	void Init();


protected:
	Vec2_Float m_pos;	// 自身の座標（5×5マスの中心）
	bool m_is_delete;	// デリートフラグ

	int(*m_p_block_form)[TETRIMINO_WIDTH];		//! テトリミノの形情報
};

#endif

