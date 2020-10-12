#include "TronGame.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"

TronGame* TronGame::p_instance = 0;

TronGame::TronGame():
	m_p_player(nullptr),
	m_p_enemy(nullptr),
	m_p_game_map(nullptr),
	m_step(TronGameStep::STEP_INITIALIZE)
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
