#include "SceneManager.h"
#include "SelectGameScene/SelectGameScene.h"
#include "RunGameScene/RunGameScene.h"
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

void SceneManager::CreateScene(SceneType scene_)
{
	m_p_scene = s_func_ptr_array[static_cast<int>(scene_)]();
}

void SceneManager::DestroyScene()
{
	if (m_p_scene != nullptr) {
		delete m_p_scene;
		m_p_scene = nullptr;
	}
}

SceneBase* (*SceneManager::s_func_ptr_array[static_cast<int>(SceneType::MAX_SCENE_NUM)])() =
{
	SelectGameScene::InstanceSelectGameScene,
	SelectGameScene::InstanceSelectGameScene,
	SelectGameScene::InstanceSelectGameScene,
	SelectGameScene::InstanceSelectGameScene,
	SelectGameScene::InstanceSelectGameScene,
	RunGameScene::InstanceRunGameScene,
	SelectGameScene::InstanceSelectGameScene
};
