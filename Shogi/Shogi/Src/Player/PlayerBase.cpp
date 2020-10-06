#include "PlayerBase.h"
#include "../ShogiGame/ShogiGame.h"
#include "../Input/Input.h"
#include "../Piece/PieceBase.h"
#include <cstdio>

PlayerBase::PlayerBase():
	m_select_pos{},
	m_move_pos{},
	m_take_piece(ObjectType::Type_Empty),
	m_my_type(PlayerType::Type_None)
{
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::Update()
{
	// �ړ��������̑I��
	m_select_pos = SelectPiece();
	// �ړ���̏ꏊ�I��
	m_move_pos = SelectMoveSquares();
	// �����Ղɏ����Z�b�g
	MovePiece();
}

void PlayerBase::Init()
{
	m_select_pos = {};
	m_move_pos = {};
	m_take_piece = ObjectType::Type_Empty;
}

Vec2 PlayerBase::SelectPiece()
{
	Vec2 pos;
	while (true) {
		// x���̓���
		while (true) {
			printf("�ړ��������̗��I�� : ");
			// ���͏���
			char tmp = Input::Instance()->InputChar();
			if (tmp == 'A') {
				pos.m_x = 0;
				break;
			}
			else if (tmp == 'B') {
				pos.m_x = 1;
				break;
			}
			else if (tmp == 'C') {
				pos.m_x = 2;
				break;
			}
			else if (tmp == 'D') {
				pos.m_x = 3;
				break;
			}
			printf("���͂��s���ł��A������x���͂��Ă�������\n");
		}
		while (true) {
			printf("�ړ��������̍s��I�� : ");
			// ���͏���
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3 || pos.m_y == 4 || pos.m_y == 5) {
				pos.m_y--;
				break;
			}
			printf("���͂��s���ł��A������x���͂��Ă�������\n");
		}
		
		// ���͂����ꏊ���󂶂�Ȃ��ꍇ
		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos) != nullptr) {
			// �I����������g�̋�ǂ���
			if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos)->GetMyOwner() == m_my_type) {
				return pos;
			}
			else {
				printf("�w�肵����͑���̋�ł��A������x���I�����Ă�������\n");
			}
		}
		// ���͂����ꏊ����̏ꍇ
		else {
			printf("�w�肵���ꏊ�ɋ�͂���܂���A������x�ꏊ����͂��Ă�������\n");
		}
	}
}

Vec2 PlayerBase::SelectMoveSquares()
{
	Vec2 pos;
	while (true) {
		// x���̓���
		while (true) {
			printf("�ړ�������}�X�̗��I�� : ");
			// ���͏���
			char tmp = Input::Instance()->InputChar();
			if (tmp == 'A') {
				pos.m_x = 0;
				break;
			}
			else if (tmp == 'B') {
				pos.m_x = 1;
				break;
			}
			else if (tmp == 'C') {
				pos.m_x = 2;
				break;
			}
			else if (tmp == 'D') {
				pos.m_x = 3;
				break;
			}
			printf("���͂��s���ł��A������x���͂��Ă�������\n");
		}

		while (true) {
			printf("�ړ�������}�X�̍s��I�� : ");
			// ���͏���
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3 || pos.m_y == 4 || pos.m_y == 5) {
				pos.m_y--;
				break;
			}
			printf("���͂��s���ł��A������x���͂��Ă�������\n");
		}

		// �I�������ړ���Ɉړ��ł��邩�̔���
		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->CanMove(m_select_pos, pos) == true) {
			PieceBase* take_piece = ShogiGame::Instance()->m_p_shogi_board->GetContens(pos);
			// �ړ���ɂ������g�̋�����ꍇ
			if (take_piece != nullptr && take_piece->GetMyOwner() == m_my_type) {
				printf("�����̋���݂��܂��A���̈ړ������͂��Ă�������\n");
				continue;
			}

			// ��������ۑ����鏈��
			if (take_piece != nullptr) {
				m_take_piece = take_piece->GetObjectType();
			}
			else {
				m_take_piece = ObjectType::Type_Empty;
			}
			return pos;
		}
		else {
			printf("�w�肵���ꏊ�ɂ͈ړ��ł��܂���A�ړ����������x���͂��Ă�������\n");
		}
	}
}

void PlayerBase::MovePiece()
{
	ShogiGame::Instance()->m_p_shogi_board->SetPiece(m_select_pos, m_move_pos);
}
