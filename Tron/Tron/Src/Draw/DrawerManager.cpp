#include "DrawerManager.h"
#include "TronDrawer.h"

DrawerManager* DrawerManager::p_instance = 0;

DrawerManager::DrawerManager():
	m_p_drawer(nullptr)
{

}

DrawerManager::~DrawerManager() 
{

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
	if (m_p_drawer == nullptr) {
		m_p_drawer = new TronDrawer;
	}
}

void DrawerManager::DeleteDrawer()
{
	if (m_p_drawer != nullptr) {
		delete m_p_drawer;
		m_p_drawer = nullptr;
	}
}
