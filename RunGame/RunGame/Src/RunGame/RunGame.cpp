#include "RunGame.h"

RunGame* RunGame::p_instance = 0;

RunGame::RunGame():
	m_p_map(nullptr),
	m_step(RunGameStep::STEP_INITIALIZE),
	m_result(RunGameResult::NONE),
	m_is_game_finish(false)
{

}

RunGame::~RunGame()
{
	DestroyObjects();
}

RunGame* RunGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new RunGame;
	}
	return p_instance;
}

void RunGame::Update()
{
	switch (m_step) {
	case RunGameStep::STEP_INITIALIZE:
		/* オブジェクトの生成 */
		CreateObjects();

		/* 初期化処理 */
		m_p_map->Init();

		/* ステップ移行 */
		m_step = RunGameStep::STEP_UPDATE;
		break;

	case RunGameStep::STEP_UPDATE:
		/* 更新処理 */

		break;

	case RunGameStep::STEP_END:
		m_is_game_finish = true;
		DestroyObjects();
		break;
	}
}

void RunGame::Draw(DrawerBase* drawer_)
{
	m_p_map->Draw(drawer_);
}

void RunGame::SetResult()
{
}

void RunGame::CreateObjects()
{
	if (m_p_map == nullptr)
		m_p_map = new GameMap;
}

void RunGame::DestroyObjects()
{
	if (m_p_map != nullptr) {
		delete m_p_map;
		m_p_map = nullptr;
	}
}