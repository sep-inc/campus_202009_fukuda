#include "Enemy.h"
#include <cstring>

Enemy::Enemy()
{
	m_param.m_type = ObjectType::ENEMY;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "Åü");
	m_current_pos.m_x = INIT_ENEMY_POS_X;
	m_current_pos.m_y = INIT_ENEMY_POS_Y;
}

Enemy::~Enemy()
{
}

void Enemy::SelectMoveDirection()
{
}
