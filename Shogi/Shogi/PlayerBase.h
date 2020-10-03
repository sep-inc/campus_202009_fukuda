#ifndef PLAYER_BASE_H_
#define PLAYER_BASE_H_

/**
* @file PlayerBase.h
* @brief PlayerBaseクラスのヘッダ
*/

#include "Definition.h"

/**
* @class PlayerBase
* @brief Playerの基底クラス
*/
class PlayerBase {
public:
	PlayerBase();
	~PlayerBase();

	//! 処理更新
	virtual void Update() = 0;
	//! 初期化関数
	virtual void Init() = 0;

	//! どの駒を移動させるかの選択処理関数
	virtual void SelectPiece() = 0;

	//! どのマスへ移動させるかの選択処理関数
	virtual void SelectMoveSquares() = 0;

	/**
	* @brief 駒を移動させる関数
	* 将棋盤のセット関数を呼び出す
	*/
	void MovePiece();


protected:
	Step m_step;		//! 現在のステップ
	Vec2 m_select_pos;	//! 選択した駒の座標
	Vec2 m_move_pos;	//! 駒の移動先の座標

};

#endif
