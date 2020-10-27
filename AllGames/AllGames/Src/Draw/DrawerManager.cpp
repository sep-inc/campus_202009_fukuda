#include "DrawerManager.h"
#include "Drawers/SelectGameDrawer.h"
#include "Drawers/RunGameDrawer.h"

DrawerManager* DrawerManager::p_instance = 0;

DrawerManager::DrawerManager():
	m_p_drawer(nullptr)
{
}

DrawerManager::~DrawerManager()
{
	DestroyDrawer();
}

DrawerManager* DrawerManager::Instance()
{
	if (p_instance == 0) {
		p_instance = new DrawerManager;
	}
	return p_instance;
}

void DrawerManager::Draw()
{
	if (m_p_drawer != nullptr) {
		m_p_drawer->Draw();
	}
}

void DrawerManager::Clear()
{
	if (m_p_drawer != nullptr) {
		m_p_drawer->Clear();
	}
}

void DrawerManager::SelectDrawer(SceneType game_type_)
{
	DestroyDrawer();
	CreateDrawer(game_type_);
}

void DrawerManager::CreateDrawer(SceneType game_type_)
{
	if (m_p_drawer == nullptr)
	{
		switch (game_type_) {
		case SceneType::SELECT_GAME:
			m_p_drawer = new SelectGameDrawer;
			break;
		case SceneType::TIT_TAT_TOE:
			break;
		case SceneType::TOWER_OF_HANOI:
			break;
		case SceneType::TRON:
			break;
		case SceneType::PACMEN:
			break;
		case SceneType::RUN_GAME:
			m_p_drawer = new RunGameDrawer;
			break;
		case SceneType::SHOGI:
			break;
		default:
			break;
		}
	}
}

void DrawerManager::DestroyDrawer()
{
	if (m_p_drawer != nullptr) {
		delete m_p_drawer;
		m_p_drawer = nullptr;
	}
}
