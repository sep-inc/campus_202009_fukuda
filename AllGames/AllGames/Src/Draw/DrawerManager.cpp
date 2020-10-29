#include "DrawerManager.h"
#include "Drawers/SelectGameDrawer.h"
#include "Drawers/RunGameDrawer.h"
#include "Drawers/PacMenDrawer.h"
#include "Drawers/ShogiGameDrawer.h"

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
	m_p_drawer = s_func_ptr_array[static_cast<int>(game_type_)]();
}

void DrawerManager::DestroyDrawer()
{
	if (m_p_drawer != nullptr) {
		delete m_p_drawer;
		m_p_drawer = nullptr;
	}
}

DrawerBase* (*DrawerManager::s_func_ptr_array[static_cast<int>(SceneType::MAX_SCENE_NUM)])() =
{
	SelectGameDrawer::InstanceSelectGameDrawer,
	SelectGameDrawer::InstanceSelectGameDrawer,
	SelectGameDrawer::InstanceSelectGameDrawer,
	SelectGameDrawer::InstanceSelectGameDrawer,
	PacMenDrawer::InstancePacMenDrawer,
	RunGameDrawer::InstanceRunGameDrawer,
	ShogiGameDrawer::InstanceSelectGameDrawer
};
