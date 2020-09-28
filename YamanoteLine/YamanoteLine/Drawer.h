#ifndef DRAWER_H_
#define DRAWER_H_

enum class Route :int {
	Route_None,
	Route_Clock_Wise,			// 時計回りルート
	Route_Counter_Clock_Wise,	// 反時計回りルート
	Route_Clock_Wise2,			// 中央線を通る時計回りルート
	Route_Counter_Clock_Wise2,	// 中央線を通る反時計回りルート

	MAX_Route
};

class Drawer {
public:
	Drawer();
	~Drawer();

	// 描画関数
	void Draw();
	// 最短ルートの計算関数
	Route CalcFastestRoute();

public:
	// セット関数群
	// 時計回り時間セット関数
	inline void SetClockWiseTime(int time) {
		m_clock_wise_time = time;
	}

	// 反時計回り時間セット関数
	inline void SetCounterClockWiseTime(int time) {
		m_counter_clock_wise_time = time;
	}

	// 中央線ありの時計回り時間セット関数
	inline void SetClockWiseTime2(int time) {
		m_clock_wise_time2 = time;
	}

	// 中央線ありの反時計回り時間セット関数
	inline void SetCounterClockWiseTime2(int time) {
		m_counter_clock_wise_time2 = time;
	}


private:
	int m_clock_wise_time;				// 時計回りの出発駅から到着駅までの時間
	int m_counter_clock_wise_time;		// 反時計回りの出発駅から到着駅までの時間
	int m_clock_wise_time2;				// 時計回りかつ中央線ありの時間
	int m_counter_clock_wise_time2;		// 反時計回りかつ中央線ありの時間

};

#endif
