#include "ZTetrimino.h"

ZTetrimino::ZTetrimino()
{
	m_p_block_form = m_block_form;
}

ZTetrimino::~ZTetrimino()
{
}

int ZTetrimino::m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH] = {
	{0,0,0,0,0},
	{0,1,1,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
