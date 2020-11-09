#ifndef TETRIS_GAME_MAP_H_
#define TETRIS_GAME_MAP_H_

#include "../../TetrisDefinition.h"
#include "../../Draw/DrawerBase.h"

/**
* @class TetrisGameMap
* @brief Tetrisのマップクラス
*/
class TetrisGameMap
{
public:
	TetrisGameMap();
	~TetrisGameMap();

	/**
	* @brief 更新処理関数
	*/
	void Update();

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_);

	/**
	* @brief 初期化関数
	*/
	void Init();

private:
	/**
	* @brief 枠の初期化関数
	*/
	void InitFrame();

private:
	TetrisObjectParam m_frame[TETRIS_DRAW_HEIGHT][TETRIS_DRAW_WIDTH];
	
};

#endif

