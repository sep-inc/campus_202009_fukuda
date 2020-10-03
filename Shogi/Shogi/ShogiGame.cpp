#include "ShogiGame.h"

ShogiGame* ShogiGame::p_instance = 0;

ShogiGame::ShogiGame():
	m_p_player1(nullptr),
	m_p_player2(nullptr),
	m_p_shogi_board(nullptr),
	m_p_king_piece(nullptr),
	m_p_knight_piece(nullptr),
	m_p_gold_general_piece(nullptr),
	m_p_pawn_piece(nullptr),
	m_step(Step::Initialize),
	m_turn_counter(1),
	m_is_game_finish(false)
{
}

ShogiGame::~ShogiGame()
{
}

ShogiGame* ShogiGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new ShogiGame;
	}
	return p_instance;
}

void ShogiGame::Update()
{
	switch (m_step) {
	case Step::Initialize:
		CreateObjects();
		m_step = Step::Update;
		break;
	case Step::Update:
		m_p_player1->Update();
		m_p_player2->Update();
		/* èüîsîªíËèàóù */

		/* ï`âÊèàóù */
		break;
	case Step::End:
		DeleteObjects();
		break;
	}
}

void ShogiGame::CreateObjects()
{
	if (m_p_player1 == nullptr)
		m_p_player1 = new Player1;
	if (m_p_player2 == nullptr)
		m_p_player2 = new Player2;
	if (m_p_shogi_board == nullptr)
		m_p_shogi_board = new ShogiBoard;
	if (m_p_king_piece == nullptr)
		m_p_king_piece = new KingPiece;
	if (m_p_knight_piece == nullptr)
		m_p_knight_piece = new KnightPiece;
	if (m_p_gold_general_piece == nullptr)
		m_p_gold_general_piece = new GoldGeneralPiece;
	if (m_p_pawn_piece == nullptr)
		m_p_pawn_piece = new PawnPiece;
}

void ShogiGame::DeleteObjects()
{
	if (m_p_player1 != nullptr) {
		delete m_p_player1;
		m_p_player1 = nullptr;
	}
	if (m_p_player2 != nullptr) {
		delete m_p_player2;
		m_p_player2 = nullptr;
	}
	if (m_p_shogi_board != nullptr) {
		delete m_p_shogi_board;
		m_p_shogi_board = nullptr;
	}
	if (m_p_king_piece != nullptr) {
		delete m_p_king_piece;
		m_p_king_piece = nullptr;
	}
	if (m_p_knight_piece != nullptr) {
		delete m_p_knight_piece;
		m_p_knight_piece = nullptr;
	}
	if (m_p_gold_general_piece != nullptr) {
		delete m_p_gold_general_piece;
		m_p_gold_general_piece = nullptr;
	}
	if (m_p_pawn_piece != nullptr) {
		delete m_p_pawn_piece;
		m_p_pawn_piece = nullptr;
	}
		
}
