#include "ShogiGame.h"
#include "../Draw/Drawer.h"

ShogiGame* ShogiGame::p_instance = 0;

ShogiGame::ShogiGame():
	m_p_player1(nullptr),
	m_p_player2(nullptr),
	m_p_shogi_board(nullptr),
	m_p_pieces(nullptr),
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
		// オブジェクトの生成
		CreateObjects();
		m_step = Step::Update;
		break;
	case Step::Update:
	{
		PlayerBase* player = nullptr;
		// プレイヤー切り替え
		if (m_turn_counter % 2 == 1) {
			PlayerBase* player = m_p_player1;
		}
		else {
			PlayerBase* player = m_p_player2;
		}
		player->Update();
		// ターン経過数加算
		m_turn_counter++;

		/* 勝敗判定処理 */
		if (player->IsTakeKing()) {
			// ゲーム終了処理
			m_is_game_finish = true;
		}

		/* 描画クラスへ情報を渡す処理 */
		

		break;
	}
	case Step::End:
		// オブジェクトの破棄
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
	if (m_p_pieces == nullptr)
		m_p_pieces = new PieceData;
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
	if (m_p_pieces != nullptr) {
		delete m_p_pieces;
		m_p_pieces = nullptr;
	}
	
}

bool ShogiGame::IsGameFinish()
{
	if (m_is_game_finish == true) {
		true;
	}
	return false;
}

void ShogiGame::SetShogiBoard()
{
	
}
