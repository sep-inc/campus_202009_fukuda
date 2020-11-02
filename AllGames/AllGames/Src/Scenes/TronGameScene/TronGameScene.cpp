#include "TronGameScene.h"
#include "TronCharacter/TronPlayer.h"
#include "TronCharacter/TronEnemy.h"
#include <string>

TronGameScene::TronGameScene() :
	m_p_player(nullptr),
	m_p_enemy(nullptr),
	m_p_game_map(nullptr),
	m_step(TronGameSceneStep::STEP_INITIALIZE),
	m_cannot_move_player(false),
	m_cannot_move_enemy(false)
{
	m_next_scene = SceneType::SELECT_GAME;
}

TronGameScene::~TronGameScene()
{
	DestroyObjects();
}

void TronGameScene::Update()
{
	switch (m_step) {
	case TronGameSceneStep::STEP_INITIALIZE:
		// オブジェクト生成
		CreateObjects();

		// 初期化処理
		Init();
		m_p_game_map->Init();
		m_p_player->Init(m_p_game_map);
		m_p_enemy->Init(m_p_game_map);

		m_step = TronGameSceneStep::STEP_GAME_START;
		break;

	case TronGameSceneStep::STEP_GAME_START:
		// ゲームスタート処理
		if (GameStart()) {
			m_step = TronGameSceneStep::STEP_UPDATE;
		}
		break;

	case TronGameSceneStep::STEP_UPDATE:
		// プレイヤーの更新処理
		m_p_player->Update();
		// 更新情報をゲームマップにセット、trueが返ってくればゲーム終了処理へ
		m_cannot_move_player = m_p_game_map->SetMovePos(m_p_player->GetMovePos(), m_p_player->GetMyParam());
		// エネミーの更新処理
		m_p_enemy->Update();
		// 更新情報をゲームマップにセット、trueが返ってくればゲーム終了処理へ
		m_cannot_move_enemy = m_p_game_map->SetMovePos(m_p_enemy->GetMovePos(), m_p_enemy->GetMyParam());

		// 終了判定
		if (m_cannot_move_player == true ||
			m_cannot_move_enemy == true) {
			m_step = TronGameSceneStep::STEP_GAME_END;
		}

		break;

	case TronGameSceneStep::STEP_GAME_END:
		/* ゲーム終了処理選択 */
		if (SelectGameEnd()) {
			m_step = TronGameSceneStep::STEP_END;
		}
		break;

	case TronGameSceneStep::STEP_END:
		if (m_is_scene_finish == true) {
			// オブジェクト破棄
			DestroyObjects();
		}
		else {
			m_step = TronGameSceneStep::STEP_INITIALIZE;
		}
		break;
	}
}

void TronGameScene::Draw(DrawerBase* drawer_)
{
	m_p_game_map->Draw(drawer_);
	SetResult(drawer_);
}

void TronGameScene::Init()
{
	m_cannot_move_player = false;
	m_cannot_move_enemy = false;
}

void TronGameScene::SetResult(DrawerBase* drawer_)
{
	if (m_cannot_move_player == true &&
		m_cannot_move_enemy == true) {
		drawer_->SetResultString("引き分け\n");
	}
	else if (m_cannot_move_enemy == true) {
		drawer_->SetResultString("プレイヤーの勝利\n");
	}
	else if (m_cannot_move_player == true) {
		drawer_->SetResultString("エネミーの勝利\n");
	}
}

SceneBase* TronGameScene::InstanceTronGameScene()
{
	return static_cast<SceneBase*>(new TronGameScene);
}

void TronGameScene::CreateObjects()
{
	if (m_p_player == nullptr)
		m_p_player = new TronPlayer;
	if (m_p_enemy == nullptr)
		m_p_enemy = new TronEnemy;
	if (m_p_game_map == nullptr)
		m_p_game_map = new TronGameMap;
}

void TronGameScene::DestroyObjects()
{
	if (m_p_player != nullptr) {
		delete m_p_player;
		m_p_player = nullptr;
	}
	if (m_p_enemy != nullptr) {
		delete m_p_enemy;
		m_p_enemy = nullptr;
	}
	if (m_p_game_map != nullptr) {
		delete m_p_game_map;
		m_p_game_map = nullptr;
	}

}