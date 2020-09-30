#include "ObjectManager.h"

ObjectManager* ObjectManager::p_instance = 0;

ObjectManager::ObjectManager():
	m_p_player(nullptr),
	m_p_game_stage_manager(nullptr),
	m_p_input(nullptr),
	m_p_drawer(nullptr)
{
}

ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::Instance()
{
	// p_instanceに実体がなかった場合生成
	if (p_instance == 0) {
		p_instance = new ObjectManager;
	}

	return p_instance;
}

void ObjectManager::CreateObjects()
{
	// NULLチェック＆生成
	if (m_p_player == nullptr)
		m_p_player = new Player;

	if (m_p_game_stage_manager == nullptr)
		m_p_game_stage_manager = new GameStageManager;

	if (m_p_input == nullptr)
		m_p_input = new Input;

	if (m_p_drawer == nullptr)
		m_p_drawer = new Drawer;
}

void ObjectManager::DeleteObjects()
{
	// NULLチェック＆生成
	if (m_p_player != nullptr)
		delete m_p_player;

	if (m_p_game_stage_manager != nullptr)
		delete m_p_game_stage_manager;

	if (m_p_input != nullptr)
		delete m_p_input;

	if (m_p_drawer != nullptr)
		delete m_p_drawer;
}
