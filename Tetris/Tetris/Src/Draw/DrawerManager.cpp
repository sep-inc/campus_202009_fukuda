#include "DrawerManager.h"
#include "TetrisDrawer.h"

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

void DrawerManager::CreateDrawer()
{
	if (m_p_drawer == nullptr) {
		m_p_drawer = new TetrisDrawer;
	}
}

void DrawerManager::DestroyDrawer()
{
	if (m_p_drawer != nullptr) {
		delete m_p_drawer;
		m_p_drawer = nullptr;
	}
}
