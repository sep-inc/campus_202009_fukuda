#include "Player2.h"

Player2::Player2()
{
}

Player2::~Player2()
{
}

void Player2::Update()
{
	switch (m_step) {
	case Step::Initialize:
		Init();
		m_step = Step::Update;
		break;
	case Step::Update:
		break;
	case Step::End:
		break;
	}
}

void Player2::Init()
{
}

void Player2::SelectPiece()
{
}

void Player2::SelectMoveSquares()
{
}