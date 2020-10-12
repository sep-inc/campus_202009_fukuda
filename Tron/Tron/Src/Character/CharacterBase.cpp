#include "CharacterBase.h"

CharacterBase::CharacterBase():
	m_current_pos{},
	m_p_map(nullptr)
{
}

CharacterBase::~CharacterBase()
{
}

void CharacterBase::Update()
{
	SelectMoveDirection();
}

void CharacterBase::SetGameMapPointer(GameMap* map_)
{
	m_p_map = map_;
}
