#include "TronPlayer.h"
#include "../../../Input/Input.h"
#include "../../../AllDefinition.h"
#include <cstdio>
#include <cstring>

TronPlayer::TronPlayer()
{
	m_param.m_type = TronGameObjectType::PLAYER;
	strcpy_s(m_param.m_draw_string, TRON_DRAW_STRING_SIZE, "■");
	m_current_pos.m_x = TRON_INIT_PLAYER_POS_X;
	m_current_pos.m_y = TRON_INIT_PLAYER_POS_Y;
}

TronPlayer::~TronPlayer()
{
}

void TronPlayer::Init(TronGameMap* map_)
{
	m_p_map = map_;
	m_current_pos.m_x = TRON_INIT_PLAYER_POS_X;
	m_current_pos.m_y = TRON_INIT_PLAYER_POS_Y;
}

void TronPlayer::SelectMoveDirection()
{
	// 入力可能範囲の取得
	Vec2_Int can_move_pos[TRON_CAN_MOVE_LIST_SIZE] = {};
	m_p_map->GetCanMovePos(m_current_pos, can_move_pos);

	// 入力処理
	while (true) {
		Vec2_Int vec = {};
		// 入力情報の取得
		int key = Input::Instance()->GetWaitingKey();
		if (key == KeyType::UP_KEY) {
			vec = { 0,-1 };
		}
		else if (key == KeyType::DOWN_KEY) {
			vec = { 0,1 };
		}
		else if (key == KeyType::LEFT_KEY) {
			vec = { -1,0 };
		}
		else if (key == KeyType::RIGHT_KEY) {
			vec = { 1,0 };
		}

		// 移動先座標の算出
		Vec2_Int move_pos = { m_current_pos.m_x + vec.m_x,m_current_pos.m_y + vec.m_y };
		// 移動可能範囲リストと移動先座標が一致しているかを調べる
		for (int i = 0; i < TRON_CAN_MOVE_LIST_SIZE; i++) {
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