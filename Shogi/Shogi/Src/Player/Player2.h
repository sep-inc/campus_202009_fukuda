#ifndef PLAYER2_H_
#define PLAYER2_H_

/**
* @file Player2.h
* @brief Player2クラスのヘッダ
*/

#include "PlayerBase.h"

/**
* @class Player2
* @brief Player2の処理クラス
*/
class Player2 : public PlayerBase {
public:
	Player2();
	~Player2();

	// /**
	// * @brief どの駒を移動させるかの選択処理関数
	// * @return 選んだ座標
	// */
	// virtual Vec2 SelectPiece()override;
	// 
	// /**
	// * @brief どのマスへ移動させるかの選択処理関数
	// * @brief 選んだ座標
	// */
	// virtual Vec2 SelectMoveSquares()override;


};

#endif

