#include "PacMenGameObject.h"

PacMenGameObject::PacMenGameObject():
	m_p_game_map(nullptr),
	m_is_delete(false)
{
}

PacMenGameObject::~PacMenGameObject()
{
}

void PacMenGameObject::Init(GameMap* map_)
{
	m_p_game_map = map_;
	m_p_game_map->SetPos(m_param);
}

void PacMenGameObject::Update()
{
	// 空
}

void PacMenGameObject::Draw(DrawerBase* drawer_)
{
	drawer_->SetDrawBuffer(m_param.m_pos, m_param.m_draw_string);
}

bool PacMenGameObject::CheckHit()
{
	return false;
}
