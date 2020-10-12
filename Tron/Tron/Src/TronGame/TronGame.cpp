#include "TronGame.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"
#include "../Draw/DrawerManager.h"

TronGame* TronGame::p_instance = 0;

TronGame::TronGame():
	m_p_player(nullptr),
	m_p_enemy(nullptr),
	m_p_game_map(nullptr),
	m_step(TronGameStep::STEP_INITIALIZE),
	m_cannot_move_player(false),
	m_cannot_move_enemy(false),
	m_is_game_finish(false)
{
}

TronGame::~TronGame()
{
}

TronGame* TronGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new TronGame;
	}
	return p_instance;
}

void TronGame::Update()
{
	switch (m_step) {
	case TronGameStep::STEP_INITIALIZE:
		CreateObjects();

		//! マップの初期化
		m_p_game_map->CreateInitGameMap();
		m_p_game_map->ClearGameMap();
		SetBlankMap();

		break;
	case TronGameStep::STEP_UPDATE:
		break;
	case TronGameStep::STEP_END:
		DestroyObjects();
		break;
	}
}

void TronGame::CreateObjects()
{
	if (m_p_player == nullptr)
		m_p_player = new Player;
	if (m_p_enemy == nullptr)
		m_p_enemy = new Enemy;
	if (m_p_game_map == nullptr)
		m_p_game_map = new GameMap;
}

void TronGame::DestroyObjects()
{
	if (m_p_player != nullptr) {
		delete m_p_player;
		m_p_player = nullptr;
	}
	if (m_p_enemy != nullptr) {
		delete m_p_enemy;
		m_p_enemy = nullptr;
	}
	if (m_p_game_map != nullptr) {
		delete m_p_game_map;
		m_p_game_map = nullptr;
	}

}

void TronGame::SetBlankMap()
{
	Vec2 pos;
	// 初期マップの情報を初期化バッファに書き込む
	for (pos.m_y = 0; pos.m_y < TRON_DRAW_BUFFER_HEIGHT; pos.m_y++) {
		for (pos.m_x = 0; pos.m_x < TRON_DRAW_BUFFER_WIDTH; pos.m_x++) {
			DrawerManager::Instance()->m_p_drawer->SetBlankBuffer(pos, m_p_game_map->GetDrawString(pos));
		}
	}
}

void TronGame::SetDrawMap()
{
	Vec2 pos;
	// ゲームマップを描画バッファに書き込む
	for (pos.m_y = 1; pos.m_y < TRON_DRAW_BUFFER_HEIGHT - 1; pos.m_y++) {
		for (pos.m_x = 1; pos.m_x < TRON_DRAW_BUFFER_WIDTH - 1; pos.m_x++) {
			DrawerManager::Instance()->m_p_drawer->SetDrawBuffer(pos, m_p_game_map->GetDrawString(pos));
		}
	}
}
