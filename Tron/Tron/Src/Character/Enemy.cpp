#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

Enemy::Enemy()
{
	m_param.m_type = ObjectType::ENEMY;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "Ÿ");
	m_current_pos.m_x = INIT_ENEMY_POS_X;
	m_current_pos.m_y = INIT_ENEMY_POS_Y;

	srand((unsigned)time(NULL));
}

Enemy::~Enemy()
{
}

void Enemy::SelectMoveDirection()
{
	// “ü—Í‰Â”\”ÍˆÍ‚ÌŽæ“¾
	Vec2 can_move_pos[CAN_MOVE_LIST_SIZE] = {};
	m_p_map->GetCanMovePos(m_current_pos, can_move_pos);

	int index_count = 0;
	for (int i = 0; i < CAN_MOVE_LIST_SIZE; i++) {
		if (can_move_pos[i].m_x != 0 && can_move_pos[i].m_y != 0) {
			index_count++;
		}
	}

	index_count--;
	int select_index = rand() % index_count;
	m_current_pos = can_move_pos[select_index];
}
