#include "TetrisGameScene.h"

TetrisGameScene::TetrisGameScene():
	m_p_map(nullptr),
	m_step(TetrisGameSceneStep::STEP_INITIALIZE)
{
}

TetrisGameScene::~TetrisGameScene()
{
	DestroyObjects();
}

void TetrisGameScene::Update()
{
	switch (m_step) {
	case TetrisGameSceneStep::STEP_INITIALIZE:
		CreateObjects();

		m_p_map->Init();

		m_step = TetrisGameSceneStep::STEP_GAME_START;

		break;
	case TetrisGameSceneStep::STEP_GAME_START:
		// ゲームのスタート処理
		if (GameStart()) {
			m_step = TetrisGameSceneStep::STEP_UPDATE;
		}
		break;
	case TetrisGameSceneStep::STEP_UPDATE:
		break;
	case TetrisGameSceneStep::STEP_GAME_END:
		// ゲームの終了選択処理
		if (SelectGameEnd()) {
			m_step = TetrisGameSceneStep::STEP_END;
		}
		
		break;
	case TetrisGameSceneStep::STEP_END:
		if (m_is_scene_finish == true) {

		}
		else {
			m_step = TetrisGameSceneStep::STEP_INITIALIZE;
		}
		break;
	}
}

void TetrisGameScene::Draw(DrawerBase* drawer_)
{
	m_p_map->Draw(drawer_);
}

void TetrisGameScene::Init()
{
}

void TetrisGameScene::CreateObjects()
{
	if (m_p_map == nullptr) {
		m_p_map = new TetrisGameMap;
	}
}

void TetrisGameScene::DestroyObjects()
{
	if (m_p_map != nullptr) {
		delete m_p_map;
		m_p_map = nullptr;
	}
}
