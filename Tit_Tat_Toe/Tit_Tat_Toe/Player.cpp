#include "Player.h"
#include "Global.h"
#include <cstdio>

Player::Player():
	m_draw_type(DrawType::TypeNone),
	m_step(Step::Step_Initialize),
	m_input_pos{}
{
}


Player::~Player()
{
}

void Player::Init()
{
	m_draw_type = DrawType::Player;
}

void Player::Update()
{
	switch (m_step) {
	case Step::Step_Initialize:
		// 初期化
		Init();
		// ステップ更新
		m_step = Step::Step_Run;
		break;
	case Step::Step_Run:
		// ゲーム終了条件が成立していない場合
		if (g_map.IsFinishGame() == false) {
			// 入力情報が確定するまで続ける
			while (true) {
				// 座標の入力
				m_input_pos = g_input.InputPlayer();
				// 入力した座標が空かどうか
				if (g_map.IsEmpty(m_input_pos) == true) {
					// 入力情報をマップへ反映
					g_map.SetPos(m_input_pos, m_draw_type);
					// 勝敗判定を行い、結果をセットする
					g_map.SetResult(g_map.JudgeResult());
					break;
				}
				// 入力したマスがすでに入力されていた場合
				else {
					printf("入力したマスには入力できません\n");
				}
			}
		}
		// ゲーム終了条件が成立していた場合
		else {
			// ステップ更新
			m_step = Step::Step_End;
		}
		break;
	case Step::Step_End:
		break;
	}

}
