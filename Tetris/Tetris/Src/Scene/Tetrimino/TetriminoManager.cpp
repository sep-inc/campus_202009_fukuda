#include "TetriminoManager.h"

TetriminoManager::TetriminoManager():
	m_active_tetrimino(nullptr),
	m_waiting_tetrimino(nullptr)
{
}

TetriminoManager::~TetriminoManager()
{
	if (m_active_tetrimino != nullptr) {
		delete m_active_tetrimino;
		m_active_tetrimino = nullptr;
	}
	if (m_waiting_tetrimino != nullptr) {
		delete m_waiting_tetrimino;
		m_waiting_tetrimino = nullptr;
	}
}

void TetriminoManager::CreateTetrimino()
{
	if (m_waiting_tetrimino == nullptr) {
		
	}
}

void TetriminoManager::DestroyActiveTetrimino()
{
	if (m_active_tetrimino != nullptr) {
		delete m_active_tetrimino;
		m_active_tetrimino = nullptr;
	}
}
