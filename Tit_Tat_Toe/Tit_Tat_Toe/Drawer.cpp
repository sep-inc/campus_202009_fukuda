#include "Drawer.h"
#include <cstdio>
#include <cstring>

Drawer::Drawer():
	m_blank_buffer{},
	m_draw_buffer{},
	m_result(MatchResult::None)
{
}

Drawer::~Drawer()
{
}

void Drawer::Init()
{
	// 初期化用バッファの初期化
	m_blank_buffer[0][0] = DrawType::HalfWidthSpace;
	m_blank_buffer[1][0] = DrawType::HalfWidthSpace;
	m_blank_buffer[0][1] = DrawType::HalfWidthSpace;
	m_blank_buffer[0][3] = DrawType::HalfWidthSpace;
	m_blank_buffer[0][5] = DrawType::HalfWidthSpace;
	m_blank_buffer[0][7] = DrawType::HalfWidthSpace;
	m_blank_buffer[3][0] = DrawType::HalfWidthSpace2;
	m_blank_buffer[5][0] = DrawType::HalfWidthSpace2;
	m_blank_buffer[7][0] = DrawType::HalfWidthSpace2;
	m_blank_buffer[2][0] = DrawType::CharA;
	m_blank_buffer[4][0] = DrawType::CharB;
	m_blank_buffer[6][0] = DrawType::CharC;
	m_blank_buffer[0][2] = DrawType::Num1;
	m_blank_buffer[0][4] = DrawType::Num2;
	m_blank_buffer[0][6] = DrawType::Num3;
	m_blank_buffer[1][1] = DrawType::UpperLeft;
	m_blank_buffer[1][7] = DrawType::LowerLeft;
	m_blank_buffer[7][1] = DrawType::UpperRight;
	m_blank_buffer[7][7] = DrawType::LowerRight;
	m_blank_buffer[3][1] = DrawType::UpperMiddle;
	m_blank_buffer[5][1] = DrawType::UpperMiddle;
	m_blank_buffer[1][3] = DrawType::MiddleLeft;
	m_blank_buffer[1][5] = DrawType::MiddleLeft;
	m_blank_buffer[7][3] = DrawType::MiddleRight;
	m_blank_buffer[7][5] = DrawType::MiddleRight;
	m_blank_buffer[3][7] = DrawType::LowerMiddle;
	m_blank_buffer[5][7] = DrawType::LowerMiddle;
	m_blank_buffer[3][3] = DrawType::Middle;
	m_blank_buffer[5][3] = DrawType::Middle;
	m_blank_buffer[3][5] = DrawType::Middle;
	m_blank_buffer[5][5] = DrawType::Middle;
	m_blank_buffer[2][1] = DrawType::HorizontalLine;
	m_blank_buffer[4][1] = DrawType::HorizontalLine;
	m_blank_buffer[6][1] = DrawType::HorizontalLine;
	m_blank_buffer[2][3] = DrawType::HorizontalLine;
	m_blank_buffer[4][3] = DrawType::HorizontalLine;
	m_blank_buffer[6][3] = DrawType::HorizontalLine;
	m_blank_buffer[2][5] = DrawType::HorizontalLine;
	m_blank_buffer[4][5] = DrawType::HorizontalLine;
	m_blank_buffer[6][5] = DrawType::HorizontalLine;
	m_blank_buffer[2][7] = DrawType::HorizontalLine;
	m_blank_buffer[4][7] = DrawType::HorizontalLine;
	m_blank_buffer[6][7] = DrawType::HorizontalLine;
	m_blank_buffer[1][2] = DrawType::VerticalLine;
	m_blank_buffer[3][2] = DrawType::VerticalLine;
	m_blank_buffer[5][2] = DrawType::VerticalLine;
	m_blank_buffer[7][2] = DrawType::VerticalLine;
	m_blank_buffer[1][4] = DrawType::VerticalLine;
	m_blank_buffer[3][4] = DrawType::VerticalLine;
	m_blank_buffer[5][4] = DrawType::VerticalLine;
	m_blank_buffer[7][4] = DrawType::VerticalLine;
	m_blank_buffer[1][6] = DrawType::VerticalLine;
	m_blank_buffer[3][6] = DrawType::VerticalLine;
	m_blank_buffer[5][6] = DrawType::VerticalLine;
	m_blank_buffer[7][6] = DrawType::VerticalLine;


	// 描画用バッファを初期化用バッファで初期化
	BufferClear();
}

