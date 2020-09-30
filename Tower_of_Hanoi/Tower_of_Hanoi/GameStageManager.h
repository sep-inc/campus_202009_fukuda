#ifndef GAME_STAGE_MANAGER_H_
#define GAME_STAGE_MANAGER_H_

/**
* @file GameStageManager.h
* @brief GameStageManager�N���X�̃w�b�_
*/


#include "Definition.h"


/**
* @class GameStageManager
* @brief �~�Ղ̏�񂪓�����3�̍Y���Ǘ�����N���X
*/
class GameStageManager
{
public:
	GameStageManager();
	~GameStageManager();

	/**
	* @brief �X�e�b�v�����֐�
	* �X�e�b�v���Ƃ̏������s���A���̊֐������C���ŌĂяo��
	*/
	void UpdateStep();

	/**
	* @brief �������֐�
	*/
	void Init();

	/**
	* @brief �v���C���[���͏��Z�b�g�֐�
	*
	* @param source_num�@�ړ����̍Y�ԍ�
	* @param destination_pile�@�ړ���̍Y�ԍ�
	* @return ���͏�񂪐������Z�b�g������true
	*/
	bool SetInputPileNums(int source_num, int destination_num);


	/**
	* @brief �Q�[���N���A����֐�
	*
	* @return �N���A����������������true
	*/
	bool IsClear();


private:
	//! �Y�z��@���̗v�f�F�Y�ԍ��@�E�̗v�f : �Y�̗v�f�ԍ�
	DiskType m_piles[PILE_NUM][PILE_SIZE];	
	
	Step m_step;	//! ���݂̃X�e�b�v

};

#endif