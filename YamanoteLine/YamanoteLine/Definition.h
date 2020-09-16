#ifndef DEFINITION_H_
#define DEFINITION_H_

// �ǂݍ��ރf�[�^�̐��@�����I�ɃT�C�Y���m�ۂ��鏈�����ł�����A����
#define MAX_DATA_NUM 29

// �w���̍ő啶����
#define MAX_STATION_NAME_NUM 32


// �����X�e�b�v
enum class Step :int {
	STEP_NONE,
	STEP_INITIALIZE,	// �������X�e�b�v
	STEP_UPDATE,		// �X�V�X�e�b�v
	STEP_END,			// �j���X�e�b�v

	STEP_MAX
};

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

