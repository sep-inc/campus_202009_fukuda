#include "PacMenGame.h"
#include "../Draw/DrawerManager.h"
#include "../GameObject/Character/Player.h"
#include "../GameObject/Character/Monster.h"
#include "../GameObject/Item.h"

PacMenGame* PacMenGame::p_instance = 0;

PacMenGame::PacMenGame() :
	m_p_game_map(nullptr),
	m_p_player(nullptr),
	m_p_monsters{ PACMEN_MONSTER_NUM,nullptr },
	m_p_items{nullptr},
	m_step(PacMenGameStep::STEP_INITIALIZE),
	m_result(PacMenResult::NONE),
	m_item_delete_counter(0),
	m_is_game_finish(false)
{
}

PacMenGame::~PacMenGame()
{
	DestroyObjects();
}

void PacMenGame::Update()
{
	switch (m_step) {
	case PacMenGameStep::STEP_INITIALIZE:
		/* オブジェクトの生成 */
		CreateObjects();

		/* 初期化処理 */
		m_p_game_map->Init();
		m_p_player->Init(m_p_game_map);
		for (PacMenGameObject* e : m_p_monsters) {
			if (e != nullptr) {
				e->Init(m_p_game_map);
			}
		}
		for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
			m_p_items[i]->Init(m_p_game_map);
		}

		/* ステップ移行 */
		m_step = PacMenGameStep::STEP_UPDATE;
		break;

	case PacMenGameStep::STEP_UPDATE:
		/* 更新処理 */
		// アイテムの更新処理
		for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
			m_p_items[i]->Update();
		}
		// プレイヤーの更新処理
		m_p_player->Update();

		/* ゲームの終了判定 */
		if (CheckHitPlayer()) {
			m_step = PacMenGameStep::STEP_END;
			break;
		}
		if (CheckHitItems()) {
			m_step = PacMenGameStep::STEP_END;
			break;
		}

		/* モンスターの更新処理 */
		for (PacMenGameObject* e : m_p_monsters) {
			if (e != nullptr) {
				e->Update();
			}
		}

		/* ゲームの終了判定 */
		if (CheckHitPlayer()) {
			m_step = PacMenGameStep::STEP_END;
		}
		break;

	case PacMenGameStep::STEP_END:
		m_is_game_finish = true;
		DestroyObjects();
		break;
	}
}

void PacMenGame::Draw()
{
	// マップの描画処理
	m_p_game_map->Draw(DrawerManager::Instance()->m_p_drawer);
	// アイテムの描画処理
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		m_p_items[i]->Draw(DrawerManager::Instance()->m_p_drawer);
	}
	// プレイヤーの描画処理
	m_p_player->Draw(DrawerManager::Instance()->m_p_drawer);
	// モンスターの描画処理
	for (PacMenGameObject* e : m_p_monsters) {
		if (e != nullptr) {
			e->Draw(DrawerManager::Instance()->m_p_drawer);
		}
	}
}

void PacMenGame::SetResult()
{
	switch (m_result) {
	case PacMenResult::NONE:
		return;
	case PacMenResult::PLAYER_WIN:
		DrawerManager::Instance()->m_p_drawer->SetResultString("プレイヤーの勝利\n");
		return;
	case PacMenResult::PLAYER_LOSE:
		DrawerManager::Instance()->m_p_drawer->SetResultString("プレイヤーの敗北\n");
		return;
	}
}

void PacMenGame::CreateObjects()
{
	if (m_p_game_map == nullptr)
		m_p_game_map = new GameMap;
	if (m_p_player == nullptr)
		m_p_player = new Player;
	for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
		m_p_monsters.push_back(new Monster);
	}
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		m_p_items[i] = new Item(i + 1);
	}
}

void PacMenGame::DestroyObjects()
{
	if (m_p_game_map != nullptr) {
		delete m_p_game_map;
		m_p_game_map = nullptr;
	}
	if (m_p_player != nullptr) {
		delete m_p_player;
		m_p_player = nullptr;
	}
	for (PacMenGameObject* e : m_p_monsters) {
		if (e != nullptr) {
			delete e;
			e = nullptr;
		}
	}
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		if (m_p_items[i] != nullptr) {
			delete m_p_items[i];
			m_p_items[i] = nullptr;
		}
	}

}

bool PacMenGame::CheckHitPlayer()
{
	//プレイヤーのヒット処理
	if (m_p_player->CheckHit() == true) {
		m_result = PacMenResult::PLAYER_LOSE;
		return true;
	}
	return false;
}

bool PacMenGame::CheckHitItems()
{
	// アイテムのヒット処理
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		if (m_p_items[i]->CheckHit()) {
			m_item_delete_counter++;
		}
	}
	// アイテムのdelete数が全アイテムの数と一致した場合
	if (m_item_delete_counter == PACMEN_ITEM_NUM) {
		m_result = PacMenResult::PLAYER_WIN;
		return true;
	}
	return false;
}

PacMenGame* PacMenGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new PacMenGame;
	}
	return p_instance;
}
