#ifndef I_TETRIMINO_H_
#define I_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class ITetrimino
* @brief I字型テトリミノクラス
*/
class ITetrimino : TetriminoBase
{
public:
	ITetrimino();
	~ITetrimino();

private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
};

#endif
