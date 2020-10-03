#include "Player1.h"
#include "ShogiGame.h"
#include "Input.h"
#include <cstdio>
#include <cstdlib>

Player1::Player1()
{
}

Player1::~Player1()
{
}

void Player1::Update()
{
	switch (m_step) {
	case Step::Initialize:
		Init();
		m_step = Step::Update;
		break;
	case Step::Update:
		break;
	case Step::End:
		break;
	}
}

void Player1::Init()
{
}

Vec2 Player1::SelectPiece()
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

		if (ShogiGame::Instance()->m_p_shogi_board->GetContens(pos)) {

		}
	}
	
}

Vec2 Player1::SelectMoveSquares()
{
}
