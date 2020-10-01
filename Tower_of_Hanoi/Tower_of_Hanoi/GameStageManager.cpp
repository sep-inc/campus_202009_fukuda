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
		// 初期化
		Init();
		// 描画マップの初期化
		CreateDrawMapFrame();
		m_step = Step::Step_Update;
		break;
	case Step::Step_Update:
		// 勝敗判定処理
		if (IsClear()) {
			ObjectManager::Instance()->m_p_drawer->IsClear();
		}
		// 描画マップへ変換
		ConvertDrawMap();
		// 描画マップのセット
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
	// 左端の杭に円盤をセットする
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
	if (m_piles[source_pile_num][source_pile_index] == DiskType::Disk_Empty) {
		return false;
	}

	// 移動先の杭の中身が空の場合
	if (m_piles[destination_pile_num][PILE_SIZE - 1] == DiskType::Disk_Empty) {
		// 円盤を移動
		m_piles[destination_pile_num][PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}
	// 移動先の杭の中身検索
	for (destination_pile_index = 0; destination_pile_index < PILE_SIZE; destination_pile_index++) {
		// 空じゃない場所が見つかればループ終了
		if (m_piles[destination_pile_num][destination_pile_index] != DiskType::Disk_Empty) {
			break;
		}
	}
	// 移動させる円盤と移動先にある円盤を比べ、移動先の方が大きければ移動する
	if (static_cast<int>(m_piles[source_pile_num][source_pile_index]) < static_cast<int>(m_piles[destination_pile_num][destination_pile_index])
		&& destination_pile_index != 0) {
		// 円盤の移動処理
		m_piles[destination_pile_num][destination_pile_index - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = DiskType::Disk_Empty;
		return true;
	}
	// 移動先の方が小さい円盤ならば移動失敗
	else {
		return false;
	}
	
}

bool GameStageManager::IsClear()
{
	// 右端の杭のすべてに円盤が入っていたらゲーム終了フラグを立てる
	for (int i = 0; i < PILE_SIZE; i++) {
		if (m_piles[2][i] == DiskType::Disk_Empty) {
			return false;
		}
	}
	return true;
}

void GameStageManager::SetDrawMap()
{
	// 描画クラスへ描画マップをセットする
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
	// 杭番号
	m_draw_map[3][5] = DrawType::Type_Number1;
	m_draw_map[9][5] = DrawType::Type_Number2;
	m_draw_map[15][5] = DrawType::Type_Number3;
	// 左端の杭
	for (int x = 1; x <= 5; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// 真ん中の杭
	for (int x = 7; x <= 11; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}
	// 右端の杭
	for (int x = 13; x <= 17; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = DrawType::Type_Pile;
		}
	}

	// Frameの情報を描画クラスの初期化バッファへ書き込む
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			ObjectManager::Instance()->m_p_drawer->SetBlankBuffer(x, y, m_draw_map[x][y]);
		}
	}
}

void GameStageManager::ConvertDrawMap()
{
	// 左端の杭の描画情報セット
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

	// 中央の杭の描画情報セット
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

	// 右端の杭の描画情報セット
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
