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
		// ‰Šú‰»
		Init();
		// •`‰æƒ}ƒbƒv‚Ì‰Šú‰»
		CreateDrawMapFrame();
		m_step = Step::Step_Update;
		break;
	case Step::Step_Update:
		// •`‰æƒ}ƒbƒv‚Ö•ÏŠ·
		// ConvertDrawMap();
		// •`‰æƒ}ƒbƒv‚ÌƒZƒbƒg
		// SetDrawMap();
		// Ÿ”s”»’èˆ—
		break;
	case Step::Step_End:
		break;
	default:
		break;
	}
}

void GameStageManager::Init()
{
	// ¶’[‚ÌY‚É‰~”Õ‚ğƒZƒbƒg‚·‚é
	m_piles[0][0] = DiskType::Small_Disk;
	m_piles[0][1] = DiskType::Normal_Disk;
	m_piles[0][2] = DiskType::Large_Disk;
}

bool GameStageManager::SetInputPileNums(int source_num, int destination_num)
{
	int source_pile_num = source_num - 1;			// ˆÚ“®Œ³‚ÌY”Ô†
	int destination_pile_num = destination_num - 1;	// ˆÚ“®æ‚ÌY”Ô†

	int source_pile_index = 0;		// ˆÚ“®Œ³‚ÌY‚Ì—v‘f”Ô†
	int destination_pile_index = 0; // ˆÚ“®æ‚ÌY‚Ì—v‘f”Ô†
	
	// ˆÚ“®Œ³‚ÌY‚É‰~”Õ‚ª‚ ‚é‚©‚Ç‚¤‚©
	for (source_pile_index = 0; source_pile_index < PILE_SIZE; source_pile_index++) {
		// ‰~”Õ‚ª‚ ‚éê‡
		if (m_piles[source_pile_num][source_pile_index] != DiskType::Disk_Empty) {
			break;
		}
	}
	// ˆÚ“®Œ³‚É‰~”Õ‚ª‚È‚©‚Á‚½ê‡
	if (m_piles[source_pile_num][source_pile_index] == DiskType::Disk_Empty) {
		return false;
	}

	// ˆÚ“®æ‚ÌY‚Ì’†g‚ª‹ó‚Ìê‡
	if (m_piles[destination_pile_num][PILE_SIZE - 1] == DiskType::Disk_Empty) {
		// ‰~”Õ‚ğˆÚ“®
		m_piles[destination_pile_num][PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}

	// ‰~”Õ‚ÌˆÚ“®
	m_piles[destination_pile_num][destination_pile_index] = m_piles[source_pile_num][source_pile_index];
	m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;

	// ˆÚ“®æ‚Ì‰~”Õ‚Ì•À‚Ñ‘Ö‚¦
	while (destination_pile_index < PILE_SIZE - 1) {
		// ‰º‚É‚ ‚é’†g‚æ‚èã‚Ì’†g‚ªd‚½‚¢‚È‚ç“ü‚ê‘Ö‚¦‚é
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
	// ‰E’[‚ÌY‚Ì‚·‚×‚Ä‚É‰~”Õ‚ª“ü‚Á‚Ä‚¢‚½‚çƒQ[ƒ€I—¹ƒtƒ‰ƒO‚ğ—§‚Ä‚é
	for (int i = 0; i < PILE_SIZE; i++) {
		if (m_piles[2][i] == DiskType::Disk_Empty) {
			return false;
		}
	}
	return true;
}

void GameStageManager::SetDrawMap()
{
	// •`‰æƒNƒ‰ƒX‚Ö•`‰æƒ}ƒbƒv‚ğƒZƒbƒg‚·‚é
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			ObjectManager::Instance()->m_p_drawer->SetDrawBuffer(x, y, m_draw_map[x][y]);
		}
	}
}

void GameStageManager::CreateDrawMapFrame()
{
	// Y”Ô†
	m_draw_map[3][5] = DrawType::Type_Number1;
	m_draw_map[9][5] = DrawType::Type_Number2;
	m_draw_map[15][5] = DrawType::Type_Number3;
	// ¶’[‚ÌY
	for (int x = 1; x <= 5; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// ^‚ñ’†‚ÌY
	for (int x = 7; x <= 11; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// ‰E’[‚ÌY
	for (int x = 13; x <= 17; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}

	// Frame‚Ìî•ñ‚ğ•`‰æƒNƒ‰ƒX‚Ì‰Šú‰»ƒoƒbƒtƒ@‚Ö‘‚«‚Ş
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			ObjectManager::Instance()->m_p_drawer->SetBlankBuffer(x, y, m_draw_map[x][y]);
		}
	}
}

void GameStageManager::ConvertDrawMap()
{
	
}
