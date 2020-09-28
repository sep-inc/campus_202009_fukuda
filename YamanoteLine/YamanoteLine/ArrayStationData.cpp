#include "ArrayStationData.h"
#include "Global.h"
#include <cstdio>
#include <cstring>

ArrayStationData::ArrayStationData():
	m_station_data_array{},
	m_departure_station{},
	m_departure_station_data_id(0),
	m_arrival_station{},
	m_arrival_station_data_id(0)
{
}

ArrayStationData::~ArrayStationData()
{
}

void ArrayStationData::Update()
{
	// �e�v�Z���Ԍ��ʂ�Drawer�N���X�ɔ��f
	g_drawer.SetClockWiseTime(CalcClockWiseTime(m_departure_station_data_id, m_arrival_station_data_id));
	g_drawer.SetCounterClockWiseTime(CalcCounterClockWiseTime(m_departure_station_data_id, m_arrival_station_data_id));
	g_drawer.SetClockWiseTime2(CalcClockWiseTime2());
	g_drawer.SetCounterClockWiseTime2(CalcCounterClockWiseTime2());
}

void ArrayStationData::SetLoadData(LoadDataParam *data, int data_size)
{
	for (int i = 0; i < data_size; i++) {
		// �w���i�[����
		strcpy(m_station_data_array[i].m_station_name, data[i].m_station_name);
		// �E�ׂ̉w�ւ̎��Ԋi�[����
		m_station_data_array[i].m_right_station_time = data[i].m_right_station_time;
		// ���ׂ̉w�ւ̎��Ԋi�[����
		if (i == 0) {
			m_station_data_array[i].m_left_station_time = data[data_size - 1].m_right_station_time;
		}
		else {
			m_station_data_array[i].m_left_station_time = m_station_data_array[i - 1].m_right_station_time;
		}
		// �V�h���_�c���z��ɓ������ۂ́A�������t���O��true�ɂ���
		if (strcmp(m_station_data_array[i].m_station_name, "�V�h") == 0) {
			m_shinjuku_data_id = i;
		}
		else if(strcmp(m_station_data_array[i].m_station_name, "�_�c") == 0){
			m_kanda_data_id = i;
		}
	}
}

bool ArrayStationData::SetDepartureStation(char* name)
{
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		// ���͂��ꂽ�w�����f�[�^�ɂ����true��Ԃ�
		if (strcmp(name, m_station_data_array[i].m_station_name) == 0) {
			strcpy(m_departure_station, name);
			m_departure_station_data_id = i;
			return true;
		}
	}
	return false;
}

bool ArrayStationData::SetArrivalStation(char* name)
{
	// �o���w�Ɠ����w�������͂��ꂽ�ꍇ
	if (strcmp(name, m_departure_station) == 0) {
		return false;
	}
	
	for (int i = 0; i < MAX_DATA_NUM; i++) {
		// ���͂��ꂽ�w�����f�[�^�ɂ����true��Ԃ�
		if (strcmp(name, m_station_data_array[i].m_station_name) == 0) {
			strcpy(m_arrival_station, name);
			m_arrival_station_data_id = i;
			return true;
		}
	}
	return false;
}

