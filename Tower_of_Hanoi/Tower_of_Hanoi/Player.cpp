#include "Player.h"
#include "ObjectManager.h"
#include <cstdio>


Player::Player():
	m_step(Step::Step_Initialize),
	m_source_pile_num(0),
	m_destination_pile_num(0)
{
}

Player::~Player()
{
}

void Player::UpdateStep()
{
	switch (m_step)
	{
	case Step::Step_Initialize:
		m_step = Step::Step_Update;
		break;
	case Step::Step_Update:
		Input();
		break;
	case Step::Step_End:
		break;
	default:
		break;
	}
}

void Player::Input()
{
	while (true) {
		// 移動元番号の入力
		m_source_pile_num = ObjectManager::Instance()->m_p_input->SelectSourcePile();
		// 移動先番号の入力
		m_destination_pile_num = ObjectManager::Instance()->m_p_input->SelectDestinationPile(m_source_pile_num);
		// 入力判定でtrueが返ってきたら、値のSet完了でループ終了
		if (ObjectManager::Instance()->m_p_game_stage_manager->SetInputPileNums(m_source_pile_num, m_destination_pile_num)) {
			break;
		}
		// 値がセットできなかったためループ続行
		else {
			printf("指定した場所には移動できません、もう一度入力してください\n");
		}
	}
	

	
}
