#ifndef DEFINITION_H_
#define DEFINITION_H_

// ESC�̃L�[�R�[�h
#define ESC (0x1B)

// �ǂݍ��ރf�[�^�̐��@�����I�ɃT�C�Y���m�ۂ��鏈�����ł�����A����
#define MAX_DATA_NUM 29

// �w���̍ő啶����
#define MAX_STATION_NAME_NUM 32

// �������̎���
#define CHUO_LINE_TIME 12


// �w�f�[�^�\����
struct StationData {
	char m_station_name[MAX_STATION_NAME_NUM];	// �w���ϐ�
	int m_right_station_time;	// �E�ׂ̉w�܂ł̎���
	int m_left_station_time;	// ���ׂ̉w�܂ł̎���
};

// �ǂݍ��ރf�[�^�p�̍\����
struct LoadDataParam {
	char m_station_name[MAX_STATION_NAME_NUM];
	int m_right_station_time;
};



#endif

