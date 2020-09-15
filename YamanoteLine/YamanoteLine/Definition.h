#ifndef DEFINITION_H_
#define DEFINITION_H_

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
	char m_station_name;		// �w���ϐ�
	int m_right_station_time;	// �E�ׂ̉w�܂ł̎���
	int m_left_station_time;	// ���ׂ̉w�܂ł̎���
};




#endif

