#include "SceneManager.h"
#include "SelectGameScene/SelectGameScene.h"
#include "../Draw/DrawerManager.h"

SceneManager* SceneManager::p_instance = 0;

SceneManager::SceneManager():
	m_p_scene(nullptr),
	m_step(SceneStep::STEP_INITIALIZE),
	m_now_scene(SceneType::SELECT_GAME)
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
		CreateScene(m_now_scene);
		// Drawerクラスの切り替え
		DrawerManager::Instance()->SelectDrawer(m_now_scene);

		m_step = SceneStep::STEP_UPDATE;
		break;

	case SceneStep::STEP_UPDATE:
		// シーンの処理
		m_p_scene->Update();

		// シーンの終了判定処理
		if (m_p_scene->IsGameFinish()) {
			m_step = SceneStep::STEP_END;
		}

		break;

	case SceneStep::STEP_END:
		// シーンを次のシーンに切り替え
		m_now_scene = m_p_scene->GetNextScene();
		// シーンの破棄
		DestroyScene();

		break;
	}
}

void SceneManager::Draw(DrawerBase* drawer_)
{
	if (m_p_scene != nullptr) {
		m_p_scene->Draw(drawer_);
	}
}

void SceneManager::CreateScene(SceneType scene_)
{
	if (m_p_scene == nullptr) {
		switch (scene_) {
		case SceneType::SELECT_GAME:
			m_p_scene = new SelectGameScene;
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
			break;
		case SceneType::SHOGI:
			break;
		default:
			break;
		}
	}
}

void SceneManager::DestroyScene()
{
	if (m_p_scene != nullptr) {
		delete m_p_scene;
		m_p_scene = nullptr;
	}
}
