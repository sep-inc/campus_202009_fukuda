#include "ArrayStationData.h"

ArrayStationData::ArrayStationData():
	m_station_data_array{},
	m_departure_station('\0'),
	m_arrival_station('\0'),
	m_step(Step::STEP_INITIALIZE)
{
}

ArrayStationData::~ArrayStationData()
{
}

void ArrayStationData::Init()
{
}

void ArrayStationData::Update()
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

void ArrayStationData::CalcClockWiseTime()
{
}

void ArrayStationData::CalCounterClockWiseTime()
{
}
