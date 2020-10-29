#include "TronGameMap.h"
#include <cstring>

TronGameMap::TronGameMap() :
	m_init_game_map{},
	m_game_map{}
{
}

TronGameMap::~TronGameMap()
{
}

void TronGameMap::Init()
{
	// 初期マップの作成
	CreateInitGameMap();
	// ゲームマップを初期マップでクリア
	ClearGameMap();
}

void TronGameMap::Draw(DrawerBase* drawer_)
{
	Vec2_Int pos;
	// ゲームマップを描画バッファに書き込む
	for (pos.m_y = 0; pos.m_y < TRON_DRAW_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < TRON_DRAW_WIDTH; pos.m_x++) {
			drawer_->SetDrawBuffer(pos, m_game_map[pos.m_y][pos.m_x].m_draw_string);
		}
	}
}

void TronGameMap::GetCanMovePos(Vec2_Int now_pos_, Vec2_Int move_list_[TRON_CAN_MOVE_LIST_SIZE])
{
	// 要素数カウント用
	int tmp = 0;
	// 1マス上の検索
	if (m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type == TronGameObjectType::TYPE_EMPTY) {
		Vec2_Int pos = { now_pos_.m_x,now_pos_.m_y - 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス下の検索
	if (m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type == TronGameObjectType::TYPE_EMPTY) {
		Vec2_Int pos = { now_pos_.m_x,now_pos_.m_y + 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス左の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type == TronGameObjectType::TYPE_EMPTY) {
		Vec2_Int pos = { now_pos_.m_x - 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1マス右の検索
	if (m_game_map[now_pos_.m_y][now_pos_.m_x + 1].m_type == TronGameObjectType::TYPE_EMPTY) {
		Vec2_Int pos = { now_pos_.m_x + 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
}

bool TronGameMap::SetMovePos(Vec2_Int move_pos_, TronCharacterParam chara_)
{
	m_game_map[move_pos_.m_y][move_pos_.m_x] = chara_;
	// セットした座標から4方向を調べて、空の場所がなければfalse
	if (m_game_map[move_pos_.m_y - 1][move_pos_.m_x].m_type == TronGameObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y + 1][move_pos_.m_x].m_type == TronGameObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x - 1].m_type == TronGameObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x + 1].m_type == TronGameObjectType::TYPE_EMPTY)
	{
		return false;
	}
	return true;
}

void TronGameMap::CreateInitGameMap()
{
	// 壁情報の定義
	TronCharacterParam frame;
	frame.m_type = TronGameObjectType::FRAME;
	strcpy_s(frame.m_draw_string, TRON_DRAW_STRING_SIZE, "□");

	// 壁のセット
	for (int i = 0; i < TRON_DRAW_HEIGHT; i++) {
		m_init_game_map[i][0] = frame;
		m_init_game_map[i][TRON_DRAW_WIDTH - 1] = frame;
	}

	for (int i = 0; i < TRON_DRAW_WIDTH; i++) {
		m_init_game_map[0][i] = frame;
		m_init_game_map[TRON_DRAW_HEIGHT - 1][i] = frame;
	}

	// プレイヤーの初期位置セット
	TronCharacterParam player;
	player.m_type = TronGameObjectType::PLAYER;
	strcpy_s(player.m_draw_string, TRON_DRAW_STRING_SIZE, "■");
	m_init_game_map[TRON_INIT_PLAYER_POS_Y][TRON_INIT_PLAYER_POS_X] = player;

	// エネミーの初期位置セット
	TronCharacterParam enemy;
	enemy.m_type = TronGameObjectType::ENEMY;
	strcpy_s(enemy.m_draw_string, TRON_DRAW_STRING_SIZE, "◆");
	m_init_game_map[TRON_INIT_ENEMY_POS_Y][TRON_INIT_ENEMY_POS_X] = enemy;
}

void TronGameMap::ClearGameMap()
{
	// ゲームマップに初期マップをコピーする
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}