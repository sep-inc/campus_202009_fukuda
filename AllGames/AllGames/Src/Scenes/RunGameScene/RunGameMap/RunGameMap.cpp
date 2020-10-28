#include "RunGameMap.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

RunGameMap::RunGameMap() :
	m_ground_map{ 0 },
	m_camera_pos{},
	m_camera_speed(RUNGAME_PLAYER_MOVE_SPEED)
{
	srand((unsigned)time(NULL));

	/*
	*	下記メンバ変数はInit関数内でも初期化を行う
	*	・m_ground_map
	*	・m_init_game_map
	*	・m_camera_pos
	*/
}

RunGameMap::~RunGameMap()
{
}


void RunGameMap::FixedUpdate(bool is_count_max_)
{
	if (is_count_max_ == true) {
		// マップ情報のクリア
		ClearMap();
		// カメラの更新処理
		UpdateCamera();
	}
}

void RunGameMap::Init()
{
	// マップの0クリア
	ZeroClearMaps();
	// マップの作成
	CreateMap();
	// ゲームマップへ作成情報を反映
	ConvertGameMap();
	// マップを初期化マップでクリア
	ClearMap();

	// 各メンバ変数初期化
	m_camera_pos.m_x = 0;
	m_camera_pos.m_y = 0;
}

void RunGameMap::Draw(DrawerBase* drawer_)
{
	Vec2_Int pos;
	for (pos.m_y = 0; pos.m_y < RUNGAME_DRAW_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < RUNGAME_DRAW_WIDTH; pos.m_x++) {
			drawer_->SetDrawBuffer(pos, m_game_map[m_camera_pos.m_y + pos.m_y][m_camera_pos.m_x + pos.m_x].m_draw_string);
		}
	}
}

void RunGameMap::SetPlayer(Vec2_Int player_pos_, RunGameObjectParam player_, RunGameObjectParam player_head_)
{
	// プレイヤー情報セット
	if (player_pos_.m_y >= 0) {
		m_game_map[player_pos_.m_y][player_pos_.m_x] = player_;
	}
	// プレイヤーの上半身情報をセット
	if (player_pos_.m_y - 1 >= 0) {
		m_game_map[player_pos_.m_y - 1][player_pos_.m_x] = player_head_;
	}
}

bool RunGameMap::IsHitGround(Vec2_Int pos_)
{
	// 真下の地面か、1マス先の地面に当たっていたらtrue
	if (m_ground_map[pos_.m_y + 1][pos_.m_x] == 1 ||
		m_ground_map[pos_.m_y + 1][pos_.m_x + 1] == 1) {
		return true;
	}
	return false;
}

bool RunGameMap::IsHitWall(Vec2_Int pos_)
{
	// 現在地が壁と重なっていたら
	if (m_ground_map[pos_.m_y][pos_.m_x] == 1) {
		return true;
	}
	return false;
}

void RunGameMap::CreateMap()
{
	int num = 0;	// 追加する番号

	// 最初のみ平坦な地形にする
	AddMapParts(m_map_pattern1, RUNGAME_MAP_HEIGHT, num);
	num++;

	// 地形パターンからランダムで選択
	while (num < RUNGAME_MAP_WIDTH / RUNGAME_MAP_PARTS_WIDTH) {
		int rand_num = rand() % RUNGAME_MAP_PARTS_NUM;
		switch (rand_num)
		{
		case 0:
			AddMapParts(m_map_pattern1, RUNGAME_MAP_HEIGHT, num);
			break;
		case 1:
			AddMapParts(m_map_pattern2, RUNGAME_MAP_HEIGHT, num);
			break;
		case 2:
			AddMapParts(m_map_pattern3, RUNGAME_MAP_HEIGHT, num);
			break;
		case 3:
			AddMapParts(m_map_pattern4, RUNGAME_MAP_HEIGHT, num);
			break;
		default:
			break;
		}
		num++;
	}
}

void RunGameMap::AddMapParts(int parts_[][RUNGAME_MAP_PARTS_WIDTH], int height_, int add_num_)
{
	// 生成範囲がマップの範囲を超えていない場合
	if (add_num_ < RUNGAME_MAP_WIDTH / RUNGAME_MAP_PARTS_WIDTH) {
		for (int y = 0; y < height_; y++) {
			memcpy(&m_ground_map[y][add_num_ * RUNGAME_MAP_PARTS_WIDTH], parts_[y], sizeof(parts_[y]));
		}
	}
}

void RunGameMap::ConvertGameMap()
{
	// 地面の定義
	RunGameObjectParam ground;
	ground.m_type = RunGameObjectType::GROUND;
	strcpy_s(ground.m_draw_string, RUNGAME_DRAW_STRING_SIZE, "■");

	// 地面情報のセット
	for (int y = 0; y < RUNGAME_MAP_HEIGHT; y++) {
		for (int x = 0; x < RUNGAME_MAP_WIDTH; x++) {
			if (m_ground_map[y][x] == 1) {
				m_init_game_map[y][x] = ground;
			}
		}
	}

}

void RunGameMap::UpdateCamera()
{
	// カメラの範囲がマップの範囲を超えていない場合
	if (m_camera_pos.m_x + RUNGAME_DRAW_WIDTH < RUNGAME_MAP_WIDTH) {
		m_camera_pos.m_x++;
	}
}

void RunGameMap::ClearMap()
{
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}

void RunGameMap::ZeroClearMaps()
{
	RunGameObjectParam empty;
	for (int y = 0; y < RUNGAME_MAP_HEIGHT; y++) {
		for (int x = 0; x < RUNGAME_MAP_WIDTH; x++) {
			m_ground_map[y][x] = 0;
			m_init_game_map[y][x] = empty;
		}
	}
}

int RunGameMap::m_map_pattern1[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{0,0,0,0,0}
};

int RunGameMap::m_map_pattern2[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{0,0,0,0,0}
};

int RunGameMap::m_map_pattern3[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,1},
	{0,0,0,1,1},
	{0,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{0,0,0,0,0}
};

int RunGameMap::m_map_pattern4[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,0,0,0,1},
	{1,0,0,1,1},
	{1,1,1,1,1},
	{0,0,0,0,0}
};