#include "LoadData.h"

LoadData::LoadData():
	m_load_data{},
	m_step(Step::STEP_INITIALIZE)
{
}

LoadData::~LoadData()
{
}

void LoadData::Init()
{
}

void LoadData::Update()
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

void LoadData::OpenFile()
{
}

void LoadData::LoadFile()
{
}

void LoadData::CloseFile()
{
}
