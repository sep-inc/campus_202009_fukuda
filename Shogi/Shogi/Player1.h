#ifndef PLAYER1_H_
#define PLAYER1_H_

/**
* @file Player1.h
* @brief Player1クラスのヘッダ
*/


#include "PlayerBase.h"

/**
* @class Player1
* @brief Player1の処理クラス
*/
class Player1 : public PlayerBase {
public:
	Player1();
	~Player1();


	/**
	* @brief 処理更新関数
	*/
	void Update()override;

	/**
	* @brief 初期化関数
	*/
	void Init()override;

	/**
	* @brief どの駒を移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2 SelectPiece()override;

	/**
	* @brief どのマスへ移動させるかの選択処理関数
	* @brief 選んだ座標
	*/
	virtual Vec2 SelectMoveSquares()override;


};

#endif