void Drawer::Run()
{
	// 描画
	DrawBuffer();
	// 試合結果が出ていたら結果を描画
	if (m_result != MatchResult::None) {
		DrawResult();
	}
	// 描画用バッファをクリア
	BufferClear();
}

void Drawer::BufferClear()
{
	// 描画用バッファに初期化用バッファをコピー
	memcpy(m_draw_buffer, m_blank_buffer, sizeof(m_blank_buffer));
}

void Drawer::DrawBuffer()
{
	// 描画バッファに格納した描画タイプをもとに表示する
	for (int x = 0; x < DRAW_BUFFER_WIDTH; x++) {
		for (int y = 0; y < DRAW_BUFFER_HEIGHT; y++) {
			switch (m_draw_buffer[y][x]) {
			case DrawType::HalfWidthSpace:
				printf(" ");
				break;
			case DrawType::HalfWidthSpace2:
				printf("  ");
				break;
			case DrawType::UpperLeft:
				printf("┏");
				break;
			case DrawType::UpperRight:
				printf("┓");
				break;
			case DrawType::LowerLeft:
				printf("┗");
				break;
			case DrawType::LowerRight:
				printf("┛");
				break;
			case DrawType::UpperMiddle:
				printf("┳");
				break;
			case DrawType::LowerMiddle:
				printf("┻");
				break;
			case DrawType::MiddleLeft:
				printf("┣");
				break;
			case DrawType::MiddleRight:
				printf("┫");
				break;
			case DrawType::Middle:
				printf("╋");
				break;
			case DrawType::VerticalLine:
				printf("┃");
				break;
			case DrawType::HorizontalLine:
				printf(" ━ ");
				break;
			case DrawType::CharA:
				printf("A");
				break;
			case DrawType::CharB:
				printf("  B");
				break;
			case DrawType::CharC:
				printf("  C");
				break;
			case DrawType::Num1:
				printf("1");
				break;
			case DrawType::Num2:
				printf("2");
				break;
			case DrawType::Num3:
				printf("3");
				break;
			case DrawType::Player:
				printf(" 〇");
				break;
			case DrawType::Enemy:
				printf(" ×");
				break;
			default:
				printf("   ");
				break;
			}
		}
		printf("\n");
	}
	
}

void Drawer::DrawResult()
{
	// 勝敗結果に応じた表示処理
	switch (m_result) {
	case MatchResult::Win:
		printf("プレイヤーの勝利\n");
		break;
	case MatchResult::Lose:
		printf("相手の勝利\n");
		break;
	case MatchResult::Draw:
		printf("引き分け\n");
	default:
		break;
	}
}

void Drawer::SetGameMap(DrawType map[][GAME_MAP_HEIGHT])
{
	// ゲームマップの座標を描画バッファ用の座標に格納する
	m_draw_buffer[2][2] = map[0][0];	// 1A
	m_draw_buffer[4][2] = map[1][0];	// 1B
	m_draw_buffer[6][2] = map[2][0];	// 1C
	m_draw_buffer[2][4] = map[0][1];	// 2A
	m_draw_buffer[4][4] = map[1][1];	// 2B
	m_draw_buffer[6][4] = map[2][1];	// 2C
	m_draw_buffer[2][6] = map[0][2];	// 3A
	m_draw_buffer[4][6] = map[1][2];	// 3B
	m_draw_buffer[6][6] = map[2][2];	// 3C
}

void Drawer::SetResult(MatchResult result)
{
	m_result = result;
}
