#ifndef INPUT_H_
#define INPUT_H_

#include "Definition.h"

class Input {
public:
	Input();
	~Input();

	// �������֐�
	void Init();
	// �X�V�֐�
	void Update();
	// �o���w���擾�֐�
	inline char GetDepartureStationName() const{
		return m_departure_station;
	}
	// �����w���擾�֐�
	inline char GetArrivalStationName() const {
		return m_arrival_station;
	}

private:
	// ���͑҂��֐�
	void WaitInput();

private:
	char m_departure_station;	// �o���w��
	char m_arrival_station;		// �����w��
	Step m_step;				// ���݂̃X�e�b�v
	

};

#endif
