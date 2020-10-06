#ifndef SHOGI_GAME_H_
#define SHOGI_GAME_H_

/**
* @file ShogiGame.h
* @brief ShogiGame�N���X�̃w�b�_
*/

#include "../Definition.h"
#include "../Player/Player1.h"
#include "../Player/Player2.h"
#include "../ShogiBoard/ShogiBoard.h"
#include "../Piece/PieceData.h"
/**
* @class ShogiGame
* @brief �����Q�[���{�̂̃N���X
*/
class ShogiGame {
public:
	static ShogiGame* Instance();

	/**
	* @brief ShogiGame�N���X�̍X�V�֐�
	*/
	void Update();

	/**
	* @brief �I�u�W�F�N�g�����֐�
	*/
	void CreateObjects();

	/**
	* @brief �I�u�W�F�N�g�j���֐�
	*/
	void DeleteObjects();

	/**
	* @brief �I�������Ԃ��֐�
	* Main�̃��[�v���I�������鏈���Ŏg�p
	*
	* @return �I���t���O
	*/
	bool IsGameFinish();

	void SetShogiBoard();

	//! �I�u�W�F�N�g�̃|�C���^�ϐ��Q
	Player1* m_p_player1;
	Player2* m_p_player2;
	ShogiBoard* m_p_shogi_board;
	PieceData* m_p_pieces;

private:
	ShogiGame();
	~ShogiGame();

	static ShogiGame* p_instance;

private:
	Step m_step;			//! ���݂̃X�e�b�v
	int m_turn_counter;		//! �^�[���o�ߐ�
	bool m_is_game_finish;	//! �Q�[���I���t���O

};

#endif

