#include "Player.h"
#include <cstring>

Player::Player():
	m_pos{},
	m_speed(PLAYER_MOVE_SPEED),
	m_jump_height(PLAYER_JUMP_HEIGHT),
	m_now_state(PlayerState::RUN)
{
}

Player::~Player()
{
}

void Player::Update()
{
	// 入力受付
}

void Player::Init()
{
	m_my_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_my_param.m_draw_string, DRAW_STRING_SIZE, "▽");
	m_head_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_my_param.m_draw_string, DRAW_STRING_SIZE, "〇");

	m_pos.m_x = PLAYER_INIT_POS_X;
	m_pos.m_y = PLAYER_INIT_POS_Y;
}

void Player::FixedUpdate(bool is_count_max_)
{
	if (is_count_max_ == true) {


	}
}

void Player::Draw()
{
}
