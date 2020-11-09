#include "SceneBase.h"
#include "../Input/Input.h"

SceneBase::SceneBase():
	m_is_scene_finish(false)
{
}

SceneBase::~SceneBase()
{
}

bool SceneBase::GameStart()
{
	printf("Spaceでゲームスタート\n");
	// キー情報取得
	int key = Input::Instance()->GetKey();
	if (key == KeyType::SPACE_KEY) {
		return true;
	}
	return false;
}

bool SceneBase::SelectGameEnd()
{
	printf("ゲームを続けますか？\n");
	printf("Enter : 続行  Esc : 終了\n");
	// キー情報取得
	int key = Input::Instance()->GetKey();
	
	// Enterキー入力
	if (key == KeyType::ENTER_KEY) {
		return true;
	}
	// Escキー入力
	else if (key == KeyType::ESCAPE_KEY) {
		m_is_scene_finish = true;
		return true;
	}

	return false;
}

bool SceneBase::IsGameFinish()
{
	if (m_is_scene_finish) {
		return true;
	}
	return false;
	
}
