#include "Player.h"
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

Vec2 Player::SelectMovePos()
{
	return m_param.m_pos;
}
