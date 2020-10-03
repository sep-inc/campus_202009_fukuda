#include "PlayerBase.h"


PlayerBase::PlayerBase():
	m_step(Step::Initialize),
	m_select_pos{},
	m_move_pos{}
{
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::MovePiece()
{
}
