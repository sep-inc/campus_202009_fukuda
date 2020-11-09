#include "JTetrimino.h"

JTetrimino::JTetrimino()
{
	m_p_block_form = m_block_form;
}

JTetrimino::~JTetrimino()
{
}

int JTetrimino::m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH] = {
	{0,0,0,0,0},
	{0,1,0,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
