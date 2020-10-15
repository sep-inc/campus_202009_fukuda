#include "GameMap.h"
#include <cstdlib>
#include <cstring>

GameMap::GameMap():
	m_init_game_map{},
	m_game_map{}
{
}

GameMap::~GameMap()
{
}

void GameMap::Init()
{
	//! 初期化マップの作成
	CreateInitGameMap();
	//! 初期化マップをゲームマップに反映
	ClearGameMap();
}

void GameMap::Draw(DrawerBase* drawer_)
{
	Vec2 pos;
	// ゲームマップを描画バッファに書き込む
	for (pos.m_y = 0; pos.m_y < PACMEN_DRAW_BUFFER_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < PACMEN_DRAW_BUFFER_WIDTH; pos.m_x++) {
			drawer_->SetDrawBuffer(pos, m_init_game_map[pos.m_y][pos.m_x].m_draw_string);
		}
	}
}

void GameMap::CreateInitGameMap()
{
	PacMenObjectParam wall;
	wall.m_type = PacMenObjectType::WALL;
	strcpy_s(wall.m_draw_string, DRAW_STRING_SIZE, "■");
	// 外枠作成
	for (int y = 0; y < PACMEN_DRAW_BUFFER_HEIGHT; y++) {
		m_init_game_map[y][0] = wall;
		m_init_game_map[y][PACMEN_DRAW_BUFFER_WIDTH - 1] = wall;
	}
	for (int x = 0; x < PACMEN_DRAW_BUFFER_WIDTH; x++) {
		m_init_game_map[0][x] = wall;
		m_init_game_map[PACMEN_DRAW_BUFFER_HEIGHT - 1][x] = wall;
	}

	// 壁データをもとにマップを作成
	for (int y = 1; y < PACMEN_DRAW_BUFFER_HEIGHT - 1; y++) {
		for (int x = 1; x < PACMEN_DRAW_BUFFER_WIDTH - 1; x++) {
			if (m_init_wall[y - 1][x - 1] == 1) {
				m_init_game_map[y][x] = wall;
			}
		}
	}
}

void GameMap::ClearGameMap()
{
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}

int GameMap::m_init_wall[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,1,0,1,1,0,0,0},
	{0,1,0,1,0,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,0,0,0,1,0,1,0},
	{0,1,0,1,1,0,1,1,0,0,0},
	{0,1,0,0,0,0,0,0,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0}
};
