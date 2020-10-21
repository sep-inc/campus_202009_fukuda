﻿#include "RunGame.h"

RunGame* RunGame::p_instance = 0;

RunGame::RunGame():
	m_p_map(nullptr),
	m_p_frame_counter(nullptr),
	m_p_player(nullptr),
	m_p_camera(nullptr),
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
		m_p_frame_counter->ResetCounter();
		m_p_player->Init();
		m_p_camera->Init(m_p_player, m_p_map);

		/* ステップ移行 */
		m_step = RunGameStep::STEP_UPDATE;
		break;

	case RunGameStep::STEP_UPDATE:
		/* 更新処理 */
		

		m_p_frame_counter->UpdateCounter();
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
	if (m_p_frame_counter == nullptr)
		m_p_frame_counter = new FrameCounter;
	if (m_p_player == nullptr)
		m_p_player = new Player;
	if (m_p_camera == nullptr)
		m_p_camera = new GameCamera;
}

void RunGame::DestroyObjects()
{
	if (m_p_map != nullptr) {
		delete m_p_map;
		m_p_map = nullptr;
	}
	if (m_p_frame_counter != nullptr) {
		delete m_p_frame_counter;
		m_p_frame_counter = nullptr;
	}
	if (m_p_player != nullptr) {
		delete m_p_player;
		m_p_player = nullptr;
	}
	if (m_p_camera != nullptr) {
		delete m_p_camera;
		m_p_camera = nullptr;
	}
}