#ifndef S_TETRIMINO_H_
#define S_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class STetrimino
* @brief S字型テトリミノクラス
*/
class STetrimino : TetriminoBase
{
public:
	STetrimino();
	~STetrimino();


private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
};

#endif
