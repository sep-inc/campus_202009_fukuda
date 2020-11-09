#ifndef O_TETRIMINO_H_
#define O_TETRIMINO_H_

#include "../TetriminoBase.h"

/**
* @class OTetrimino
* @brief O字型テトリミノクラス
*/
class OTetrimino : TetriminoBase
{
public:
	OTetrimino();
	~OTetrimino();

private:
	static int m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];
	
};

#endif

