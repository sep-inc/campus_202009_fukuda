#include "Player.h"
#include "Global.h"
#include <cstdio>

Player::Player():
	m_draw_type(DrawType::TypeNone),
	m_step(Step::Step_Initialize),
	m_input_pos{}
{
}


Player::~Player()
{
}

void Player::Init()
{
	m_draw_type = DrawType::Player;
}

void Player::Update()
{
	switch (m_step) {
	case Step::Step_Initialize:
		// ������
		Init();
		// �X�e�b�v�X�V
		m_step = Step::Step_Run;
		break;
	case Step::Step_Run:
		// �Q�[���I���������������Ă��Ȃ��ꍇ
		if (g_map.IsFinishGame() == false) {
			// ���͏�񂪊m�肷��܂ő�����
			while (true) {
				// ���W�̓���
				m_input_pos = g_input.InputPlayer();
				// ���͂������W���󂩂ǂ���
				if (g_map.IsEmpty(m_input_pos) == true) {
					// ���͏����}�b�v�֔��f
					g_map.SetPos(m_input_pos, m_draw_type);
					// ���s������s���A���ʂ��Z�b�g����
					g_map.SetResult(g_map.JudgeResult());
					break;
				}
				// ���͂����}�X�����łɓ��͂���Ă����ꍇ
				else {
					printf("���͂����}�X�ɂ͓��͂ł��܂���\n");
				}
			}
		}
		// �Q�[���I���������������Ă����ꍇ
		else {
			// �X�e�b�v�X�V
			m_step = Step::Step_End;
		}
		break;
	case Step::Step_End:
		break;
	}

}
