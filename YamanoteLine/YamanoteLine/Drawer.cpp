#include "Drawer.h"
#include <cstdio>

Drawer::Drawer():
	m_clock_wise_time(0),
	m_counter_clock_wise_time(0),
	m_clock_wise_time2(0),
	m_counter_clock_wise_time2(0)
{
}

Drawer::~Drawer()
{
}

void Drawer::Draw()
{
	// �S�p�^�[���\��
	printf("���v���̎��� : %d��\n", m_clock_wise_time);
	printf("�����v���̎��� : %d��\n", m_counter_clock_wise_time);
	printf("�������𗘗p�������v���̎��� : %d��\n", m_clock_wise_time2);
	printf("�������𗘗p���������v���̎��� : %d��\n", m_counter_clock_wise_time2);

	// �ŒZ���[�g�\��
	switch (CalcFastestRoute()) {
	case Route::Route_Clock_Wise:
		printf("�ŒZ���[�g : ���v���\n���� : %d��\n", m_clock_wise_time);
		break;
	case Route::Route_Counter_Clock_Wise:
		printf("�ŒZ���[�g : �����v���\n���� : %d��\n", m_counter_clock_wise_time);
		break;
	case Route::Route_Clock_Wise2:
		printf("�ŒZ���[�g : �������𗘗p�������v���\n���� : %d��\n", m_clock_wise_time2);
		break;
	case Route::Route_Counter_Clock_Wise2:
		printf("�ŒZ���[�g : �������𗘗p���������v���\n���� : %d��\n", m_counter_clock_wise_time2);
		break;
	default:
		break;
	}
}

Route Drawer::CalcFastestRoute()
{
	// �����l�����v���ɃZ�b�g
	int fastest_route_time = m_clock_wise_time;
	Route fastest_route = Route::Route_Clock_Wise;
	
	// �����v��胋�[�g�Ɣ�r
	if (fastest_route_time > m_counter_clock_wise_time) {
		fastest_route_time = m_counter_clock_wise_time;
		fastest_route = Route::Route_Counter_Clock_Wise;
	}
	// �������𗘗p�������v��胋�[�g�Ɣ�r
	if (fastest_route_time > m_clock_wise_time2) {
		fastest_route_time = m_clock_wise_time2;
		fastest_route = Route::Route_Clock_Wise2;
	}
	// �������𗘗p���������v��胋�[�g�Ɣ�r
	if (fastest_route_time > m_counter_clock_wise_time2) {
		fastest_route_time = m_counter_clock_wise_time2;
		fastest_route = Route::Route_Counter_Clock_Wise2;
	}

	return fastest_route;
}
