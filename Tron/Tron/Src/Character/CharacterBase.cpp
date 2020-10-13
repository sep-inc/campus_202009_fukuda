#include "CharacterBase.h"

CharacterBase::CharacterBase():
	m_current_pos{},
	m_p_map(nullptr)
{
}

CharacterBase::~CharacterBase()
{
}

void CharacterBase::Init(GameMap* map_)
{
	m_p_map = map_;
}

void CharacterBase::Update()
{
	SelectMoveDirection();
}
