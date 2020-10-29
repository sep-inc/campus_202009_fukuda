#include "ShogiPlayerBase.h"
#include "../ShogiPiece/ShogiPieceBase.h"
#include "../../../Input/Input.h"
#include "../../../AllDefinition.h"
#include <cstdio>

ShogiPlayerBase::ShogiPlayerBase() :
	m_select_pos{},
	m_move_pos{},
	m_take_piece(ShogiGameObjectType::TYPE_EMPTY),
	m_my_type(ShogiPlayerType::TYPE_NONE),
	m_p_board(nullptr)
{
}

ShogiPlayerBase::~ShogiPlayerBase()
{
}

void ShogiPlayerBase::Update()
{
	// 移動させる駒の選択
	m_select_pos = SelectPiece();
	// 移動先の場所選択
	m_move_pos = SelectMoveSquares();
	// 将棋盤に情報をセット
	MovePiece();
}

void ShogiPlayerBase::Init(ShogiBoard* board_)
{
	m_select_pos = {};
	m_move_pos = {};
	m_take_piece = ShogiGameObjectType::TYPE_EMPTY;

	m_p_board = board_;
}

Vec2_Int ShogiPlayerBase::SelectPiece()
{
	Vec2_Int pos;
	while (true) {
		// x軸の入力
		while (true) {
			bool break_flag = false;
			printf("移動させる駒の列を選択 : ");
			// 入力処理
			int key = Input::Instance()->GetWaitingKey();
			switch (key) {
			case KeyType::A_KEY:
				pos.m_x = 0;
				break_flag = true;
				break;
			case KeyType::B_KEY:
				pos.m_x = 1;
				break_flag = true;
				break;
			case KeyType::C_KEY:
				pos.m_x = 2;
				break_flag = true;
				break;
			case KeyType::D_KEY:
				pos.m_x = 3;
				break_flag = true;
				break;
			default:
				printf("\n入力が不正です、もう一度入力してください\n");
				break;
			}

			if (break_flag) {
				break;
			}
		}
		while (true) {
			bool break_flag = false;
			printf("移動させる駒の行を選択 : ");
			// 入力処理
			int key = Input::Instance()->GetWaitingKey();
			switch (key) {
			case KeyType::ONE_KEY:
				pos.m_y = 0;
				break_flag = true;
				break;
			case KeyType::TWO_KEY:
				pos.m_y = 1;
				break_flag = true;
				break;
			case KeyType::THREE_KEY:
				pos.m_y = 2;
				break_flag = true;
				break;
			case KeyType::FOUR_KEY:
				pos.m_y = 3;
				break_flag = true;
				break;
			case KeyType::FIVE_KEY:
				pos.m_y = 4;
				break_flag = true;
				break;
			default:
				printf("\n入力が不正です、もう一度入力してください\n");
				break;
			}

			if (break_flag) {
				break;
			}
		}

		// 入力した場所が空じゃない場合
		if (m_p_board->GetContens(pos) != nullptr) {
			// 選択した駒が自身の駒かどうか
			if (m_p_board->GetContens(pos)->GetMyOwner() == m_my_type) {
				return pos;
			}
			else {
				printf("\n指定した駒は相手の駒です、もう一度駒を選択してください\n");
			}
		}
		// 入力した場所が空の場合
		else {
			printf("\n指定した場所に駒はありません、もう一度場所を入力してください\n");
		}
	}
}

Vec2_Int ShogiPlayerBase::SelectMoveSquares()
{
	Vec2_Int pos;
	while (true) {
		// x軸の入力
		while (true) {
			printf("移動させるマスの列を選択 : ");
			bool break_flag = false;
			// 入力処理
			int key = Input::Instance()->GetWaitingKey();
			switch (key) {
			case KeyType::A_KEY:
				pos.m_x = 0;
				break_flag = true;
				break;
			case KeyType::B_KEY:
				pos.m_x = 1;
				break_flag = true;
				break;
			case KeyType::C_KEY:
				pos.m_x = 2;
				break_flag = true;
				break;
			case KeyType::D_KEY:
				pos.m_x = 3;
				break_flag = true;
				break;
			default:
				printf("\n入力が不正です、もう一度入力してください\n");
				break;
			}

			if (break_flag) {
				break;
			}
		}

		while (true) {
			printf("移動させるマスの行を選択 : ");
			bool break_flag = false;
			// 入力処理
			int key = Input::Instance()->GetWaitingKey();
			switch (key) {
			case KeyType::ONE_KEY:
				pos.m_y = 0;
				break_flag = true;
				break;
			case KeyType::TWO_KEY:
				pos.m_y = 1;
				break_flag = true;
				break;
			case KeyType::THREE_KEY:
				pos.m_y = 2;
				break_flag = true;
				break;
			case KeyType::FOUR_KEY:
				pos.m_y = 3;
				break_flag = true;
				break;
			case KeyType::FIVE_KEY:
				pos.m_y = 4;
				break_flag = true;
				break;
			default:
				printf("\n入力が不正です、もう一度入力してください\n");
				break;
			}

			if (break_flag) {
				break;
			}
		}

		// 選択した移動先に移動できるかの判定
		if (m_p_board->GetContens(m_select_pos)->CanMove(m_select_pos, pos) == true) {
			ShogiPieceBase* take_piece = m_p_board->GetContens(pos);
			// 移動先にある駒が自身の駒だった場合
			if (take_piece != nullptr && take_piece->GetMyOwner() == m_my_type) {
				printf("\n自分の駒が存在します、他の移動先を入力してください\n");
				continue;
			}

			// 取った駒を保存する処理
			if (take_piece != nullptr) {
				m_take_piece = take_piece->GetObjectType();
			}
			else {
				m_take_piece = ShogiGameObjectType::TYPE_EMPTY;
			}
			return pos;
		}
		else {
			printf("\n指定した場所には移動できません、移動先をもう一度入力してください\n");
		}
	}
}

void ShogiPlayerBase::MovePiece()
{
	m_p_board->SetMovePiece(m_select_pos, m_move_pos);
}