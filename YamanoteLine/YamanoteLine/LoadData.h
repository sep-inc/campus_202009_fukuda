#ifndef LOADDATA_H_
#define LOADDATA_H_

#include "Definition.h"
#include <cstdio>
#include <vector>

// �t�@�C���ǂݍ��݃N���X
class LoadData {
public:
	LoadData();
	~LoadData();

	// �ǂݍ��ݏ����֐�
	void Load();

private:
	// �t�@�C���I�[�v���֐�
	void OpenFile();	
	// �t�@�C���ǂݍ��݊֐�
	void LoadFile();	
	// �t�@�C���I���֐�
	void CloseFile();

private:
	// �ǂݍ��񂾉w�f�[�^�@���t�@�C���ǂݍ��ݏ����������������
	LoadDataParam m_load_data[MAX_DATA_NUM] = {
	{"�V�h"		,2},
	{"�V��v��"	,2},
	{"���c�n��"	,2},
	{"�ڔ�"		,3},
	{"�r��"		,2},
	{"���"		,2},
	{"����"		,2},
	{"�"		,2},
	{"�c�["		,2},
	{"�����闢"	,1},
	{"���闢"	,2},
	{"��J"		,2},
	{"���"		,2},
	{"��k��"	,2},
	{"�H�t��"	,2},
	{"�_�c"		,1},
	{"����"		,2},
	{"�L�y��"	,2},
	{"�V��"		,2},
	{"�l����"	,2},
	{"�c��"		,2},
	{"�i��"		,3},
	{"���"		,2},
	{"�ܔ��c"	,2},
	{"�ڍ�"		,3},
	{"�b���"	,2},
	{"�a�J"		,2},
	{"���h"		,2},
	{"��X��"	,2}
	};
	

	FILE* m_fp;				// �t�@�C���|�C���^�ϐ�
	// LoadDataParam m_load_data[MAX_DATA_NUM];	// �ǂݍ��񂾃f�[�^�̊i�[�z��
};

#endif

