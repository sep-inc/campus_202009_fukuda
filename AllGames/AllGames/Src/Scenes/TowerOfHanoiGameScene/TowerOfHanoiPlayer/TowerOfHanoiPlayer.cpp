#include "TowerOfHanoiPlayer.h"
#include "../../../Input/Input.h"
#include "../../../AllDefinition.h"
#include <cstdio>

TowerOfHanoiPlayer::TowerOfHanoiPlayer() : 
	m_source_pile_num(0),
	m_destination_pile_num(0)
{
}

TowerOfHanoiPlayer::~TowerOfHanoiPlayer()
{
}

void TowerOfHanoiPlayer::Update()
{
	InputPlayer();
}

void TowerOfHanoiPlayer::InputPlayer()
{
	while (true) {
		// 移動元番号の入力
		while (true) {
			int key = Input::Instance()->GetWaitingKey();
			printf("動かす円盤のある番号を入力 : ");
			if (key == KeyType::ONE_KEY) {
				m_source_pile_num = 1;
				break;
			}
			else if (key == KeyType::TWO_KEY) {
				m_source_pile_num = 2;
				break;
			}
			else if (key == KeyType::THREE_KEY) {
				m_source_pile_num = 3;
				break;
			}
			printf("入力した値が不正です\n");
		}

		// 移動先番号の入力
		while (true) {
			int key = Input::Instance()->GetWaitingKey();
			int tmp = 0;
			printf("円盤を移動させる場所の番号を入力 : ");
			if (key == KeyType::ONE_KEY) {
				tmp = 1;
			}
			else if (key == KeyType::TWO_KEY) {
				tmp = 2;
			}
			else if (key == KeyType::THREE_KEY) {
				tmp = 3;
			}
			else {
				printf("入力した値が不正です\n");
				continue;
			}

			if (tmp == m_source_pile_num) {
				printf("そこには移動できません\n");
			}
			else {
				m_destination_pile_num = tmp;
				break;
			}
		}
		
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