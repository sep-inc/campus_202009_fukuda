#include "Player.h"
#include "../Input/Input.h"
#include <cstdio>
#include <cstring>

Player::Player()
{
	m_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "■");
	m_current_pos.m_x = INIT_PLAYER_POS_X;
	m_current_pos.m_y = INIT_PLAYER_POS_Y;
}

Player::~Player()
{
}

void Player::SelectMoveDirection()
{
	// 入力可能範囲の取得
	Vec2 can_move_pos[CAN_MOVE_LIST_SIZE] = {};
	m_p_map->GetCanMovePos(m_current_pos, can_move_pos);

	// 入力処理
	while (true) {
		// 入力情報の取得
		Vec2 vec = Input::Instance()->InputDirection();
		// 移動先座標の算出
		Vec2 move_pos = { m_current_pos.m_x + vec.m_x,m_current_pos.m_y + vec.m_y };
		// 移動可能範囲リストと移動先座標が一致しているかを調べる
		for (int i = 0; i < CAN_MOVE_LIST_SIZE; i++) {
			// 一致していた場合、現在の座標を更新
			if (can_move_pos[i].m_x == move_pos.m_x &&
				can_move_pos[i].m_y == move_pos.m_y) {
				m_current_pos = move_pos;
				return;
			}
		}
		// 一致していない場合はループ続行
		printf("入力先には移動できません、もう一度入力して下さい\n");
	}
}
