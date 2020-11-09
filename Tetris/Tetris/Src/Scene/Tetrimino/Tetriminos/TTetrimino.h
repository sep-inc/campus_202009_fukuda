#ifndef T_TETRIMINO_H_
#define T_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class TTetrimino
* @brief T字型テトリミノクラス
*/
class TTetrimino : TetriminoBase
{
public:
	TTetrimino();
	~TTetrimino();


private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
};

#endif
