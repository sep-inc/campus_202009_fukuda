#include "GameMap.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

GameMap::GameMap():
	m_ground_map{0}
{
	srand((unsigned)time(NULL));
}

GameMap::~GameMap()
{
}


void GameMap::Init()
{
	// マップの作成
	CreateMap();
	// ゲームマップへ作成情報を反映
	ConvertGameMap();
}

void GameMap::Draw(DrawerBase* drawer_)
{
	Vec2 pos;
	for (pos.m_y = 0; pos.m_y < RUNGAME_DRAW_BUFFER_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < RUNGAME_DRAW_BUFFER_WIDTH; pos.m_x++) {
			drawer_->SetDrawBuffer(pos, m_game_map[pos.m_y][pos.m_x].m_draw_string);
		}
	}
}

void GameMap::CreateMap()
{
	int num = 0;
	while (num * RUNGAME_MAP_PARTS_WIDTH <= RUNGAME_MAP_PARTS_WIDTH) {
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

void GameMap::AddMapParts(int parts_[][RUNGAME_MAP_PARTS_WIDTH], int height_, int add_num_)
{
	// 追加するパーツがマップのサイズを超えていない場合
	if (add_num_ * RUNGAME_MAP_PARTS_WIDTH <= RUNGAME_MAP_WIDTH) {
		for (int y = 0; y < height_; y++) {
			memcpy(&m_ground_map[y][add_num_ * RUNGAME_MAP_PARTS_WIDTH], parts_[y], sizeof(parts_[y]));
		}
	}
}

void GameMap::ConvertGameMap()
{
	ObjectParam ground;
	ground.m_type = ObjectType::GROUND;
	strcpy_s(ground.m_draw_string, DRAW_STRING_SIZE, "■");
	
	for (int y = 0; y < RUNGAME_MAP_HEIGHT; y++) {
		for (int x = 0; x < RUNGAME_MAP_WIDTH; x++) {
			if (m_ground_map[y][x] == 1) {
				m_game_map[y][x] = ground;
			}
		}
	}

}

int GameMap::m_map_pattern1[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
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

int GameMap::m_map_pattern2[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
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

int GameMap::m_map_pattern3[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
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

int GameMap::m_map_pattern4[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH] =
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