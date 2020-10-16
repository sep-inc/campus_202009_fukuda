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

void GameMap::SetPos(PacMenObjectParam param_)
{
	m_game_map[param_.m_pos.m_y][param_.m_pos.m_x] = param_;
}

void GameMap::SetMovePos(PacMenObjectParam param_, Vec2 move_pos_)
{
	switch (param_.m_type) {
	case PacMenObjectType::PLAYER:
		if (m_game_map[move_pos_.m_y][move_pos_.m_x].m_type == PacMenObjectType::MONSTER) {
			// 自身の場所を空にする
			m_game_map[param_.m_pos.m_y][param_.m_pos.m_x] = m_empty;
		}
		else if (m_game_map[move_pos_.m_y][move_pos_.m_x].m_type == PacMenObjectType::ITEM) {
			// 自身の場所を空にして、移動先に移動する
			m_game_map[param_.m_pos.m_y][param_.m_pos.m_x] = m_empty;
			m_game_map[move_pos_.m_y][move_pos_.m_x] = param_;
		}
		break;
	case PacMenObjectType::MONSTER:
		// 自身の場所を空にして、移動先に移動する
		m_game_map[param_.m_pos.m_y][param_.m_pos.m_x] = m_empty;
		m_game_map[move_pos_.m_y][move_pos_.m_x] = param_;
		break;
	}
}

int GameMap::GetCanCreatePos(Vec2 list[CAN_CREATE_POS_NUM])
{
	int index = 0;
	// 外枠の壁を除いて空の場所を検索する
	for (int x = 1; x < PACMEN_DRAW_BUFFER_WIDTH - 1; x++) {
		for (int y = 1; y < PACMEN_DRAW_BUFFER_HEIGHT - 1; y++) {
			if (m_game_map[y][x].m_type == PacMenObjectType::TYPE_EMPTY) {
				Vec2 pos = { x,y };
				list[index] = pos;
				index++;
			}
		}
	}
	return index;
}

int GameMap::GetCanPlayerMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_CHARACTER_MOVE_POS_LIST])
{
	int tmp = 0;
	// 1マス上の検索
	if (m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type != PacMenObjectType::WALL) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y - 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス下の検索
	if (m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type != PacMenObjectType::WALL) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y + 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス左の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type != PacMenObjectType::WALL) {
		Vec2 pos = { now_pos_.m_x - 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス右の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x + 1].m_type != PacMenObjectType::WALL) {
		Vec2 pos = { now_pos_.m_x + 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	return tmp;
}

int GameMap::GetCanMonsterMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_CHARACTER_MOVE_POS_LIST])
{
	int tmp = 0;
	// 1マス上の検索
	if (m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type != PacMenObjectType::WALL &&
		m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type != PacMenObjectType::MONSTER) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y - 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス下の検索
	if (m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type != PacMenObjectType::WALL &&
		m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type != PacMenObjectType::MONSTER) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y + 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス左の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type != PacMenObjectType::WALL &&
		m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type != PacMenObjectType::MONSTER) {
		Vec2 pos = { now_pos_.m_x - 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス右の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x + 1].m_type != PacMenObjectType::WALL &&
		m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type != PacMenObjectType::MONSTER) {
		Vec2 pos = { now_pos_.m_x + 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	return tmp;
}

void GameMap::CreateInitGameMap()
{
	// 壁の定義
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

// 壁の配置
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
