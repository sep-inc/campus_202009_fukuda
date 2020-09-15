#ifndef ARRAYSTATIONDATA_H_
#define ARRAYSTATIONDATA_H_

#include "Definition.h"

// �w�f�[�^�i�[�N���X
class ArrayStationData {
public:
	ArrayStationData();
	~ArrayStationData(); 

	// �X�V�֐�
	void Update();

private:
	// �E��莞�Ԍv�Z�֐�
	void CalcClockWiseTime();
	// ����莞�Ԍv�Z�֐�
	void CalCounterClockWiseTime();

private:
	StationData m_station_data_array;	// �w�f�[�^���i�[����z��
	char m_departure_station;			// �o���w��
	char m_arrival_station;				// �����w��

	Step m_step;						// ���݂̃X�e�b�v

};

#endif

