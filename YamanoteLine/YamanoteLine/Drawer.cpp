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
	// 全パターン表示
	printf("時計回りの時間 : %d分\n", m_clock_wise_time);
	printf("反時計回りの時間 : %d分\n", m_counter_clock_wise_time);
	printf("中央線を利用した時計回りの時間 : %d分\n", m_clock_wise_time2);
	printf("中央線を利用した反時計回りの時間 : %d分\n", m_counter_clock_wise_time2);

	// 最短ルート表示
	switch (CalcFastestRoute()) {
	case Route::Route_Clock_Wise:
		printf("最短ルート : 時計回り\n時間 : %d分\n", m_clock_wise_time);
		break;
	case Route::Route_Counter_Clock_Wise:
		printf("最短ルート : 反時計回り\n時間 : %d分\n", m_counter_clock_wise_time);
		break;
	case Route::Route_Clock_Wise2:
		printf("最短ルート : 中央線を利用した時計回り\n時間 : %d分\n", m_clock_wise_time2);
		break;
	case Route::Route_Counter_Clock_Wise2:
		printf("最短ルート : 中央線を利用した反時計回り\n時間 : %d分\n", m_counter_clock_wise_time2);
		break;
	default:
		break;
	}
}

Route Drawer::CalcFastestRoute()
{
	// 初期値を時計回りにセット
	int fastest_route_time = m_clock_wise_time;
	Route fastest_route = Route::Route_Clock_Wise;
	
	// 反時計回りルートと比較
	if (fastest_route_time > m_counter_clock_wise_time) {
		fastest_route_time = m_counter_clock_wise_time;
		fastest_route = Route::Route_Counter_Clock_Wise;
	}
	// 中央線を利用した時計回りルートと比較
	if (fastest_route_time > m_clock_wise_time2) {
		fastest_route_time = m_clock_wise_time2;
		fastest_route = Route::Route_Clock_Wise2;
	}
	// 中央線を利用した反時計回りルートと比較
	if (fastest_route_time > m_counter_clock_wise_time2) {
		fastest_route_time = m_counter_clock_wise_time2;
		fastest_route = Route::Route_Counter_Clock_Wise2;
	}

	return fastest_route;
}
