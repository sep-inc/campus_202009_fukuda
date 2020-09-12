#ifndef DRAWER_H_
#define DRAWER_H_

#include "Definition.h"

// 1�}�X�̃T�C�Y
#define UNIT_X 16
#define UNIT_Y 16
// �`��T�C�Y
#define DRAW_X GAME_WIDTH / UNIT_X + 2
#define DRAW_Y GAME_HEIGHT / UNIT_Y + 2


// �`��N���X
class Drawer {
public:
	Drawer();
	~Drawer();

	// �������֐�
	void Init();
	// �`��֐�
	void DrawTable();
	// �`��o�b�t�@�N���A
	void BufferClear();
	// �t���[���z��Ɖ��z���W�z��̍���
	void ComposeMap();
	// �`��o�b�t�@�֏������ފ֐� ���T�C�Y�w��͎��R
	void SetBlankBuffer(float x, float y, Kind kind, float width = 0.f , float height = 0.f);

private:
	// �`��p�p�����[�^
	struct DrawerParam {
		char m_kind;
	};

	DrawerParam m_blank_buffer[DRAW_X][DRAW_Y];				// �������p�z��
	DrawerParam m_draw_array[DRAW_X][DRAW_Y];				// �������ݗp�z��
};

#endif

