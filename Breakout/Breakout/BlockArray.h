#ifndef BLOCKARRAY_H_
#define BLOCKARRAY_H_

#include "Block.h"

// �u���b�N��z��ŊǗ�����N���X
class BlockArray {
public:
	BlockArray();
	~BlockArray();

	// �������֐�
	void Init();
	// �X�e�b�v�X�V�֐�
	void Update();
	// �u���b�N�z�u�֐�
	void SetUpBlocks();
	// �e�u���b�N�̕`��o�b�t�@�֏������ފ֐����Ăяo���֐�
	void SetUpDrawBuffer();


	Block m_block_array[BLOCK_NUM_X][BLOCK_NUM_Y];		// �u���b�N�z��
private:
	
	ObjectBase::Step m_step;							// ���݂̃X�e�b�v
	

};

#endif

