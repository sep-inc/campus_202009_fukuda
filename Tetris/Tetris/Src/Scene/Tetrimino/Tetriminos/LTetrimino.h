#ifndef L_TETRIMINO_H_
#define L_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class LTetrimino
* @brief L字型テトリミノクラス
*/
class LTetrimino : TetriminoBase
{
public:
	LTetrimino();
	~LTetrimino();


private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
};

#endif
