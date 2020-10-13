#include "GameMap.h"
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
	// 初期マップの作成
	CreateInitGameMap();
	// ゲームマップを初期マップでクリア
	ClearGameMap();
}

void GameMap::Draw(DrawerBase* drawer_)
{
	Vec2 pos;
	// ゲームマップを描画バッファに書き込む
	for (pos.m_y = 0; pos.m_y < TRON_DRAW_BUFFER_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < TRON_DRAW_BUFFER_WIDTH; pos.m_x++) {
			drawer_->SetDrawBuffer(pos, m_game_map[pos.m_y][pos.m_x].m_draw_string);
		}
	}
}

void GameMap::GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE])
{
	// 要素数カウント用
	int tmp = 0;
	// 1マス上の検索
	if (m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y - 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス下の検索
	if (m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y + 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス左の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x - 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス右の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x + 1].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x + 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
}

bool GameMap::SetMovePos(Vec2 move_pos_, CharacterParam chara_)
{
	m_game_map[move_pos_.m_y][move_pos_.m_x] = chara_;
	// セットした座標から4方向を調べて、空の場所がなければfalse
	if (m_game_map[move_pos_.m_y - 1][move_pos_.m_x].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y + 1][move_pos_.m_x].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x - 1].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x + 1].m_type == ObjectType::TYPE_EMPTY) 
	{
		return false;
	}
	return true;
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

	// プレイヤーの初期位置セット
	CharacterParam player;
	player.m_type = ObjectType::PLAYER;
	strcpy_s(player.m_draw_string, DRAW_STRING_SIZE, "■");
	m_init_game_map[INIT_PLAYER_POS_Y][INIT_PLAYER_POS_X] = player;

	// エネミーの初期位置セット
	CharacterParam enemy;
	enemy.m_type = ObjectType::ENEMY;
	strcpy_s(enemy.m_draw_string, DRAW_STRING_SIZE, "◆");
	m_init_game_map[INIT_ENEMY_POS_Y][INIT_ENEMY_POS_X] = enemy;
}

void GameMap::ClearGameMap()
{
	// ゲームマップに初期マップをコピーする
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}


