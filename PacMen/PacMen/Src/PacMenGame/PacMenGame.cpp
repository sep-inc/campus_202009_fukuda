#include "PacMenGame.h"
#include "../Draw/DrawerManager.h"

PacMenGame* PacMenGame::p_instance = 0;

PacMenGame::PacMenGame():
	m_p_game_map(nullptr),
	m_p_characters{nullptr},
	m_p_items{nullptr},
	m_step(PacMenGameStep::STEP_INITIALIZE),
	m_is_game_finish(false)
{

}

PacMenGame::~PacMenGame()
{
	DestroyObjects();
}

void PacMenGame::CreateObjects()
{
	if (m_p_game_map == nullptr)
		m_p_game_map = new GameMap;
}

void PacMenGame::DestroyObjects()
{
	if (m_p_game_map != nullptr) {
		delete m_p_game_map;
		m_p_game_map = nullptr;
	}
	
}

PacMenGame* PacMenGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new PacMenGame;
	}
	return p_instance;
}

void PacMenGame::Update()
{
	switch (m_step) {
	case PacMenGameStep::STEP_INITIALIZE:
		// オブジェクトの生成	
		CreateObjects();

		// 初期化処理
		m_p_game_map->Init();

		// ステップ移行
		m_step = PacMenGameStep::STEP_UPDATE;
		break;
	case PacMenGameStep::STEP_UPDATE:

		break;
	case PacMenGameStep::STEP_END:
		DestroyObjects();
		break;
	}
}

void PacMenGame::Draw()
{
	m_p_game_map->Draw(DrawerManager::Instance()->m_p_drawer);
}

void PacMenGame::SetResult()
{
}
