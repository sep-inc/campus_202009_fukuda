#ifndef LOADDATA_H_
#define LOADDATA_H_

#include "Definition.h"

// �t�@�C���ǂݍ��݃N���X
class LoadData {
public:
	LoadData();
	~LoadData();

	// �X�V�֐�
	void Update();

private:
	// �t�@�C���I�[�v���֐�
	void OpenFile();	
	// �t�@�C���ǂݍ��݊֐�
	void LoadFile();	
	// �t�@�C���I���֐�
	void CloseFile();

private:
	StationData m_load_data;	// �ǂݍ��񂾃f�[�^�̊i�[�z��
	Step m_step;				// ���݂̃X�e�b�v

};

#endif

