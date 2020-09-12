#include "Bar.h"
#include "Global.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::Init(float pos_x, float pos_y, bool enable, Kind kind)
{
	ObjectBase::Init(pos_x, pos_y, enable, kind);
	m_speed = BAR_SPEED;
	m_vec.x = m_speed;
	m_vec.y = 0.f;
	m_size.width = BAR_WIDTH;
	m_size.height = BAR_HEIGHT;
}


void Bar::Update()
{
	switch (m_step) {
	case ObjectBase::Step::STEP_INITIALIZE:
		Init(BAR_INITIAL_X_POS, BAR_INITIAL_Y_POS, true, Kind::BAR);
		m_step = ObjectBase::Step::STEP_RUN;
		break;
	case ObjectBase::Step::STEP_RUN:
		HitWall();
		Move();
		break;
	case ObjectBase::Step::STEP_END:
		break;
	default:
		break;
	}
}

void Bar::SetUpDrawBuffer()
{
	g_drawer.SetBlankBuffer(m_pos.x, m_pos.y, m_kind, m_size.width, m_size.height);
}


void Bar::HitWall()
{
	if (HitLeftWall()) {
		m_vec.x = -m_vec.x;
	}
	else if (HitRightWall()) {
		m_vec.x = -m_vec.x;
	}
}

bool Bar::HitLeftWall()
{
	if (m_pos.x <= 0) {
		return true;
	}
	return false;
}

bool Bar::HitRightWall()
{
	if (m_pos.x >= GAME_WIDTH - BAR_WIDTH) {
		return true;
	}
	return false;
}

void Bar::Move()
{
	m_pos.x += m_vec.x;
}
