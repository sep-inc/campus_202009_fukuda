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
	// 移動させる駒の選択
	m_select_pos = SelectPiece();
	// 移動先の場所選択
	m_move_pos = SelectMoveSquares();
	// 将棋盤に情報をセット
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
			else if (tmp == 'D') {
				pos.m_x = 3;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}
		while (true) {
			printf("移動させる駒の行を選択 : ");
			// 入力処理
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3 || pos.m_y == 4 || pos.m_y == 5) {
				pos.m_y--;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}
		
		// 入力した場所が空じゃない場合
		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos) != nullptr) {
			// 選択した駒が自身の駒かどうか
			if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos)->GetMyOwner() == m_my_type) {
				return pos;
			}
			else {
				printf("指定した駒は相手の駒です、もう一度駒を選択してください\n");
			}
		}
		// 入力した場所が空の場合
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
			printf("移動させるマスの列を選択 : ");
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
			else if (tmp == 'D') {
				pos.m_x = 3;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}

		while (true) {
			printf("移動させるマスの行を選択 : ");
			// 入力処理
			pos.m_y = Input::Instance()->InputNum();
			if (pos.m_y == 1 || pos.m_y == 2 || pos.m_y == 3 || pos.m_y == 4 || pos.m_y == 5) {
				pos.m_y--;
				break;
			}
			printf("入力が不正です、もう一度入力してください\n");
		}

		// 選択した移動先に移動できるかの判定
		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(m_select_pos)->CanMove(m_select_pos, pos) == true) {
			PieceBase* take_piece = ShogiGame::Instance()->m_p_shogi_board->GetContens(pos);
			// 移動先にある駒が自身の駒だった場合
			if (take_piece != nullptr && take_piece->GetMyOwner() == m_my_type) {
				printf("自分の駒が存在します、他の移動先を入力してください\n");
				continue;
			}

			// 取った駒を保存する処理
			if (take_piece != nullptr) {
				m_take_piece = take_piece->GetObjectType();
			}
			else {
				m_take_piece = ObjectType::Type_Empty;
			}
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
