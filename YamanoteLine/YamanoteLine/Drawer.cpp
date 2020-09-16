#include "Drawer.h"
#include <cstdio>

Drawer::Drawer():
	m_clock_wise_time(0),
	m_counter_clock_wise_time(0)
{
}

Drawer::~Drawer()
{
}

void Drawer::Draw()
{
	printf("右回りの時間 : %d\n", m_clock_wise_time);
	printf("左回りの時間 : %d\n", m_counter_clock_wise_time);
}