int ArrayStationData::CalcClockWiseTime(int start_station_id, int end_station_id)
{
	int sum_time = 0;	// �ʂ������Ԃ̍��v�l
	int start_id = start_station_id;	// ���ݒn��ID

	// ���ݒn�������w�ƈ�v����܂�
	while (start_id != end_station_id) {
		// �E�ׂ̉w�̎��Ԃ𑫂�
		sum_time += m_station_data_array[start_id].m_right_station_time;
		// ���ݒn���P�i�߂�
		start_id++;
		// ���ݒn���f�[�^ID�̍Ō�ɂȂ�����ID��0�ɖ߂�
		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	
	return sum_time;
}

int ArrayStationData::CalcCounterClockWiseTime(int start_station_id, int end_station_id)
{
	int sum_time = 0;	// �ʂ������Ԃ̍��v�l
	int start_id = start_station_id;	// ���ݒn��ID

	// ���ݒn�������w�ƈ�v����܂�
	while (start_id != end_station_id) {
		// �E�ׂ̉w�̎��Ԃ𑫂�
		sum_time += m_station_data_array[start_id].m_left_station_time;
		// ���ݒn���P�i�߂�i�����v�ɐi�ނ��߁A1�}�C�i�X����j
		start_id--;
		// ���ݒn���f�[�^ID�̍Ō�ɂȂ�����ID��0�ɖ߂�
		if (start_id < 0) {
			start_id = MAX_DATA_NUM - 1;
		}
	}

	return sum_time;
}

int ArrayStationData::CalcClockWiseTime2()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;
	bool is_passed_chuo_line = false;	// ��������ʉ߂������̃t���O

	while (start_id != m_arrival_station_data_id) {
		// ��������ʉ߂��Ă��Ȃ��ꍇ�̏���
		if (is_passed_chuo_line == false) {
			// �V�h�w���璆�����ɓ��鏈��
			if (start_id == m_shinjuku_data_id) {
				// �������̎��Ԃ𑫂�
				sum_time += CHUO_LINE_TIME;
				// �_�c�w�Ɉړ�
				start_id = m_kanda_data_id;
				// �ʉ߃t���O�𗧂Ă�
				is_passed_chuo_line = true;
			}
			// �_�c�w���璆�����ɓ��鏈��
			else if (start_id == m_kanda_data_id) {
				// �������̎��Ԃ𑫂�
				sum_time += CHUO_LINE_TIME;
				// �V�h�w�ֈړ�
				start_id = m_shinjuku_data_id;
				// �ʉ߃t���O�𗧂Ă�
				is_passed_chuo_line = true;
			}
			else {
				sum_time += m_station_data_array[start_id].m_right_station_time;
				start_id++;
			}
		}
		// ��������ʉ߂��Ă���ꍇ�̏���
		else {
			// ���������~�肽�w���瓞���w�܂ŁA���v���Ɣ����v���ł͂ǂ��炪�������̔�r
			if (CalcClockWiseTime(start_id, m_arrival_station_data_id) < CalcCounterClockWiseTime(start_id, m_arrival_station_data_id)) {
				// ���v���ԂɎ��v���̎��Ԃ𑫂��Čv�Z�I��
				sum_time += CalcClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
			else {
				// ���v���Ԃɔ����v���̎��Ԃ𑫂��Čv�Z�I��
				sum_time += CalcCounterClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
		}

		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	return sum_time;
}

int ArrayStationData::CalcCounterClockWiseTime2()
{
	int sum_time = 0;
	int start_id = m_departure_station_data_id;
	bool is_passed_chuo_line = false;	// ��������ʉ߂������̃t���O

	while (start_id != m_arrival_station_data_id) {
		// ��������ʉ߂��Ă��Ȃ��ꍇ�̏���
		if (is_passed_chuo_line == false) {
			// �V�h�w���璆�����ɓ��鏈��
			if (start_id == m_shinjuku_data_id) {
				// �������̎��Ԃ𑫂�
				sum_time += CHUO_LINE_TIME;
				// �_�c�w�Ɉړ�
				start_id = m_kanda_data_id;
				// �ʉ߃t���O�𗧂Ă�
				is_passed_chuo_line = true;
			}
			// �_�c�w���璆�����ɓ��鏈��
			else if (start_id == m_kanda_data_id) {
				// �������̎��Ԃ𑫂�
				sum_time += CHUO_LINE_TIME;
				// �V�h�w�ֈړ�
				start_id = m_shinjuku_data_id;
				// �ʉ߃t���O�𗧂Ă�
				is_passed_chuo_line = true;
			}
			else {
				sum_time += m_station_data_array[start_id].m_left_station_time;
				start_id--;
			}
		}
		// ��������ʉ߂��Ă���ꍇ�̏���
		else {
			// ���������~�肽�w���瓞���w�܂ŁA���v���Ɣ����v���ł͂ǂ��炪�������̔�r
			if (CalcClockWiseTime(start_id, m_arrival_station_data_id) < CalcCounterClockWiseTime(start_id, m_arrival_station_data_id)) {
				// ���v���ԂɎ��v���̎��Ԃ𑫂��Čv�Z�I��
				sum_time += CalcClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
			else {
				// ���v���Ԃɔ����v���̎��Ԃ𑫂��Čv�Z�I��
				sum_time += CalcCounterClockWiseTime(start_id, m_arrival_station_data_id);
				break;
			}
		}

		if (start_id == MAX_DATA_NUM) {
			start_id = 0;
		}
	}
	return sum_time;
}
