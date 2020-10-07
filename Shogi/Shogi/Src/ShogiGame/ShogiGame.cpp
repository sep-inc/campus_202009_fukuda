#include "ShogiGame.h"
#include "../Draw/Drawer.h"
#include <sstream>

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

		// �����Ղ̏�����
		InitShogiBoard();

		// �`����Z�b�g
		LinkShogiBoard();
		SetShogiBoard();

		m_step = Step::Update;
		break;
	case Step::Update:
	{
		PlayerBase* player = nullptr;
		// �v���C���[�؂�ւ�
		if (m_turn_counter % 2 == 1) {
			player = m_p_player1;
		}
		else {
			player = m_p_player2;
		}
		player->Update();
		// �^�[���o�ߐ����Z
		m_turn_counter++;

		/* ���s���菈�� */
		ObjectType take_piece = player->GetTakePiece();
		if (take_piece == ObjectType::King1 || take_piece == ObjectType::King2) {
			// �Q�[���I������
			m_is_game_finish = true;
		}

		/* �`����̃Z�b�g */
		LinkShogiBoard();
		SetShogiBoard();
		if (m_is_game_finish) {
			Drawer::Instance()->SetResultString(SetResult(take_piece));
			m_step = Step::End;
		}
		
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
		return true;
	}
	return false;
}

void ShogiGame::LinkShogiBoard()
{
	/*
		char* draw[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT];
		char a[] = "aa";
		draw[0][2] = a;
	*/
	
	// 1�s��
	m_shogi_board_string = "  A    B    C    D  \n";
	// 2�s��
	m_shogi_board_string += " �� �� �� �� �� �� �� �� ��\n";
	
	Vec2 pos;
	int line_counter = 1;	// �s���̃J�E���g�ϐ�
	std::string separation = "��";	// ��؂�
	std::string space = " ";		// ��
	std::string new_line = "\n";	// ���s
	std::string middle_line = " �� �� �� �� �� �� �� �� ��\n";	// ���ԍs

	for (pos.m_y = 0; pos.m_y < SHOGI_BOARD_HEIGHT; pos.m_y++) {
		// �s�J�E���g�𕶎���ɒǉ����鏈��
		std::ostringstream line_num;
		line_num << line_counter;
		m_shogi_board_string += line_num.str();
		m_shogi_board_string += separation;

		for (pos.m_x = 0; pos.m_x < SHOGI_BOARD_WIDTH; pos.m_x++) {
			m_shogi_board_string += space;
			// �}�X�ڂ̒��g����łȂ��ꍇ
			if (m_p_shogi_board->GetContens(pos) != nullptr) {
				m_shogi_board_string += m_p_shogi_board->GetContens(pos)->GetDrawString();
			}
			// �}�X�ڂ̒��g����̏ꍇ
			else {
				m_shogi_board_string += "�@";
			}

			m_shogi_board_string += separation;
		}
		// �s���X�V
		line_counter++;
		m_shogi_board_string += new_line;
		// �Ō�̍s�Ȃ烋�[�v�I���imiddle_line��ǉ����Ȃ����߁j
		if (pos.m_y == SHOGI_BOARD_HEIGHT - 1) {
			break;
		}
		m_shogi_board_string += middle_line;
	}
	// �Ō�̍s
	m_shogi_board_string += " �� �� �� �� �� �� �� �� ��\n";

}

void ShogiGame::SetShogiBoard()
{
	Drawer::Instance()->SetDrawMapString(m_shogi_board_string);
}

std::string ShogiGame::SetResult(ObjectType type)
{
	std::string result;
	if (type == ObjectType::King1) {
		result = "Player2�̏���\n";
	}
	else if (type == ObjectType::King2) {
		result = "Player1�̏���\n";
	}
	return result.c_str();
}

void ShogiGame::InitShogiBoard()
{
	// �����Ղ̏����z�u�쐬
	PieceBase* init_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {
		{nullptr,							m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_knight1},
		{m_p_pieces->m_p_king2,				m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_gold_general1},
		{m_p_pieces->m_p_gold_general2,		m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_king1},
		{m_p_pieces->m_p_knight2,			m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		nullptr}
	};

	// �����ՂփZ�b�g
	for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
		for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
			m_p_shogi_board->SetPiece(x, y, init_board[x][y]);
		}
	}
}
