#include "TronGame.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"
#include "../Draw/DrawerManager.h"
#include <string>

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
	DestroyObjects();
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
		// オブジェクト生成
		CreateObjects();

		// マップの初期化
		m_p_game_map->CreateInitGameMap();
		m_p_game_map->ClearGameMap();
		// 初期マップをセット
		m_p_game_map->InitDraw(DrawerManager::Instance()->m_p_drawer);

		// ゲームマップのポインタをセット
		m_p_player->SetGameMapPointer(m_p_game_map);
		m_p_enemy->SetGameMapPointer(m_p_game_map);

		m_step = TronGameStep::STEP_UPDATE;
		break;
	case TronGameStep::STEP_UPDATE:
		// プレイヤーの更新処理
		m_p_player->Update();
		// 更新情報をゲームマップにセット、trueが返ってくればゲーム終了処理へ
		m_cannot_move_player = m_p_game_map->SetMovePos(m_p_player->GetMovePos(), m_p_player->GetMyParam());
		// エネミーの更新処理
		m_p_enemy->Update();
		// 更新情報をゲームマップにセット、trueが返ってくればゲーム終了処理へ
		m_cannot_move_enemy = m_p_game_map->SetMovePos(m_p_enemy->GetMovePos(), m_p_enemy->GetMyParam());

		// 終了判定
		if (m_cannot_move_player == true ||
			m_cannot_move_enemy == true) {
			m_step = TronGameStep::STEP_END;
		}

		break;
	case TronGameStep::STEP_END:
		// オブジェクト破棄
		DestroyObjects();
		m_is_game_finish = true;
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

void TronGame::Draw()
{
	m_p_game_map->Draw(DrawerManager::Instance()->m_p_drawer);
}

void TronGame::SetResult()
{
	if (m_cannot_move_player == true &&
		m_cannot_move_enemy == true) {
		DrawerManager::Instance()->m_p_drawer->SetResultString("引き分け");
	}
	else if (m_cannot_move_enemy == true) {
		DrawerManager::Instance()->m_p_drawer->SetResultString("プレイヤーの勝利");
	}
	else if (m_cannot_move_player == true) {
		DrawerManager::Instance()->m_p_drawer->SetResultString("エネミーの勝利");
	}
}
