#ifndef PLAYER_BASE_H_
#define PLAYER_BASE_H_

/**
* @file PlayerBase.h
* @brief PlayerBaseクラスのヘッダ
*/

#include "../Definition.h"

/**
* @class PlayerBase
* @brief Playerの基底クラス
*/
class PlayerBase {
public:
	PlayerBase();
	~PlayerBase();

	//! 処理更新
	virtual void Update();
	//! 初期化関数
	virtual void Init() = 0;

	/**
	* @brief どの駒を移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2 SelectPiece();

	/**
	* @brief どのマスへ移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2 SelectMoveSquares();

	/**
	* @brief 駒を移動させる関数
	* 将棋盤のセット関数を呼び出す
	*/
	void MovePiece();

	/**
	* @brief 王の駒を取っているかを返す関数
	* @return 王を取っていたらtrue
	*/
	bool IsTakeKing();

protected:
	Step m_step;		//! 現在のステップ
	Vec2 m_select_pos;	//! 選択した駒の座標
	Vec2 m_move_pos;	//! 駒の移動先の座標
	ObjectType m_take_piece;	//! 直前に取った駒
};

#endif
