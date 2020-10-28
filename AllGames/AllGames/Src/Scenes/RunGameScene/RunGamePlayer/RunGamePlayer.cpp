#include "RunGamePlayer.h"
#include "../../../Input/Input.h"
#include <cstring>

RunGamePlayer::RunGamePlayer() :
	m_pos{},
	m_speed(RUNGAME_PLAYER_MOVE_SPEED),
	m_now_jump_height(0),
	m_now_state(RunGamePlayerState::RUN),
	m_p_map(nullptr)
{
}

RunGamePlayer::~RunGamePlayer()
{
}

void RunGamePlayer::Update()
{
	// 入力情報取得
	int key = Input::Instance()->GetKey();
	// スペースキー入力処理
	if (key == KeyType::SPACE_KEY) {
		if (m_now_state == RunGamePlayerState::RUN) {
			m_now_state = RunGamePlayerState::JUMP;
		}
	}
}

void RunGamePlayer::Init(RunGameMap* map_)
{
	// パラメータ情報の初期化
	m_my_param.m_type = RunGameObjectType::PLAYER;
	strcpy_s(m_my_param.m_draw_string, RUNGAME_DRAW_STRING_SIZE, "▽");
	m_head_param.m_type = RunGameObjectType::PLAYER;
	strcpy_s(m_head_param.m_draw_string, RUNGAME_DRAW_STRING_SIZE, "〇");
	// 各メンバ変数初期化
	m_pos.m_x = RUNGAME_PLAYER_INIT_POS_X;
	m_pos.m_y = RUNGAME_PLAYER_INIT_POS_Y;
	m_now_jump_height = 0;
	m_now_state = RunGamePlayerState::RUN;
	// マップをセット
	m_p_map = map_;
}

void RunGamePlayer::FixedUpdate(bool is_count_max_)
{
	if (is_count_max_ == true) {
		// 自身の状態に合わせた移動処理
		switch (m_now_state)
		{
		case RunGamePlayerState::RUN:
			m_pos.m_x++;
			// 地面と当たっていなかった場合、状態をFALLに移行
			if (!m_p_map->IsHitGround(m_pos)) {
				m_now_state = RunGamePlayerState::FALL;
			}
			break;
		case RunGamePlayerState::JUMP:
			m_pos.m_x++;
			m_pos.m_y--;
			m_now_jump_height++;
			// ジャンプした高さがジャンプ力分に達した場合
			if (m_now_jump_height >= RUNGAME_PLAYER_JUMP_HEIGHT) {
				m_now_jump_height = 0;
				// 地面と当たっていた場合、状態をRUNに移行
				if (m_p_map->IsHitGround(m_pos)) {
					m_now_state = RunGamePlayerState::RUN;
				}
				// 地面と当たっていなかった場合、状態をFALLに移行
				else {
					m_now_state = RunGamePlayerState::FALL;
				}
			}
			break;
		case RunGamePlayerState::FALL:
			m_pos.m_x++;
			m_pos.m_y++;
			// 地面と当たっていた場合
			if (m_p_map->IsHitGround(m_pos)) {
				m_now_state = RunGamePlayerState::RUN;
			}
			break;
		default:
			break;
		}

		// 壁と当たっていたら死亡フラグを立てる
		IsDead();
	}
}

void RunGamePlayer::Draw()
{
	m_p_map->SetPlayer(m_pos, m_my_param, m_head_param);
}

bool RunGamePlayer::IsClear()
{
	if (m_pos.m_x == RUNGAME_MAP_WIDTH - 1) {
		return true;
	}
	return false;
}

bool RunGamePlayer::IsDead()
{
	if (m_p_map->IsHitWall(m_pos)) {
		return true;
	}
	return false;
}