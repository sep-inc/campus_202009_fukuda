#include "Player.h"
#include "../../Input/Input.h"
#include <cstring>

Player::Player()
{
	m_param.m_pos.m_x = PLAYER_INIT_POS_WIDTH;
	m_param.m_pos.m_y = PLAYER_INIT_POS_HEIGHT;
	m_param.m_type = PacMenObjectType::PLAYER;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "〇");
}

Player::~Player()
{
}

void Player::SelectMovePos()
{
	Vec2 movement = {};	// 移動量
	Vec2 can_move_array[CAN_CHARACTER_MOVE_POS_LIST] = {};	// 移動可能範囲
	// 移動可能範囲の取得
	m_p_game_map->GetCanPlayerMovePos(m_param.m_pos, can_move_array);

	while (true) {
		// 入力処理
		movement = Input::Instance()->InputDirection();
		Vec2 move_pos = { m_param.m_pos.m_x + movement.m_x,m_param.m_pos.m_y + movement.m_y };
		// 移動先座標が移動可能範囲の中にあれば座標をセットし、終了
		for (int i = 0; i < CAN_CHARACTER_MOVE_POS_LIST; i++) {
			if (move_pos.m_x == can_move_array[i].m_x &&
				move_pos.m_y == can_move_array[i].m_y) {
				m_p_game_map->SetMovePos(m_param, move_pos);
				// 現在地を移動先に更新
				m_param.m_pos = move_pos;
				return;
			}
		}
		// 一致していない場合はループ続行
		printf("入力先には移動できません、もう一度入力して下さい\n");
	}
}

bool Player::CheckHit()
{
	if (m_p_game_map->GetContent(m_param.m_pos) == PacMenObjectType::MONSTER) {
		m_is_delete = true;
		return m_is_delete;
	}
	return false;
}
