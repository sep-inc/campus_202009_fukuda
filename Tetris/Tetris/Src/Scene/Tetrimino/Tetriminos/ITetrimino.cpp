#include "Itetrimino.h"

ITetrimino::ITetrimino()
{
	m_p_block_form = m_block_form;
}

ITetrimino::~ITetrimino()
{
}

int ITetrimino::m_block_form[TETRIMINO_HEIGHT][TETRIMINO_WIDTH] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
