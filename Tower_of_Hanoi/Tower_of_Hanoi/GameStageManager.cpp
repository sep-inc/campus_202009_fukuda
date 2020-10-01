#include "GameStageManager.h"
#include "ObjectManager.h"


GameStageManager::GameStageManager():
	m_step(Step::Step_Initialize),
	m_piles{DiskType::Disk_Empty},
	m_draw_map{DrawType::Type_Empty}
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
		// ������
		Init();
		// �`��}�b�v�̏�����
		CreateDrawMapFrame();
		m_step = Step::Step_Update;
		break;
	case Step::Step_Update:
		// ���s���菈��
		if (IsClear()) {
			ObjectManager::Instance()->m_p_drawer->IsClear();
		}
		// �`��}�b�v�֕ϊ�
		ConvertDrawMap();
		// �`��}�b�v�̃Z�b�g
		SetDrawMap();
		ClearDrawMap();
		
		break;
	case Step::Step_End:
		break;
	default:
		break;
	}
}

void GameStageManager::Init()
{
	// ���[�̍Y�ɉ~�Ղ��Z�b�g����
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
	if (m_piles[source_pile_num][source_pile_index] == DiskType::Disk_Empty) {
		return false;
	}

	// �ړ���̍Y�̒��g����̏ꍇ
	if (m_piles[destination_pile_num][PILE_SIZE - 1] == DiskType::Disk_Empty) {
		// �~�Ղ��ړ�
		m_piles[destination_pile_num][PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}
	// �ړ���̍Y�̒��g����
	for (destination_pile_index = 0; destination_pile_index < PILE_SIZE; destination_pile_index++) {
		// �󂶂�Ȃ��ꏊ��������΃��[�v�I��
		if (m_piles[destination_pile_num][destination_pile_index] != DiskType::Disk_Empty) {
			break;
		}
	}
	// �ړ�������~�Ղƈړ���ɂ���~�Ղ��ׁA�ړ���̕����傫����Έړ�����
	if (static_cast<int>(m_piles[source_pile_num][source_pile_index]) < static_cast<int>(m_piles[destination_pile_num][destination_pile_index])
		&& destination_pile_index != 0) {
		// �~�Ղ̈ړ�����
		m_piles[destination_pile_num][destination_pile_index - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}
	// �ړ���̕����������~�ՂȂ�Έړ����s
	else {
		return false;
	}
	
}

bool GameStageManager::IsClear()
{
	// �E�[�̍Y�̂��ׂĂɉ~�Ղ������Ă�����Q�[���I���t���O�𗧂Ă�
	for (int i = 0; i < PILE_SIZE; i++) {
		if (m_piles[2][i] == DiskType::Disk_Empty) {
			return false;
		}
	}
	return true;
}

void GameStageManager::SetDrawMap()
{
	// �`��N���X�֕`��}�b�v���Z�b�g����
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			if (m_draw_map[x][y] != DrawType::Type_Empty) {
				ObjectManager::Instance()->m_p_drawer->SetDrawBuffer(x, y, m_draw_map[x][y]);
			}
		}
	}
}

void GameStageManager::CreateDrawMapFrame()
{
	// �Y�ԍ�
	m_draw_map[3][5] = DrawType::Type_Number1;
	m_draw_map[9][5] = DrawType::Type_Number2;
	m_draw_map[15][5] = DrawType::Type_Number3;
	// ���[�̍Y
	for (int x = 1; x <= 5; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// �^�񒆂̍Y
	for (int x = 7; x <= 11; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// �E�[�̍Y
	for (int x = 13; x <= 17; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}

	// Frame�̏���`��N���X�̏������o�b�t�@�֏�������
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			ObjectManager::Instance()->m_p_drawer->SetBlankBuffer(x, y, m_draw_map[x][y]);
		}
	}
}

void GameStageManager::ConvertDrawMap()
{
	// ���[�̍Y�̕`����Z�b�g
	for (int i = 0; i < PILE_SIZE; i++) {
		switch (m_piles[0][i]) {
		case DiskType::Large_Disk:
			m_draw_map[LEFT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Disk;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[LEFT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Small_Disk:
			m_draw_map[LEFT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[LEFT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[LEFT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[LEFT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		}
	}

	// �����̍Y�̕`����Z�b�g
	for (int i = 0; i < PILE_SIZE; i++) {
		switch (m_piles[1][i]) {
		case DiskType::Large_Disk:
			m_draw_map[CENTER_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Disk;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[CENTER_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Small_Disk:
			m_draw_map[CENTER_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[CENTER_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[CENTER_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[CENTER_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		}
	}

	// �E�[�̍Y�̕`����Z�b�g
	for (int i = 0; i < PILE_SIZE; i++) {
		switch (m_piles[2][i]) {
		case DiskType::Large_Disk:
			m_draw_map[RIGHT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Disk;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[RIGHT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Small_Disk:
			m_draw_map[RIGHT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[RIGHT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[RIGHT_PILE_POS_X][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 1][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 2][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 3][PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[RIGHT_PILE_POS_X + 4][PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		}
	}
}

void GameStageManager::ClearDrawMap()
{
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			m_draw_map[x][y] = DrawType::Type_Empty;
		}
	}
}
