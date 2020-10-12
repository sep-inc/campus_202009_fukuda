#include "GameMap.h"
#include <cstring>

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::ClearGameMap()
{
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}

void GameMap::CreateInitGameMap()
{
	// 壁情報の定義
	CharacterParam frame;
	frame.m_type = ObjectType::FRAME;
	strcpy_s(frame.m_draw_string, DRAW_STRING_SIZE, "□");

	// 壁のセット
	for (int i = 0; i < TRON_DRAW_BUFFER_HEIGHT; i++) {
		m_init_game_map[i][0] = frame;
		m_init_game_map[i][TRON_DRAW_BUFFER_WIDTH - 1] = frame;
	}

	for (int i = 0; i < TRON_DRAW_BUFFER_WIDTH; i++) {
		m_init_game_map[0][i] = frame;
		m_init_game_map[TRON_DRAW_BUFFER_HEIGHT - 1][i] = frame;
	}
}

char* GameMap::GetDrawString(Vec2 pos_)
{
	return m_game_map[pos_.m_y][pos_.m_x].m_draw_string;
}
