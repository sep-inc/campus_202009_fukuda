#include "Player.h"
#include "../Input/Input.h"
#include <cstdio>
#include <cstring>

Player::Player()
{
	m_param.m_type = ObjectType::PLAYER;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "��");
	m_current_pos.m_x = INIT_PLAYER_POS_X;
	m_current_pos.m_y = INIT_PLAYER_POS_Y;
}

Player::~Player()
{
}

void Player::SelectMoveDirection()
{
	// ���͉\�͈͂̎擾
	Vec2 can_move_pos[CAN_MOVE_LIST_SIZE] = {};
	m_p_map->GetCanMovePos(m_current_pos, can_move_pos);

	// ���͏���
	while (true) {
		// ���͏��̎擾
		Vec2 vec = Input::Instance()->InputDirection();
		// �ړ�����W�̎Z�o
		Vec2 move_pos = { m_current_pos.m_x + vec.m_x,m_current_pos.m_y + vec.m_y };
		// �ړ��\�͈̓��X�g�ƈړ�����W����v���Ă��邩�𒲂ׂ�
		for (int i = 0; i < CAN_MOVE_LIST_SIZE; i++) {
			// ��v���Ă����ꍇ�A���݂̍��W���X�V
			if (can_move_pos[i].m_x == move_pos.m_x &&
				can_move_pos[i].m_y == move_pos.m_y) {
				m_current_pos = move_pos;
				return;
			}
		}
		// ��v���Ă��Ȃ��ꍇ�̓��[�v���s
		printf("���͐�ɂ͈ړ��ł��܂���A������x���͂��ĉ�����\n");
	}
}
