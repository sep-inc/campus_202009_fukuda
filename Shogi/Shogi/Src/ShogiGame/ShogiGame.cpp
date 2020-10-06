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
		// �I�u�W�F�N�g�̐���
		CreateObjects();
		m_step = Step::Update;
		break;
	case Step::Update:
	{
		PlayerBase* player = nullptr;
		// �v���C���[�؂�ւ�
		if (m_turn_counter % 2 == 1) {
			PlayerBase* player = m_p_player1;
		}
		else {
			PlayerBase* player = m_p_player2;
		}
		player->Update();
		// �^�[���o�ߐ����Z
		m_turn_counter++;

		/* ���s���菈�� */
		if (player->IsTakeKing()) {
			// �Q�[���I������
			m_is_game_finish = true;
		}

		/* �`��N���X�֏���n������ */
		

		break;
	}
	case Step::End:
		// �I�u�W�F�N�g�̔j��
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
