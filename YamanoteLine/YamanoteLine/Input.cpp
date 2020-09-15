#include "Input.h"

Input::Input():
	m_departure_station('\0'),
	m_arrival_station('\0'),
	m_step(Step::STEP_INITIALIZE)
{
}

Input::~Input()
{
}

void Input::Init()
{
}

void Input::Update()
{
	switch (m_step) {
	case Step::STEP_INITIALIZE:
		Init();
		m_step = Step::STEP_UPDATE;
		break;
	case Step::STEP_UPDATE:
		// çXêVèàóù
		break;
	case Step::STEP_END:
		break;
	default:
		break;
	}
}

void Input::WaitInput()
{
}
