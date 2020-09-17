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
	printf("‰E‰ñ‚è‚ÌŠÔ : %d•ª\n", m_clock_wise_time);
	printf("¶‰ñ‚è‚ÌŠÔ : %d•ª\n", m_counter_clock_wise_time);
}
