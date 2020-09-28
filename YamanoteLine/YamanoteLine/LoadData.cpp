#include "LoadData.h"
#include "Global.h"
#include <cstdlib>

LoadData::LoadData():
	m_fp(nullptr)
{
}

LoadData::~LoadData()
{
}


void LoadData::Load()
{
	// 読み込んだデータをデータ管理クラスにセット
	g_array_station_data.SetLoadData(m_load_data, MAX_DATA_NUM);

	// OpenFile();
	// LoadFile();
	// CloseFile();
}

void LoadData::OpenFile()
{
	fopen_s(&m_fp,"Res/YamanoteLineData.bin", "r");
	
	if (m_fp == nullptr) {
		exit(0);
	}
	printf("ファイルオープン成功\n");
}

void LoadData::LoadFile()
{
	fread(m_load_data[0].m_station_name, sizeof(m_load_data[0].m_station_name), 1, m_fp);
	fread(&m_load_data[0].m_right_station_time, sizeof(m_load_data[0].m_right_station_time), 1, m_fp);

}

void LoadData::CloseFile()
{
	fclose(m_fp);
}
