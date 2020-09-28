#include "ObjectBase.h"

ObjectBase::ObjectBase()
	: m_pos{},
	m_speed(0.f),
	m_kind(Kind::NONE),
	m_enable(false),
	m_step(ObjectBase::Step::STEP_INITIALIZE)
{
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Init(float pos_x, float pos_y, bool enable, Kind kind)
{
	m_pos.x = pos_x;
	m_pos.y = pos_y;
	m_enable = enable;
	m_kind = kind;
}

void ObjectBase::Update()
{
}

void ObjectBase::SetUpDrawBuffer()
{
}
