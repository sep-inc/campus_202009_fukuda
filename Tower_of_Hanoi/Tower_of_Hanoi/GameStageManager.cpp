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
	int source_pile_num = source_num - 1;			// 移動元の杭番号
	int destination_pile_num = destination_num - 1;	// 移動先の杭番号

	int source_pile_index = 0;		// 移動元の杭の要素番号
	int destination_pile_index = 0; // 移動先の杭の要素番号
	
	// 移動元の杭に円盤があるかどうか
	for (source_pile_index = 0; source_pile_index < PILE_SIZE; source_pile_index++) {
		// 円盤がある場合
		if (m_piles[source_pile_num][source_pile_index] != DiskType::Disk_Empty) {
			break;
		}
	}
	// 移動元に円盤がなかった場合
	if (m_piles[source_num][source_pile_index] == DiskType::Disk_Empty) {
		return false;
	}

	// 移動先の杭の中身が空の場合
	if (m_piles[destination_pile_num][PILE_SIZE - 1] == DiskType::Disk_Empty) {
		// 円盤を移動
		m_piles[destination_pile_num][PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}

	// 円盤の移動
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
