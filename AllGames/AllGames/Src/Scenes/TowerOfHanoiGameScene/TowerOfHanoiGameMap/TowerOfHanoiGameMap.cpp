#include "TowerOfHanoiGameMap.h"

GameStageManager::GameStageManager() :
	m_piles{ TowerOfHanoiDiskType::DISK_EMPTY },
	m_draw_map{ TowerOfHanoiObjectType::TYPE_EMPTY }
{

}


GameStageManager::~GameStageManager()
{
}

void GameStageManager::UpdateStep()
{
	// 勝敗判定処理
	// if (IsClear()) {
	// 	ObjectManager::Instance()->m_p_drawer->IsClear();
	// }
	// 描画マップへ変換
	ConvertDrawMap();
	// 描画マップのセット
	SetDrawMap();
	ClearDrawMap();
}

void GameStageManager::Init()
{
	// 左端の杭に円盤をセットする
	m_piles[0][0] = TowerOfHanoiDiskType::SMALL_DISK;
	m_piles[0][1] = TowerOfHanoiDiskType::NORMAL_DISK;
	m_piles[0][2] = TowerOfHanoiDiskType::LARGE_DISK;

	CreateDrawMapFrame();
}

bool GameStageManager::SetInputPileNums(int source_num, int destination_num)
{
	int source_pile_num = source_num - 1;			// 移動元の杭番号
	int destination_pile_num = destination_num - 1;	// 移動先の杭番号

	int source_pile_index = 0;		// 移動元の杭の要素番号
	int destination_pile_index = 0; // 移動先の杭の要素番号

	// 移動元の杭に円盤があるかどうか
	for (source_pile_index = 0; source_pile_index < TOWER_OF_HANOI_PILE_SIZE; source_pile_index++) {
		// 円盤がある場合
		if (m_piles[source_pile_num][source_pile_index] != TowerOfHanoiDiskType::DISK_EMPTY) {
			break;
		}
	}
	// 移動元に円盤がなかった場合
	if (m_piles[source_pile_num][source_pile_index] == TowerOfHanoiDiskType::DISK_EMPTY) {
		return false;
	}

	// 移動先の杭の中身が空の場合
	if (m_piles[destination_pile_num][TOWER_OF_HANOI_PILE_SIZE - 1] == TowerOfHanoiDiskType::DISK_EMPTY) {
		// 円盤を移動
		m_piles[destination_pile_num][TOWER_OF_HANOI_PILE_SIZE - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = TowerOfHanoiDiskType::DISK_EMPTY;
		return true;
	}
	// 移動先の杭の中身検索
	for (destination_pile_index = 0; destination_pile_index < TOWER_OF_HANOI_PILE_SIZE; destination_pile_index++) {
		// 空じゃない場所が見つかればループ終了
		if (m_piles[destination_pile_num][destination_pile_index] != TowerOfHanoiDiskType::DISK_EMPTY) {
			break;
		}
	}
	// 移動させる円盤と移動先にある円盤を比べ、移動先の方が大きければ移動する
	if (static_cast<int>(m_piles[source_pile_num][source_pile_index]) < static_cast<int>(m_piles[destination_pile_num][destination_pile_index])
		&& destination_pile_index != 0) {
		// 円盤の移動処理
		m_piles[destination_pile_num][destination_pile_index - 1] = m_piles[source_pile_num][source_pile_index];
		m_piles[source_pile_num][source_pile_index] = TowerOfHanoiDiskType::DISK_EMPTY;
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
	for (int i = 0; i < TOWER_OF_HANOI_PILE_SIZE; i++) {
		if (m_piles[2][i] == TowerOfHanoiDiskType::DISK_EMPTY) {
			return false;
		}
	}
	return true;
}

void GameStageManager::SetDrawMap()
{
	// 描画クラスへ描画マップをセットする
	for (int x = 0; x < TOWER_OF_HANOI_DRAW_WIDTH; x++) {
		for (int y = 0; y < TOWER_OF_HANOI_DRAW_HEIGHT; y++) {
			if (m_draw_map[x][y] != TowerOfHanoiObjectType::TYPE_EMPTY) {
				ObjectManager::Instance()->m_p_drawer->SetDrawBuffer(x, y, m_draw_map[x][y]);
			}
		}
	}
}

void GameStageManager::CreateDrawMapFrame()
{
	// 杭番号
	m_draw_map[3][5] = TowerOfHanoiObjectType::NUMBER1;
	m_draw_map[9][5] = TowerOfHanoiObjectType::NUMBER2;
	m_draw_map[15][5] = TowerOfHanoiObjectType::NUMBER3;
	// 左端の杭
	for (int x = 1; x <= 5; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = TowerOfHanoiObjectType::PILE;
		}
	}
	// 真ん中の杭
	for (int x = 7; x <= 11; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = TowerOfHanoiObjectType::PILE;
		}
	}
	// 右端の杭
	for (int x = 13; x <= 17; x++) {
		for (int y = 2; y <= 4; y++) {
			m_draw_map[x][y] = TowerOfHanoiObjectType::PILE;
		}
	}

	// Frameの情報を描画クラスの初期化バッファへ書き込む
	for (int x = 0; x < TOWER_OF_HANOI_DRAW_WIDTH; x++) {
		for (int y = 0; y < TOWER_OF_HANOI_DRAW_HEIGHT; y++) {
			ObjectManager::Instance()->m_p_drawer->SetBlankBuffer(x, y, m_draw_map[x][y]);
		}
	}
}

void GameStageManager::ConvertDrawMap()
{
	// 左端の杭の描画情報セット
	for (int i = 0; i < TOWER_OF_HANOI_PILE_SIZE; i++) {
		switch (m_piles[0][i]) {
		case DiskType::Large_Disk:
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			break;
		case DiskType::Small_Disk:
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::DISK;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			m_draw_map[TOWER_OF_HANOI_LEFT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = TowerOfHanoiObjectType::PILE;
			break;
		}
	}

	// 中央の杭の描画情報セット
	for (int i = 0; i < TOWER_OF_HANOI_PILE_SIZE; i++) {
		switch (m_piles[1][i]) {
		case DiskType::Large_Disk:
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Small_Disk:
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_CENTER_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		}
	}

	// 右端の杭の描画情報セット
	for (int i = 0; i < PILE_SIZE; i++) {
		switch (m_piles[2][i]) {
		case DiskType::Large_Disk:
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			break;
		case DiskType::Normal_Disk:
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Small_Disk:
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Disk;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		case DiskType::Disk_Empty:
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 1][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 2][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 3][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			m_draw_map[TOWER_OF_HANOI_RIGHT_PILE_POS_X + 4][TOWER_OF_HANOI_PILE_POS_Y + i] = DrawType::Type_Pile;
			break;
		}
	}
}

void GameStageManager::ClearDrawMap()
{
	for (int x = 0; x < TOWER_OF_HANOI_DRAW_WIDTH; x++) {
		for (int y = 0; y < TOWER_OF_HANOI_DRAW_HEIGHT; y++) {
			m_draw_map[x][y] = DrawType::Type_Empty;
		}
	}
}