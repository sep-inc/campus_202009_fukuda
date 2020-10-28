#include "RunGameScene.h"
#include "../../Input/Input.h"


RunGameScene::RunGameScene() :
	m_p_map(nullptr),
	m_p_frame_counter(nullptr),
	m_p_player(nullptr),
	m_step(RunGameSceneStep::STEP_INITIALIZE),
	m_result(RunGameResult::NONE)
{
	m_next_scene = SceneType::SELECT_GAME;
}

RunGameScene::~RunGameScene()
{
	DestroyObjects();
}

void RunGameScene::Update()
{
	switch (m_step) {
	case RunGameSceneStep::STEP_INITIALIZE:
		/* オブジェクトの生成 */
		CreateObjects();

		/* 初期化処理 */
		m_p_map->Init();
		m_p_frame_counter->ResetCounter();
		m_p_player->Init(m_p_map);
		m_result = RunGameResult::NONE;

		/* ステップ移行 */
		m_step = RunGameSceneStep::STEP_GAME_START;
		break;

	case RunGameSceneStep::STEP_GAME_START:
		// ゲームスタート処理
		if (StartRunGame()) {
			m_step = RunGameSceneStep::STEP_UPDATE;
		}
		break;

	case RunGameSceneStep::STEP_UPDATE:
		/* 更新処理 */
		// 毎フレーム行う更新
		m_p_player->Update();

		// 指定フレームのみ行う更新
		m_p_player->FixedUpdate(m_p_frame_counter->IsCountMax());
		m_p_map->FixedUpdate(m_p_frame_counter->IsCountMax());

		/* 勝敗判定 */
		if (m_p_player->IsClear()) {
			m_result = RunGameResult::WIN;
			m_step = RunGameSceneStep::STEP_GAME_END;
		}
		if (m_p_player->IsDead()) {
			m_result = RunGameResult::LOSE;
			m_step = RunGameSceneStep::STEP_GAME_END;
		}

		// フレームカウント更新
		m_p_frame_counter->UpdateCounter();
		break;

	case RunGameSceneStep::STEP_GAME_END:
		/* ゲーム終了処理選択 */
		SelectGameEnd();
		break;

	case RunGameSceneStep::STEP_END:
		if (m_is_scene_finish == true) {
			DestroyObjects();
		}
		else {
			m_step = RunGameSceneStep::STEP_INITIALIZE;
		}
		break;
	}
}

void RunGameScene::Draw(DrawerBase* drawer_)
{
	m_p_player->Draw();
	m_p_map->Draw(drawer_);

	SetResult(drawer_);
}

void RunGameScene::SetResult(DrawerBase* drawer_)
{
	if (m_result == RunGameResult::NONE) {
		drawer_->SetResultString("\0");
	}
	else if (m_result == RunGameResult::WIN) {
		drawer_->SetResultString("プレイヤーの勝利\n");
	}
	else {
		drawer_->SetResultString("プレイヤーの敗北\n");
	}
}

SceneBase* RunGameScene::InstanceRunGameScene()
{
	return static_cast<SceneBase*>(new RunGameScene);
}

void RunGameScene::CreateObjects()
{
	if (m_p_map == nullptr)
		m_p_map = new RunGameMap;
	if (m_p_frame_counter == nullptr)
		m_p_frame_counter = new FrameCounter;
	if (m_p_player == nullptr)
		m_p_player = new Player;
}

void RunGameScene::DestroyObjects()
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

}

bool RunGameScene::StartRunGame()
{
	printf("Spaceでゲームスタート\n");
	// キー情報取得
	int key = Input::Instance()->GetKey();
	if (key == KeyType::SPACE_KEY) {
		return true;
	}
	return false;
}

void RunGameScene::SelectGameEnd()
{
	printf("ゲームを続けますか？\n");
	printf("Enter : 続行  Esc : 終了\n");
	// キー情報取得
	int key = Input::Instance()->GetKey();
	// 入力なし
	if (key == -1) {
		return;
	}
	// Enterキー入力
	else if (key == KeyType::ENTER_KEY) {
		m_step = RunGameSceneStep::STEP_END;
	}
	// Escキー入力
	else if (key == KeyType::ESCAPE_KEY) {
		m_is_scene_finish = true;
		m_step = RunGameSceneStep::STEP_END;
	}
}
