#include "TTetrimino.h"

TTetrimino::TTetrimino()
{
	m_p_block_form = m_block_form;
}

TTetrimino::~TTetrimino()
{
}

int TTetrimino::m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH] = {
	{0,0,0,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
