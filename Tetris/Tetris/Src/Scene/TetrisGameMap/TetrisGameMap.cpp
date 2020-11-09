#include "TetrisGameMap.h"
#include <cstring>

TetrisGameMap::TetrisGameMap():
	m_frame{}
{
}

TetrisGameMap::~TetrisGameMap()
{
}

void TetrisGameMap::Update()
{
}

void TetrisGameMap::Draw(DrawerBase* drawer_)
{
	// 枠の描画
	Vec2_Int frame_pos;
	for (frame_pos.m_y = 0; frame_pos.m_y < TETRIS_DRAW_HEIGHT; frame_pos.m_y++) {
		for (frame_pos.m_x = 0; frame_pos.m_x < TETRIS_DRAW_WIDTH; frame_pos.m_x++) {
			drawer_->SetDrawBuffer(frame_pos, m_frame[frame_pos.m_y][frame_pos.m_x].m_draw_string);
		}
	}
}

void TetrisGameMap::Init()
{
	// 枠初期化
	InitFrame();
}

void TetrisGameMap::InitFrame()
{
	// 枠の定義
	TetrisObjectParam frame = {};
	frame.m_type = TetrisObjectType::FRAME;
	strcpy_s(frame.m_draw_string, TETRIS_DRAW_STRING_SIZE, "□");

	// 枠を埋める処理
	for (int i = 0; i < TETRIS_DRAW_HEIGHT; i++) {
		m_frame[i][0] = frame;
		m_frame[i][TETRIS_DRAW_WIDTH - 1] = frame;
	}

	for (int i = 1; i < TETRIS_DRAW_WIDTH - 1; i++) {
		m_frame[TETRIS_DRAW_HEIGHT - 1][i] = frame;
	}
}
