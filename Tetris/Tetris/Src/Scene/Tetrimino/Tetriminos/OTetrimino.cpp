#include "OTetrimino.h"

OTetrimino::OTetrimino()
{
	m_p_block_form = m_block_form;
}

OTetrimino::~OTetrimino()
{
}

int OTetrimino::m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH] = {
	{0,0,0,0,0},
	{0,0,1,1,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
