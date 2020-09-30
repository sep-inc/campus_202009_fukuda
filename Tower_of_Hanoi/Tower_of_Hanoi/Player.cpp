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
		// �ړ����ԍ��̓���
		m_source_pile_num = ObjectManager::Instance()->m_p_input->SelectSourcePile();
		// �ړ���ԍ��̓���
		m_destination_pile_num = ObjectManager::Instance()->m_p_input->SelectDestinationPile(m_source_pile_num);
		// ���͔����true���Ԃ��Ă�����A�l��Set�����Ń��[�v�I��
		if (ObjectManager::Instance()->m_p_game_stage_manager->SetInputPileNums(m_source_pile_num, m_destination_pile_num)) {
			break;
		}
		// �l���Z�b�g�ł��Ȃ��������߃��[�v���s
		else {
			printf("�w�肵���ꏊ�ɂ͈ړ��ł��܂���A������x���͂��Ă�������\n");
		}
	}
	

	
}
