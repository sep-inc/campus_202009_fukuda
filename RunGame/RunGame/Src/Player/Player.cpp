#include "Player.h"
#include "../Input/Input.h"
#include <cstring>

Player::Player():
	m_pos{},
	m_speed(PLAYER_MOVE_SPEED),
	m_now_jump_height(0),
	m_is_dead(false),
	m_now_state(PlayerState::RUN),
	m_p_map(nullptr)
{
}

Player::~Player()
{
}

void Player::Update()
{
	// 入力処理
	if (m_now_state == PlayerState::RUN) {
		if (Input::Instance()->PressSpaceKey(KeyType::SPACE_KEY)) {
			m_now_state = PlayerState::JUMP;
		}
	}
}

void Player::Init(GameMap* map_)
{
	m_my_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_my_param.m_draw_string, DRAW_STRING_SIZE, "▽");
	m_head_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_head_param.m_draw_string, DRAW_STRING_SIZE, "〇");

	m_pos.m_x = PLAYER_INIT_POS_X;
	m_pos.m_y = PLAYER_INIT_POS_Y;

	m_p_map = map_;
}

void Player::FixedUpdate(bool is_count_max_)
{
	if (is_count_max_ == true) {
		if (m_p_map->IsHitWall(m_pos)) {
			m_is_dead = true;
			return;
		}

		// 移動処理
		switch (m_now_state)
		{
		case PlayerState::RUN:
			m_pos.m_x++;
			if (!m_p_map->IsHitGround(m_pos)) {
				m_now_state = PlayerState::FALL;
			}
			break;
		case PlayerState::JUMP:
			m_pos.m_x++;
			m_pos.m_y--;
			m_now_jump_height++;
			if (m_now_jump_height >= PLAYER_JUMP_HEIGHT) {
				m_now_jump_height = 0;
				if (m_p_map->IsHitGround(m_pos)) {
					m_now_state = PlayerState::RUN;
				}
				else {
					m_now_state = PlayerState::FALL;
				}
			}
			break;
		case PlayerState::FALL:
			m_pos.m_x++;
			m_pos.m_y++;
			if (m_p_map->IsHitGround(m_pos)) {
				m_now_state = PlayerState::RUN;
			}
			break;
		default:
			break;
		}
	}
}

void Player::Draw()
{
	m_p_map->SetPlayer(m_pos, m_my_param, m_head_param);
}

bool Player::IsClear()
{
	if (m_pos.m_x == RUNGAME_MAP_WIDTH - 1) {
		return true;
	}
	return false;
}

bool Player::IsDead()
{
	return m_is_dead;
}
