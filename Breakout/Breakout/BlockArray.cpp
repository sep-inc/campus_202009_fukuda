#include "BlockArray.h"

BlockArray::BlockArray()
{
}

BlockArray::~BlockArray()
{
}

void BlockArray::Init()
{
	m_step = ObjectBase::Step::STEP_INITIALIZE;
	SetUpBlocks();
}

void BlockArray::Update()
{
	switch (m_step) {
	case ObjectBase::Step::STEP_INITIALIZE:
		Init();
		m_step = ObjectBase::Step::STEP_RUN;
		break;
	case ObjectBase::Step::STEP_RUN:
		break;
	case ObjectBase::Step::STEP_END:
		break;
	default:
		break;
	}
}

void BlockArray::SetUpBlocks()
{	
	// ブロックをBlockArray配列の中に配置する
	float fy = BLOCK_INITIAL_Y_POS;
	for (int y = 0; y < BLOCK_NUM_Y; y++) {
		float fx = BLOCK_INITIAL_X_POS;
		for (int x = 0; x < BLOCK_NUM_X; x++) {
			m_block_array[x][y].Init(fx, fy, true, Kind::BLOCK);
			fx += BLOCK_WIDTH;
		}
		fy += BLOCK_HEIGHT;
	}
	
}

void BlockArray::SetUpDrawBuffer()
{
	for (int y = 0; y < BLOCK_NUM_Y; y++) {
		for (int x = 0; x < BLOCK_NUM_X; x++) {
			m_block_array[x][y].SetUpDrawBuffer();
		}
	}
}
