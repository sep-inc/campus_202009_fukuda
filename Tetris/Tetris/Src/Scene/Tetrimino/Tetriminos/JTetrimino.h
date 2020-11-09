#ifndef J_TETRIMINO_H_
#define J_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class JTetrimino
* @brief J字型テトリミノクラス
*/
class JTetrimino : TetriminoBase
{
public:
	JTetrimino();
	~JTetrimino();

private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];

};

#endif
