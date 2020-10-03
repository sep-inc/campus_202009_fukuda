#include "Player1.h"

Player1::Player1()
{
}

Player1::~Player1()
{
}

void Player1::Update()
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

void Player1::Init()
{
}

void Player1::SelectPiece()
{
}

void Player1::SelectMoveSquares()
{
}
