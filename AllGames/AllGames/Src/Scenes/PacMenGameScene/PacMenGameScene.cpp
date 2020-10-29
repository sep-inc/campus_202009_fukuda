#include "PacMenGameScene.h"
#include "PacMenGameObject/PacMenGameCharacter/PacMenPlayer.h"
#include "PacMenGameObject/PacMenGameCharacter/PacMenMonster.h"
#include "PacMenGameObject/PacMenItem.h"
#include "../../Input/Input.h"


PacMenGameScene::PacMenGameScene() :
	m_p_game_map(nullptr),
	m_p_player(nullptr),
	m_p_monsters{ nullptr },
	m_p_items{ nullptr },
	m_step(PacMenGameSceneStep::STEP_INITIALIZE),
	m_result(PacMenResult::NONE),
	m_item_delete_counter(0),
	m_is_game_finish(false)
{
	m_next_scene = SceneType::SELECT_GAME;
}

PacMenGameScene::~PacMenGameScene()
{
	DestroyObjects();
}

void PacMenGameScene::Update()
{
	switch (m_step) {
	case PacMenGameSceneStep::STEP_INITIALIZE:
		/* オブジェクトの生成 */
		CreateObjects();

		/* 初期化処理 */
		m_p_game_map->Init();
		m_p_player->Init(m_p_game_map);
		for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
			m_p_monsters[i]->Init(m_p_game_map);
		}
		for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
			m_p_items[i]->Init(m_p_game_map);
		}

		/* ステップ移行 */
		m_step = PacMenGameSceneStep::STEP_GAME_START;
		break;

	case PacMenGameSceneStep::STEP_GAME_START:
		// ゲームスタート処理
		if (StartPacMen()) {
			m_step = PacMenGameSceneStep::STEP_UPDATE;
		}
		break;

	case PacMenGameSceneStep::STEP_UPDATE:
		/* 更新処理 */
		// アイテムの更新処理
		for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
			m_p_items[i]->Update();
		}
		// プレイヤーの更新処理
		m_p_player->Update();

		/* ゲームの終了判定 */
		if (CheckHitPlayer()) {
			m_step = PacMenGameSceneStep::STEP_GAME_END;
			break;
		}
		if (CheckHitItems()) {
			m_step = PacMenGameSceneStep::STEP_GAME_END;
			break;
		}

		/* モンスターの更新処理 */
		for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
			m_p_monsters[i]->Update();
		}

		/* ゲームの終了判定 */
		if (CheckHitPlayer()) {
			m_step = PacMenGameSceneStep::STEP_GAME_END;
		}
		break;

	case PacMenGameSceneStep::STEP_GAME_END:
		/* ゲーム終了処理選択 */
		SelectGameEnd();
		break;

	case PacMenGameSceneStep::STEP_END:
		if (m_is_scene_finish == true) {
			DestroyObjects();
		}
		else {
			m_step = PacMenGameSceneStep::STEP_INITIALIZE;
		}
		break;
	}
}

void PacMenGameScene::Draw(DrawerBase* drawer_)
{
	// マップの描画処理
	m_p_game_map->Draw(drawer_);
	// アイテムの描画処理
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		m_p_items[i]->Draw(drawer_);
	}
	// プレイヤーの描画処理
	m_p_player->Draw(drawer_);
	// モンスターの描画処理
	for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
		m_p_monsters[i]->Draw(drawer_);
	}
}

void PacMenGameScene::SetResult(DrawerBase* drawer_)
{
	switch (m_result) {
	case PacMenResult::NONE:
		return;
	case PacMenResult::PLAYER_WIN:
		drawer_->SetResultString("プレイヤーの勝利\n");
		return;
	case PacMenResult::PLAYER_LOSE:
		drawer_->SetResultString("プレイヤーの敗北\n");
		return;
	}
}

SceneBase* PacMenGameScene::InstancePacMenGameScene()
{
	return static_cast<SceneBase*>(new PacMenGameScene);
}

void PacMenGameScene::CreateObjects()
{
	if (m_p_game_map == nullptr)
		m_p_game_map = new PacMenGameMap;
	if (m_p_player == nullptr)
		m_p_player = new PacMenPlayer;
	for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
		if (m_p_monsters[i] == nullptr) {
			m_p_monsters[i] = new PacMenMonster;
		}
	}
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		if (m_p_items[i] == nullptr) {
			m_p_items[i] = new PacMenItem(i + 1);
		}
	}
}

void PacMenGameScene::DestroyObjects()
{
	if (m_p_game_map != nullptr) {
		delete m_p_game_map;
		m_p_game_map = nullptr;
	}
	if (m_p_player != nullptr) {
		delete m_p_player;
		m_p_player = nullptr;
	}
	for (int i = 0; i < PACMEN_MONSTER_NUM; i++) {
		if (m_p_monsters[i] != nullptr) {
			delete m_p_monsters[i];
			m_p_items[i] = nullptr;
		}
	}
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		if (m_p_items[i] != nullptr) {
			delete m_p_items[i];
			m_p_items[i] = nullptr;
		}
	}

}

bool PacMenGameScene::StartPacMen()
{
	printf("Spaceでゲームスタート\n");
	// キー情報取得
	int key = Input::Instance()->GetKey();
	if (key == KeyType::SPACE_KEY) {
		return true;
	}
	return false;
}

void PacMenGameScene::SelectGameEnd()
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
		m_step = PacMenGameSceneStep::STEP_END;
	}
	// Escキー入力
	else if (key == KeyType::ESCAPE_KEY) {
		m_is_scene_finish = true;
		m_step = PacMenGameSceneStep::STEP_END;
	}
}

bool PacMenGameScene::CheckHitPlayer()
{
	//プレイヤーのヒット処理
	if (m_p_player->CheckHit() == true) {
		m_result = PacMenResult::PLAYER_LOSE;
		return true;
	}
	return false;
}

bool PacMenGameScene::CheckHitItems()
{
	// アイテムのヒット処理
	for (int i = 0; i < PACMEN_ITEM_NUM; i++) {
		if (m_p_items[i]->CheckHit()) {
			m_item_delete_counter++;
		}
	}
	// アイテムのdelete数が全アイテムの数と一致した場合
	if (m_item_delete_counter == PACMEN_ITEM_NUM) {
		m_result = PacMenResult::PLAYER_WIN;
		return true;
	}
	return false;
}
