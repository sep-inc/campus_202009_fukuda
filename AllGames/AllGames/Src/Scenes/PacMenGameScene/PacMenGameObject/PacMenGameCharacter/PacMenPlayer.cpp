#include "PacMenPlayer.h"
#include "../../../../AllDefinition.h"
#include "../../../../Input/Input.h"
#include <cstring>

PacMenPlayer::PacMenPlayer()
{
	m_param.m_pos.m_x = PACMEN_PLAYER_INIT_POS_X;
	m_param.m_pos.m_y = PACMEN_PLAYER_INIT_POS_Y;
	m_param.m_type = PacMenObjectType::PLAYER;
	strcpy_s(m_param.m_draw_string, PACMEN_DRAW_STRING_SIZE, "〇");
}

PacMenPlayer::~PacMenPlayer()
{
}

void PacMenPlayer::SelectMovePos()
{
	Vec2_Int movement = {};	// 移動量
	Vec2_Int can_move_array[PACMEN_CAN_CHARACTER_MOVE_POS_LIST] = {};	// 移動可能範囲
	// 移動可能範囲の取得
	m_p_game_map->GetCanPlayerMovePos(m_param.m_pos, can_move_array);

	while (true) {
		// 入力処理
		int key = Input::Instance()->GetWaitingKey();
		if (key == KeyType::UP_KEY) {
			movement = { 0,-1 };
		}
		else if (key == KeyType::DOWN_KEY) {
			movement = { 0,1 };
		}
		else if (key == KeyType::LEFT_KEY) {
			movement = { -1,0 };
		}
		else if (key == KeyType::RIGHT_KEY) {
			movement = { 1,0 };
		}

		Vec2_Int move_pos = { m_param.m_pos.m_x + movement.m_x,m_param.m_pos.m_y + movement.m_y };
		// 移動先座標が移動可能範囲の中にあれば座標をセットし、終了
		for (int i = 0; i < PACMEN_CAN_CHARACTER_MOVE_POS_LIST; i++) {
			if (move_pos.m_x == can_move_array[i].m_x &&
				move_pos.m_y == can_move_array[i].m_y) {
				m_p_game_map->SetMovePos(m_param, move_pos);
				// 現在地を移動先に更新
				m_param.m_pos = move_pos;
				return;
			}
		}
	}
}

bool PacMenPlayer::CheckHit()
{
	if (m_p_game_map->GetContent(m_param.m_pos) == PacMenObjectType::MONSTER) {
		m_is_delete = true;
		return m_is_delete;
	}
	return false;
}