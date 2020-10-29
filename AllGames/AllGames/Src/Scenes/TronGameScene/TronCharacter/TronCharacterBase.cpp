#include "TronCharacterBase.h"

TronCharacterBase::TronCharacterBase() :
	m_current_pos{},
	m_p_map(nullptr)
{
}

TronCharacterBase::~TronCharacterBase()
{
}

void TronCharacterBase::Update()
{
	SelectMoveDirection();
}