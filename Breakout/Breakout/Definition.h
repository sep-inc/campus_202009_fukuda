#ifndef DEFINITION_H_
#define DEFINITION_H_

/* 定数まとめ */

// フレームサイズ
#define GAME_WIDTH  320
#define GAME_HEIGHT 640


// ブロックサイズ
#define BLOCK_WIDTH  32
#define BLOCK_HEIGHT 16
// ブロック初期座標
#define BLOCK_INITIAL_X_POS 0
#define BLOCK_INITIAL_Y_POS 0
// ブロックの数
#define BLOCK_NUM_X GAME_WIDTH / BLOCK_WIDTH
#define BLOCK_NUM_Y 2


// バーサイズ
#define BAR_WIDTH  80
#define BAR_HEIGHT 16
// バー初期座標
#define BAR_INITIAL_X_POS GAME_WIDTH / 2
#define BAR_INITIAL_Y_POS GAME_HEIGHT - (BAR_HEIGHT * 5)
// バー速度
#define BAR_SPEED 16


// ボールサイズ
#define BALL_SIZE 16
// ボール初期座標
#define BALL_INITIAL_X_POS GAME_WIDTH / 2
#define BALL_INITIAL_Y_POS BAR_INITIAL_Y_POS - BALL_SIZE
// ボールの速度
#define BALL_SPEED 16



/* 共通で使う構造体や列挙体まとめ */

struct Vec2 {
	float x, y;
};

struct Size {
	float width, height;
};

// オブジェクトの種類
enum Kind
{
	NONE,
	BALL,
	BAR,
	BLOCK,
	FRAME
};

#endif

