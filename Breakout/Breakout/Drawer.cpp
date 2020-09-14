#include "Drawer.h"
#include <string.h>
#include <cstdio>

Drawer::Drawer()
{
}

Drawer::~Drawer()
{
}


void Drawer::Init()
{
	// �������p�o�b�t�@�̏�����
	memset(m_blank_buffer, 0, sizeof(m_blank_buffer));
	// �t���[���̐ݒ�
	for (int i = 0; i < DRAW_X; i++) {
		m_blank_buffer[i][0].m_kind = Kind::FRAME;
		m_blank_buffer[i][DRAW_Y - 1].m_kind = Kind::FRAME;
	}

	for (int i = 0; i < DRAW_Y; i++) {
		m_blank_buffer[0][i].m_kind = Kind::FRAME;
		m_blank_buffer[DRAW_X - 1][i].m_kind = Kind::FRAME;
	}
}

void Drawer::DrawTable()
{
	for (int i = 0; i < DRAW_Y; i++) {
		for (int j = 0; j < DRAW_X; j++) {
			switch (m_draw_array[j][i].m_kind) {
			case Kind::BALL:
				printf("��");
				break;
			case Kind::BAR:
				printf("��");
				break;
			case Kind::BLOCK:
				printf("��");
				break;
			case Kind::FRAME:
				printf("��");
				break;
			default:
				printf("�@");
				break;
			}
		}
		printf("\n");
	}
}

void Drawer::BufferClear()
{
	// �`�悵���o�b�t�@������������
	memcpy(m_draw_array, m_blank_buffer, sizeof(m_blank_buffer));
}

void Drawer::SetDrawBuffer(float x, float y, Kind kind ,float width,float height)
{
	// �o�b�t�@�ɏ������ޗp�̍��W�ɂ���
	int buffer_x = x / UNIT_X + 1;
	int buffer_y = y / UNIT_Y + 1;

	// �T�C�Y�w�肪���邩�A�Ȃ����̕���
	if (width != 0 && height != 0) {
		int buffer_x_num = width / UNIT_X;
		int buffer_y_num = height / UNIT_Y;
		for (int iy = 0; iy < buffer_y_num; iy++) {
			for (int ix = 0; ix < buffer_x_num; ix++) {
				m_draw_array[buffer_x + ix][buffer_y + iy].m_kind = kind;
			}
		}
	}
	else {
		m_draw_array[buffer_x][buffer_y].m_kind = kind;
	}
}