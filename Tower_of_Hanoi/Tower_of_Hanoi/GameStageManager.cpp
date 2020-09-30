#include "GameStageManager.h"


GameStageManager::GameStageManager():
	m_step(Step::Step_Initialize),
	m_piles{DiskType::Disk_Empty}
{
}


GameStageManager::~GameStageManager()
{
}

void GameStageManager::UpdateStep()
{
	switch (m_step)
	{
	case Step::Step_Initialize:
		Init();
		m_step = Step::Step_Update;
		break;
	case Step::Step_Update:
		
		break;
	case Step::Step_End:
		break;
	default:
		break;
	}
}

void GameStageManager::Init()
{
	m_piles[0][0] = DiskType::Small_Disk;
	m_piles[0][1] = DiskType::Normal_Disk;
	m_piles[0][2] = DiskType::Large_Disk;
}

bool GameStageManager::SetInputPileNums(int source_num, int destination_num)
{
	int source_pile_num = source_num - 1;			// �ړ����̍Y�ԍ�
	int destination_pile_num = destination_num - 1;	// �ړ���̍Y�ԍ�

	int source_pile_index = 0;		// �ړ����̍Y�̗v�f�ԍ�
	int destination_pile_index = 0; // �ړ���̍Y�̗v�f�ԍ�
	
	// �ړ����̍Y�ɉ~�Ղ����邩�ǂ���
	for (source_pile_index = 0; source_pile_index < PILE_SIZE; source_pile_index++) {
		// �~�Ղ�����ꍇ
		if (m_piles[source_pile_num][source_pile_index] != DiskType::Disk_Empty) {
			break;
		}
	}
	// �ړ����ɉ~�Ղ��Ȃ������ꍇ
	if (m_piles[source_num][source_pile_index] == DiskType::Disk_Empty) {
		return false;
	}

	// �ړ���̍Y�̒��g����̏ꍇ
	if (m_piles[destination_pile_num][PILE_SIZE - 1] == DiskType::Disk_Empty) {
		// �~�Ղ��ړ�
		m_piles[destination_pile_num][PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}

	// �~�Ղ̈ړ�
	m_piles[destination_pile_num][destination_pile_index] = m_piles[source_pile_num][source_pile_index];
	m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;

	while (destination_pile_index < PILE_SIZE - 1) {
		if (static_cast<int>(m_piles[destination_pile_num][destination_pile_index]) > 
			static_cast<int>(m_piles[destination_pile_num][destination_pile_index + 1])) {
			DiskType tmp = m_piles[destination_pile_num][destination_pile_index + 1];
			m_piles[destination_pile_num][destination_pile_index + 1] = m_piles[destination_pile_num][destination_pile_index];
			m_piles[destination_pile_num][destination_pile_index] = tmp;
		}
		else {
			break;
		}
	}

	return true;
}

bool GameStageManager::IsClear()
{
	for (int i = 0; i < PILE_SIZE; i++) {
		if (m_piles[2][i] == DiskType::Disk_Empty) {
			return false;
		}
	}
	return true;
}
