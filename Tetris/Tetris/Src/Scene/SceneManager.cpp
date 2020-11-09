#include "SceneManager.h"
#include "TetrisGameScene.h"

SceneManager* SceneManager::p_instance = 0;

SceneManager::SceneManager():
	m_p_scene(nullptr),
	m_step(SceneStep::STEP_INITIALIZE)
{
}

SceneManager::~SceneManager()
{
	DestroyScene();
}

SceneManager* SceneManager::Instance()
{
	if (p_instance == 0) {
		p_instance = new SceneManager;
	}
	return p_instance;
}

void SceneManager::Update()
{
	switch (m_step) {
	case SceneStep::STEP_INITIALIZE:
		// シーンの生成
		CreateScene();
		
		m_step = SceneStep::STEP_UPDATE;

	case SceneStep::STEP_UPDATE:
		// シーンの処理
		m_p_scene->Update();

		// シーンの終了判定処理
		if (m_p_scene->IsGameFinish()) {
			m_step = SceneStep::STEP_END;
		}

		break;

	case SceneStep::STEP_END:
		// シーンの破棄
		DestroyScene();

		m_step = SceneStep::STEP_INITIALIZE;

		break;
	}
}

void SceneManager::Draw(DrawerBase* drawer_)
{
	if (m_p_scene != nullptr) {
		m_p_scene->Draw(drawer_);
	}
}

void SceneManager::CreateScene()
{
	if (m_p_scene == nullptr) {
		m_p_scene = new TetrisGameScene;
	}
}

void SceneManager::DestroyScene()
{
	if (m_p_scene != nullptr) {
		delete m_p_scene;
		m_p_scene = nullptr;
	}
}
