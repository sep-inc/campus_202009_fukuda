#include "PlayerBase.h"

PlayerBase::PlayerBase():
	m_step(Step::Initialize),
	m_select_pos{},
	m_move_pos{},
	m_take_piece(ObjectType::Type_Empty)
{
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::MovePiece()
{
}

bool PlayerBase::IsTakeKing()
{
	// æ‚Á‚½‹î‚Ì•Ï”‚É‰¤‚ª“ü‚Á‚Ä‚¢‚ê‚Îtrue
	if (m_take_piece == ObjectType::King1 || m_take_piece == ObjectType::King2) {
		return true;
	}
	return false;
}
