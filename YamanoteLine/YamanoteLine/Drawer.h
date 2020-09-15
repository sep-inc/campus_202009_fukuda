#ifndef DRAWER_H_
#define DRAWER_H_

class Drawer {
public:
	Drawer();
	~Drawer();

	// 描画関数
	void Draw();

	// 時計回り時間セット関数
	inline void SetClockWiseTime(int time) {
		m_clock_wise_time = time;
	}
	// 反時計回り時間セット関数
	void SetCounterClockWiseTime(int time) {
		m_counter_clock_wise_time = time;
	}


private:
	int m_clock_wise_time;				// 時計回りの出発駅から到着駅までの時間
	int m_counter_clock_wise_time;		// 反時計回りの出発駅から到着駅までの時間

};

#endif
