#ifndef SHOGI_PLAYER_BASE_H_
#define SHOGI_PLAYER_BASE_H_

#include "../../../Utility/Utility.h"
#include "../ShogiGameDefinition.h"
#include "../ShogiBoard/ShogiBoard.h"

/**
* @class PlayerBase
* @brief Playerの基底クラス
*/
class ShogiPlayerBase {
public:
	ShogiPlayerBase();
	~ShogiPlayerBase();

	//! 処理更新
	virtual void Update();

	//! 初期化関数
	virtual void Init(ShogiBoard* board_);

	/**
	* @brief 王の駒を取っているかを返す関数
	* @return 王を取っていたらtrue
	*/
	inline ShogiGameObjectType GetTakePiece()const { return m_take_piece; }

	/**
	* @brief 自身のタイプを返す関数
	*/
	inline ShogiPlayerType GetMyType()const { return m_my_type; }


private:
	/**
	* @brief どの駒を移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2_Int SelectPiece();

	/**
	* @brief どのマスへ移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2_Int SelectMoveSquares();

	/**
	* @brief 駒を移動させる関数
	* 将棋盤のセット関数を呼び出す
	*/
	void MovePiece();


protected:
	Vec2_Int m_select_pos;	//! 選択した駒の座標
	Vec2_Int m_move_pos;	//! 駒の移動先の座標
	ShogiGameObjectType m_take_piece;	//! 直前に取った駒
	ShogiPlayerType m_my_type;	//! 自身のタイプ

	ShogiBoard* m_p_board;
};

#endif
