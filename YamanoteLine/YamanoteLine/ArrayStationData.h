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

	// �Z�b�g�֐��Q
	// �ǂݍ��񂾃f�[�^���i�[�z��ɃZ�b�g����֐�
	void SetLoadData(LoadDataParam* data, int data_size);
	// ���͂��ꂽ�o���w�����Z�b�g����֐�
	bool SetDepartureStation(char* name);
	// ���͂��ꂽ�����w�����Z�b�g����֐�
	bool SetArrivalStation(char* name);

private:
	// ���Ԍv�Z�֐��Q
	// �E��莞�Ԍv�Z�֐��i��P�����F�o���wID, ��Q�����F�����wID�j
	int CalcClockWiseTime(int start_station_id, int end_station_id);
	// ����莞�Ԍv�Z�֐��i��P�����F�o���wID, ��Q�����F�����wID�j
	int CalcCounterClockWiseTime(int start_station_id, int end_station_id);
	// �E��肩����������̌v�Z
	int CalcClockWiseTime2();
	// ����肩����������̌v�Z
	int CalcCounterClockWiseTime2();

private:
	StationData m_station_data_array[MAX_DATA_NUM];	// �w�f�[�^���i�[����z��

	char m_departure_station[MAX_STATION_NAME_NUM];	// �o���w��
	int m_departure_station_data_id;				// �o���w�̃f�[�^ID		

	char m_arrival_station[MAX_STATION_NAME_NUM];	// �����w��
	int m_arrival_station_data_id;					// �����w�̃f�[�^ID

	int m_shinjuku_data_id;		// �V�h�̃f�[�^ID�ۑ��ϐ�
	int m_kanda_data_id;		// �_�c�̃f�[�^ID�ۑ��ϐ��@���������̏����Ɏg�p
};

#endif

