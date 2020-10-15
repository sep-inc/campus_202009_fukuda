#include "GameMap.h"
#include <cstdlib>

GameMap::GameMap():
	m_init_game_map{nullptr},
	m_game_map{nullptr},
	m_p_wall(nullptr)
{
	if (m_p_wall == nullptr)
		m_p_wall = new Wall;
}

GameMap::~GameMap()
{
	if (m_p_wall != nullptr) {
		delete m_p_wall;
		m_p_wall = nullptr;
	}
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
	//! 空情報
	char empty_string[DRAW_STRING_SIZE] = "　";

	// ゲームマップを描画バッファに書き込む
	for (pos.m_y = 0; pos.m_y < PACMEN_DRAW_BUFFER_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < PACMEN_DRAW_BUFFER_WIDTH; pos.m_x++) {
			if (m_game_map[pos.m_y][pos.m_x] != nullptr) {
				drawer_->SetDrawBuffer(pos, m_game_map[pos.m_y][pos.m_x]->GetMyParam().m_draw_string);
			}
			else {
				drawer_->SetDrawBuffer(pos, empty_string);
			}
		}
	}
}

void GameMap::CreateInitGameMap()
{
	// 外枠作成
	for (int y = 0; y < PACMEN_DRAW_BUFFER_HEIGHT; y++) {
		m_init_game_map[y][0] = m_p_wall;
		m_init_game_map[y][PACMEN_DRAW_BUFFER_WIDTH - 1] = m_p_wall;
	}
	for (int x = 0; x < PACMEN_DRAW_BUFFER_WIDTH; x++) {
		m_init_game_map[0][x] = m_p_wall;
		m_init_game_map[PACMEN_DRAW_BUFFER_HEIGHT - 1][x] = m_p_wall;
	}

	// 壁データをもとにマップを作成
	for (int y = 1; y < PACMEN_DRAW_BUFFER_HEIGHT - 1; y++) {
		for (int x = 1; x < PACMEN_DRAW_BUFFER_WIDTH - 1; x++) {
			if (m_init_wall[y - 1][x - 1] == 1) {
				m_init_game_map[y][x] = m_p_wall;
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
