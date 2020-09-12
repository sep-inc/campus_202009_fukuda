#include "Ball.h"
#include "Global.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Init(float pos_x, float pos_y, bool enable, Kind kind)
{
	ObjectBase::Init(pos_x, pos_y, enable, kind);
	m_speed = BALL_SPEED;
	m_size.width = BALL_SIZE;
	m_size.height = BALL_SIZE;
	m_radius = m_size.width / 2.0f;
	m_vec.x = -m_speed;
	m_vec.y = -m_speed;
}

void Ball::Update()
{
	switch (m_step) {
	case ObjectBase::Step::STEP_INITIALIZE:
		Init(BALL_INITIAL_X_POS, BALL_INITIAL_Y_POS, true, Kind::BALL);
		m_step = Step::STEP_RUN;
		break;
	case ObjectBase::Step::STEP_RUN:
		// �ǂƂ̓����蔻��
		HitWall();
		// �u���b�N�Ƃ̓����蔻��
		// �o�[�Ƃ̓����蔻��
		// �ړ��֐�
		Move();
		break;
	case ObjectBase::Step::STEP_END:
		break;
	default:
		break;
	}
}

void Ball::SetUpDrawBuffer()
{
	g_drawer.SetBlankBuffer(m_pos.x, m_pos.y, m_kind);
}

void Ball::HitWall()
{
	// ���E�̕ǂɓ��������ꍇ���]
	if (m_pos.x + m_vec.x < 0 ||
		m_pos.x + m_vec.x > GAME_WIDTH - BALL_SIZE) {
		m_vec.x = -m_vec.x;
	}
	// �㉺�̕ǂɓ��������甽�]
	if (m_pos.y + m_vec.y > GAME_HEIGHT - BALL_SIZE ||
		m_pos.y + m_vec.y < 0) {
		m_vec.y = -m_vec.y;
	}
}

void Ball::HitBlock()
{
	// �K�v�Ȓl�̒�`
	Vec2 circle_center;
	circle_center.x = m_pos.x + m_radius;
	circle_center.y = m_pos.y + m_radius;
	for (int i = 0; i < BLOCK_NUM_X; i++) {
		for (int j = 0; j < BLOCK_NUM_Y; j++) {
			// ����A�E��A�����A�E��
			Vec2 rect_vertex1, rect_vertex2, rect_vertex3, rect_vertex4;
			rect_vertex1.x = g_block_array.m_block_array[i][j].GetBlockPos().x;
			rect_vertex1.y = g_block_array.m_block_array[i][j].GetBlockPos().y;
			rect_vertex2.x = g_block_array.m_block_array[i][j].GetBlockPos().x + BLOCK_WIDTH;
			rect_vertex2.y = g_block_array.m_block_array[i][j].GetBlockPos().y + BLOCK_HEIGHT;
			// if (HitRectVertexHitBox()) {			// ���_����
			// 	m_vec.x = -m_vec.x;
			// 	m_vec.y = -m_vec.y;
			// }
			if (circle_center.x > rect_vertex1.x &&
				circle_center.x < rect_vertex2.x &&
				circle_center.y > rect_vertex1.y - m_radius &&
				circle_center.y < rect_vertex2.y + m_radius) {	// ���E����
				m_vec.x = -m_vec.x;
			}
			else if (circle_center.x > rect_vertex1.x - m_radius &&
				circle_center.x < rect_vertex2.x + m_radius &&
				circle_center.y > rect_vertex1.y &&
				circle_center.y < rect_vertex2.y) {		// �㉺����
				m_vec.y = -m_vec.y;
			}
		}
	}
}

void Ball::Move()
{
	m_pos.x += m_vec.x;
	m_pos.y += m_vec.y;
}

// bool Ball::HitRectLeftRightHitBox()
// {
// 	
// 	
// 	return false;
// }
// 
// bool Ball::HitRectUpDownHitBox()
// {
// 	return false;
// }
// 
// bool Ball::HitRectVertexHitBox()
// {
// 	return false;
// }

// bool Ball::CalcCircleAndRectHitBox()
// {
// 	if (circle_center.x > rect_vertex1.x &&
// 		circle_center.x < rect_vertex2.x &&
// 		circle_center.y > rect_vertex1.y - circle_radius &&
// 		circle_center.y < rect_vertex2.y + circle_radius) {
// 		return true;
// 	}
// 	else if (circle_center.x > rect_vertex1.x - circle_radius &&
// 		circle_center.x < rect_vertex2.x + circle_radius &&
// 		circle_center.y > rect_vertex1.y &&
// 		circle_center.y < rect_vertex2.y) {
// 		return true;
// 	}
// 	else if ((rect_vertex1.x - circle_center.x) * (rect_vertex1.x - circle_center.x)
// 		+ (rect_vertex1.y - circle_center.y) * (rect_vertex1.y - circle_center.y)
// 		< circle_radius * circle_radius) {
// 		return true;
// 	}
// 	else if ((rect_vertex2.x - circle_center.x) * (rect_vertex2.x - circle_center.x)
// 		+ (rect_vertex1.y - circle_center.y) * (rect_vertex1.y - circle_center.y)
// 		< circle_radius * circle_radius) {
// 		return true;
// 	}
// 	else if ((rect_vertex2.x - circle_center.x) * (rect_vertex2.x - circle_center.x)
// 		+ (rect_vertex2.y - circle_center.y) * (rect_vertex2.y - circle_center.y)
// 		< circle_radius * circle_radius) {
// 		return true;
// 	}
// 	else if ((rect_vertex1.x - circle_center.x) * (rect_vertex1.x - circle_center.x)
// 		+ (rect_vertex2.y - circle_center.y) * (rect_vertex2.y - circle_center.y)
// 		< circle_radius * circle_radius) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }
