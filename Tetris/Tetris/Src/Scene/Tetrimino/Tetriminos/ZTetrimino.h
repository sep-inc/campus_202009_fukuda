#ifndef Z_TETRIMINO_H_
#define Z_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class ZTetrimino
* @brief Z字型テトリミノクラス
*/
class ZTetrimino : TetriminoBase
{
public:
	ZTetrimino();
	~ZTetrimino();


private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
};

#endif
