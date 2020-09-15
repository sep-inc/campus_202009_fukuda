#ifndef INPUT_H_
#define INPUT_H_

#include "Definition.h"

class Input {
public:
	Input();
	~Input();

	// 初期化関数
	void Init();
	// 更新関数
	void Update();
	// 出発駅名取得関数
	inline char GetDepartureStationName() const{
		return m_departure_station;
	}
	// 到着駅名取得関数
	inline char GetArrivalStationName() const {
		return m_arrival_station;
	}

private:
	// 入力待ち関数
	void WaitInput();

private:
	char m_departure_station;	// 出発駅名
	char m_arrival_station;		// 到着駅名
	Step m_step;				// 現在のステップ
	

};

#endif
