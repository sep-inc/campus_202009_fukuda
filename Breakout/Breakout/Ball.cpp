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
	m_circle_center.x = m_pos.x + m_radius;
	m_circle_center.y = m_pos.y + m_radius;
}

void Ball::Update()
{
	switch (m_step) {
	case ObjectBase::Step::STEP_INITIALIZE:
		Init(BALL_INITIAL_X_POS, BALL_INITIAL_Y_POS, true, Kind::BALL);
		m_step = Step::STEP_RUN;
		break;
	case ObjectBase::Step::STEP_RUN:
		// 壁との当たり判定
		HitWall();
		// ブロックとの当たり判定
		HitBlock();
		// バーとの当たり判定
		HitBar();
		// 移動関数
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
	// 左右の壁に当たった場合反転
	if (m_pos.x + m_vec.x < 0 ||
		m_pos.x + m_vec.x > GAME_WIDTH - BALL_SIZE) {
		m_vec.x = -m_vec.x;
	}
	// 上下の壁に当たったら反転
	if (m_pos.y + m_vec.y > GAME_HEIGHT - BALL_SIZE ||
		m_pos.y + m_vec.y < 0) {
		m_vec.y = -m_vec.y;
	}
}

void Ball::HitBlock()
{
	for (int i = 0; i < BLOCK_NUM_X; i++) {
		for (int j = 0; j < BLOCK_NUM_Y; j++) {
			if (g_block_array.m_block_array[i][j].GetDrawFlag()) {
				// 左上、右上、左下、右下
				Vec2 rect_vertex1, rect_vertex2;
				rect_vertex1.x = g_block_array.m_block_array[i][j].GetBlockPos().x;
				rect_vertex1.y = g_block_array.m_block_array[i][j].GetBlockPos().y;
				rect_vertex2.x = g_block_array.m_block_array[i][j].GetBlockPos().x + BLOCK_WIDTH;
				rect_vertex2.y = g_block_array.m_block_array[i][j].GetBlockPos().y + BLOCK_HEIGHT;
				if (HitRectVertexHitBox(rect_vertex1, rect_vertex2)) {			// 頂点判定
					m_vec.x = -m_vec.x;
					m_vec.y = -m_vec.y;
					g_block_array.m_block_array[i][j].IsDelete();
				}
				else if (HitRectUpDownHitBox(rect_vertex1, rect_vertex2)) {	// 上下判定
					m_vec.y = -m_vec.y;
					g_block_array.m_block_array[i][j].IsDelete();
				}
				else if (HitRectLeftRightHitBox(rect_vertex1, rect_vertex2)) {		// 左右判定
					m_vec.x = -m_vec.x;
					g_block_array.m_block_array[i][j].IsDelete();
				}
			}
		}
	}
}

void Ball::HitBar()
{
	Vec2 rect_vertex1, rect_vertex2;
	rect_vertex1.x = g_bar.GetBarPos().x;
	rect_vertex1.y = g_bar.GetBarPos().y;
	rect_vertex2.x = g_bar.GetBarPos().x + BLOCK_WIDTH;
	rect_vertex2.y = g_bar.GetBarPos().y + BLOCK_HEIGHT;

	if (HitRectVertexHitBox(rect_vertex1, rect_vertex2)) {			// 頂点判定
		m_vec.x = -m_vec.x;
		m_vec.y = -m_vec.y;
	}
	else if (HitRectUpDownHitBox(rect_vertex1, rect_vertex2)) {	// 上下判定
		m_vec.y = -m_vec.y;
	}
	else if (HitRectLeftRightHitBox(rect_vertex1, rect_vertex2)) {		// 左右判定
		m_vec.x = -m_vec.x;
	}
}

void Ball::Move()
{
	m_pos.x += m_vec.x;
	m_pos.y += m_vec.y;

	// 円の中心座標更新
	m_circle_center.x = m_pos.x + m_radius;
	m_circle_center.y = m_pos.y + m_radius;
}


bool Ball::HitRectVertexHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos)
{
	if ((vertex1_pos.x - m_circle_center.x) * (vertex1_pos.x - m_circle_center.x)
		+ (vertex1_pos.y - m_circle_center.y) * (vertex1_pos.y - m_circle_center.y)
		<= m_radius * m_radius) {
		return true;
	}
	else if ((vertex2_pos.x - m_circle_center.x) * (vertex2_pos.x - m_circle_center.x)
		+ (vertex1_pos.y - m_circle_center.y) * (vertex1_pos.y - m_circle_center.y)
		<= m_radius * m_radius) {
		return true;
	}
	else if ((vertex2_pos.x - m_circle_center.x) * (vertex2_pos.x - m_circle_center.x)
		+ (vertex2_pos.y - m_circle_center.y) * (vertex2_pos.y - m_circle_center.y)
		<= m_radius * m_radius) {
		return true;
	}
	else if ((vertex1_pos.x - m_circle_center.x) * (vertex1_pos.x - m_circle_center.x)
		+ (vertex2_pos.y - m_circle_center.y) * (vertex2_pos.y - m_circle_center.y)
		<= m_radius * m_radius) {
		return true;
	}
	return false;
}

bool Ball::HitRectUpDownHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos)
{
	if (m_circle_center.x >= vertex1_pos.x &&
		m_circle_center.x <= vertex2_pos.x &&
		m_circle_center.y >= vertex1_pos.y - m_radius &&
		m_circle_center.y <= vertex2_pos.y + m_radius) {
		return true;
	}
	return false;
}

bool Ball::HitRectLeftRightHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos)
{
	if (m_circle_center.x >= vertex1_pos.x - m_radius &&
		m_circle_center.x <= vertex2_pos.x + m_radius &&
		m_circle_center.y >= vertex1_pos.y &&
		m_circle_center.y <= vertex2_pos.y) {
		return true;
	}
	return false;
}
