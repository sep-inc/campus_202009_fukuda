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
	*/
	virtual void SelectPiece()override;

	/**
	* @brief どのマスへ移動させるかの選択処理関数
	*/
	virtual void SelectMoveSquares()override;


};

#endif

