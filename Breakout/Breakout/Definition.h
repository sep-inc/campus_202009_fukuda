#ifndef DEFINITION_H_
#define DEFINITION_H_

/* �萔�܂Ƃ� */

// �t���[���T�C�Y
#define GAME_WIDTH  320
#define GAME_HEIGHT 640


// �u���b�N�T�C�Y
#define BLOCK_WIDTH  32
#define BLOCK_HEIGHT 16
// �u���b�N�������W
#define BLOCK_INITIAL_X_POS 0
#define BLOCK_INITIAL_Y_POS 0
// �u���b�N�̐�
#define BLOCK_NUM_X GAME_WIDTH / BLOCK_WIDTH
#define BLOCK_NUM_Y 2


// �o�[�T�C�Y
#define BAR_WIDTH  80
#define BAR_HEIGHT 16
// �o�[�������W
#define BAR_INITIAL_X_POS GAME_WIDTH / 2
#define BAR_INITIAL_Y_POS GAME_HEIGHT - (BAR_HEIGHT * 5)
// �o�[���x
#define BAR_SPEED 16


// �{�[���T�C�Y
#define BALL_SIZE 16
// �{�[���������W
#define BALL_INITIAL_X_POS GAME_WIDTH / 2
#define BALL_INITIAL_Y_POS BAR_INITIAL_Y_POS - BALL_SIZE
// �{�[���̑��x
#define BALL_SPEED 16



/* ���ʂŎg���\���̂�񋓑̂܂Ƃ� */

struct Vec2 {
	float x, y;
};

struct Size {
	float width, height;
};

// �I�u�W�F�N�g�̎��
enum Kind
{
	NONE,
	BALL,
	BAR,
	BLOCK,
	FRAME
};

#endif

