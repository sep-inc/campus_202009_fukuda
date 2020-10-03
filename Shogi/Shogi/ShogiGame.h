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
#include "KingPiece.h"
#include "KnightPiece.h"
#include "GoldGeneralPiece.h"
#include "PawnPiece.h"

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
	KingPiece* m_p_king_piece;
	KnightPiece* m_p_knight_piece;
	GoldGeneralPiece* m_p_gold_general_piece;
	PawnPiece* m_p_pawn_piece;

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

