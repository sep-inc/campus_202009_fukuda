#include "SelectGameScene.h"
#include "../../Input/Input.h"
#include <cstring>

SelectGameScene::SelectGameScene():
	m_now_step(SelectGameStep::STEP_INITIALIZE),
	m_now_select_index(0)
{
}

SelectGameScene::~SelectGameScene()
{
}

void SelectGameScene::Update()
{
	switch (m_now_step) {
	case SelectGameStep::STEP_INITIALIZE:
		Init();
		m_now_step = SelectGameStep::STEP_UPDATE;
		break;
	case SelectGameStep::STEP_UPDATE:
		if (SelectScene()) {
			m_next_scene = m_games[m_now_select_index].m_scene_type;
			m_now_step = SelectGameStep::STEP_END;
		}

		break;
	case SelectGameStep::STEP_END:
		m_is_scene_finish = true;
		break;
	}
}

void SelectGameScene::Draw(DrawerBase* drawer_)
{
	char space[SELECT_GAME_DRAW_STRING_SIZE] = "　";
	char pointer[SELECT_GAME_DRAW_STRING_SIZE] = "●";
	Vec2_Int pos;
	for (pos.m_y = 0; pos.m_y < ALL_GAME_NUM; pos.m_y++) {
		pos.m_x = 0;
		if (pos.m_y == m_now_select_index) {
			drawer_->SetDrawBuffer(pos, pointer);
		}
		else {
			drawer_->SetDrawBuffer(pos, space);
		}
		pos.m_x++;
		drawer_->SetDrawBuffer(pos, m_games[pos.m_y].m_title_string);
	}
}

SceneBase* SelectGameScene::InstanceSelectGameScene()
{
	return static_cast<SceneBase*>(new SelectGameScene);
}

void SelectGameScene::Init()
{
	m_games[0].m_scene_type = SceneType::TIT_TAT_TOE;
	strcpy_s(m_games[0].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "マルバツゲーム");
	m_games[1].m_scene_type = SceneType::TOWER_OF_HANOI;
	strcpy_s(m_games[1].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "ハノイの塔");
	m_games[2].m_scene_type = SceneType::TRON;
	strcpy_s(m_games[2].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "トロン");
	m_games[3].m_scene_type = SceneType::PACMEN;
	strcpy_s(m_games[3].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "パックマン");
	m_games[4].m_scene_type = SceneType::RUN_GAME;
	strcpy_s(m_games[4].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "Runゲーム");
	m_games[5].m_scene_type = SceneType::SHOGI;
	strcpy_s(m_games[5].m_title_string, SELECT_GAME_DRAW_STRING_SIZE, "4マス将棋");
}

bool SelectGameScene::SelectScene()
{
	int key = Input::Instance()->GetKey();
	if (key == KeyType::ENTER_KEY) {
		return true;
	}

	if (key == KeyType::UP_KEY) {
		m_now_select_index--;
		if (m_now_select_index < 0) {
			m_now_select_index = ALL_GAME_NUM - 1;
		}
	}
	else if (key == KeyType::DOWN_KEY) {
		m_now_select_index++;
		if (m_now_select_index > ALL_GAME_NUM - 1) {
			m_now_select_index = 0;
		}
	}

	return false;
}
