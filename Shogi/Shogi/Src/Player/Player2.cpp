#include "Player2.h"
#include "../ShogiGame/ShogiGame.h"
#include "../Input/Input.h"
#include <cstdio>
#include <cstdlib>

Player2::Player2()
{
}

Player2::~Player2()
{
}

void Player2::Init()
{
}

// Vec2 Player2::SelectPiece()
// {
// 	Vec2 pos;
// 	while (true) {
// 		// x���̓���
// 		while (true) {
// 			printf("�ړ��������̗��I�� : ");
// 			// ���͏���
// 			char tmp = Input::Instance()->InputChar();
// 			if (tmp == 'A') {
// 				pos.m_x = 0;
// 				break;
// 			}
// 			else if (tmp == 'B') {
// 				pos.m_x = 1;
// 				break;
// 			}
// 			else if (tmp == 'C') {
// 				pos.m_x = 2;
// 				break;
// 			}
// 			printf("���͂��s���ł��A������x���͂��Ă�������\n");
// 		}
// 
// 		while (true) {
// 			printf("�ړ��������̍s��I�� : ");
// 			// ���͏���
// 			pos.m_y = Input::Instance()->InputNum();
// 			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3) {
// 				pos.m_y--;
// 				break;
// 			}
// 			printf("���͂��s���ł��A������x���͂��Ă�������\n");
// 		}
// 
// 		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos) != nullptr) {
// 			return pos;
// 		}
// 		else {
// 			printf("�w�肵���ꏊ�ɋ�͂���܂���A������x�ꏊ����͂��Ă�������\n");
// 		}
// 	}
// }
// 
// Vec2 Player2::SelectMoveSquares()
// {
// 	Vec2 pos;
// 	while (true) {
// 		// x���̓���
// 		while (true) {
// 			printf("�ړ��������̗��I�� : ");
// 			// ���͏���
// 			char tmp = Input::Instance()->InputChar();
// 			if (tmp == 'A') {
// 				pos.m_x = 0;
// 				break;
// 			}
// 			else if (tmp == 'B') {
// 				pos.m_x = 1;
// 				break;
// 			}
// 			else if (tmp == 'C') {
// 				pos.m_x = 2;
// 				break;
// 			}
// 			printf("���͂��s���ł��A������x���͂��Ă�������\n");
// 		}
// 
// 		while (true) {
// 			printf("�ړ��������̍s��I�� : ");
// 			// ���͏���
// 			pos.m_y = Input::Instance()->InputNum();
// 			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3) {
// 				pos.m_y--;
// 				break;
// 			}
// 			printf("���͂��s���ł��A������x���͂��Ă�������\n");
// 		}
// 
// 		// �I�������ړ���Ɉړ��ł��邩�̔���
// 		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->CanMove(m_select_pos, pos) == true) {
// 			m_take_piece = ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->GetObjectType();
// 			return pos;
// 		}
// 		else {
// 			printf("�w�肵���ꏊ�ɂ͈ړ��ł��܂���A�ړ����������x���͂��Ă�������\n");
// 		}
// 	}
// }
