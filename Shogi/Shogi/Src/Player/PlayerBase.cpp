#include "PlayerBase.h"
#include "../ShogiGame/ShogiGame.h"
#include "../Input/Input.h"
#include <cstdio>

PlayerBase::PlayerBase():
	m_step(Step::Initialize),
	m_select_pos{},
	m_move_pos{},
	m_take_piece(ObjectType::Type_Empty)
{
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::Update()
{
	switch (m_step) {
	case Step::Initialize:
		// 初期化処理
		Init();
		m_step = Step::Update;
		break;
	case Step::Update:
		// 移動させる駒の選択
		m_select_pos = SelectPiece();
		// 移動先の場所選択
		m_move_pos = SelectMoveSquares();
		// 将棋盤に情報をセット
		MovePiece();
		break;
	case Step::End:
		break;
	}
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
		// x軸の入力
		while (true) {
			printf("移動させる駒の列を選択 : ");
			// 入力処理
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
			printf("入力が不正です、もう一度入力してください\n");
		}

		while (true) {
			printf("移動させる駒の行を選択 : ");
			// 入力処理
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3) {
				pos.m_y--;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}

		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos) != nullptr) {
			return pos;
		}
		else {
			printf("指定した場所に駒はありません、もう一度場所を入力してください\n");
		}
	}
}

Vec2 PlayerBase::SelectMoveSquares()
{
	Vec2 pos;
	while (true) {
		// x軸の入力
		while (true) {
			printf("移動させる駒の列を選択 : ");
			// 入力処理
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
			printf("入力が不正です、もう一度入力してください\n");
		}

		while (true) {
			printf("移動させる駒の行を選択 : ");
			// 入力処理
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3) {
				pos.m_y--;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}

		// 選択した移動先に移動できるかの判定
		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->CanMove(m_select_pos, pos) == true) {
			m_take_piece = ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->GetObjectType();
			return pos;
		}
		else {
			printf("指定した場所には移動できません、移動先をもう一度入力してください\n");
		}
	}
}

void PlayerBase::MovePiece()
{
	ShogiGame::Instance()->m_p_shogi_board->SetPiece(m_select_pos, m_move_pos);
}

bool PlayerBase::IsTakeKing()
{
	// 取った駒の変数に王が入っていればtrue
	if (m_take_piece == ObjectType::King1 || m_take_piece == ObjectType::King2) {
		return true;
	}
	return false;
}
