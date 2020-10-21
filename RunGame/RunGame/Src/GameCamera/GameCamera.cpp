#include "GameCamera.h"

GameCamera::GameCamera():
	m_pos{},
	m_speed(PLAYER_MOVE_SPEED)
{
}

GameCamera::~GameCamera()
{
}

void GameCamera::FixedUpdate(bool is_count_max_)
{
	if (is_count_max_ == true) {
		Move();
	}
}

void GameCamera::Init(Player* player_, GameMap* map_)
{
	m_pos.m_x = 0;
	m_pos.m_y = 0;

	m_p_player = player_;
	m_p_map = map_;
}

void GameCamera::Draw(DrawerBase* drawer_)
{
}

void GameCamera::Move()
{
}
