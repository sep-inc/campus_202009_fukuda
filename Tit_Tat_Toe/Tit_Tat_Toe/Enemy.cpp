#include "Enemy.h"
#include "Global.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy():
	m_step(Step::Step_Initialize),
	m_draw_type(DrawType::TypeNone)
{
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// �^�����������e�[�u���̏������i���ԁj
	srand((unsigned)time(NULL));
	m_draw_type = DrawType::Enemy;
}

void Enemy::Update()
{
	switch (m_step) {
	case Step::Step_Initialize:
		// ������
		Init();
	// �������I���ŃX�e�b�v�X�V
		m_step = Step::Step_Run;
		break;
	case Step::Step_Run:
		// �Q�[���I������������������Ă��Ȃ��ꍇ
		if (g_map.IsFinishGame() == false) {
			// ���͂���ꏊ�����߁A�Q�[���}�b�v�z��փZ�b�g����
			g_map.SetPos(SelectInputPos(), m_draw_type);
			// ���s������s���A���ʂ�Map�N���X�փZ�b�g����
			g_map.SetResult(g_map.JudgeResult());
		}
		// �Q�[���I���̏������������Ă����ꍇ
		else {
			// �X�e�b�v��Step_End�ɍX�V����
			m_step = Step::Step_End;
		}
		break;
	case Step::Step_End:
		break;
	}
}

Vec2 Enemy::SelectInputPos()
{
	// �I������v�f������̃}�X�ڃ��X�g�̃T�C�Y�����ƂɃ����_���Ō��߂�
	int select_num = rand() % (g_map.GetEmptyArraySize());
	// ���܂����v�f���Ɋi�[����Ă�����W��Ԃ�
	return g_map.GetSelectEnptyPos(select_num);
}
