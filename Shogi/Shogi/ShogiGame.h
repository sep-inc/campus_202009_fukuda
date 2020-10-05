#ifndef SHOGI_GAME_H_
#define SHOGI_GAME_H_

/**
* @file ShogiGame.h
* @brief ShogiGameクラスのヘッダ
*/

#include "Definition.h"
#include "Player1.h"
#include "Player2.h"
#include "ShogiBoard.h"
#include "PieceData.h"
/**
* @class ShogiGame
* @brief 将棋ゲーム本体のクラス
*/
class ShogiGame {
public:
	static ShogiGame* Instance();

	void Update();

	void CreateObjects();

	void DeleteObjects();

	Player1* m_p_player1;
	Player2* m_p_player2;
	ShogiBoard* m_p_shogi_board;
	PieceData* m_p_pieces;

private:
	ShogiGame();
	~ShogiGame();

	static ShogiGame* p_instance;

private:
	Step m_step;
	int m_turn_counter;
	bool m_is_game_finish;

};

#endif

