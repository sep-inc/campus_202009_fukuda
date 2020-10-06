#include "DrawerManager.h"
#include "ShogiDrawer.h"

DrawerManager* DrawerManager::p_instance = 0;

DrawerManager::DrawerManager():
	m_drawer(nullptr)
{
}

DrawerManager::~DrawerManager()
{
	if (m_drawer != nullptr) {
		delete m_drawer;
		m_drawer = nullptr;
	}
}

DrawerManager* DrawerManager::Instance()
{
	if (p_instance == 0) {
		p_instance = new DrawerManager;
	}
	return p_instance;
}

void DrawerManager::CreateDrawer()
{
	m_drawer = new ShogiDrawer;
}
