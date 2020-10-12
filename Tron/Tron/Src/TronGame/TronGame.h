#ifndef TRON_GAME_H_
#define TRON_GAME_H_

/**
* @file TronGame.h
* @brief TronGame�N���X�̃w�b�_
*/

#include "../Character/CharacterBase.h"
#include "../GameMap/GameMap.h"

/**
* @class TronGame
* @brief �Q�[���{��
*/
class TronGame
{
public:
	static TronGame* Instance();

	/**
	* @brief �Q�[���{�̂̍X�V�֐�
	*/
	void Update();

	/**
	* @brief �I�u�W�F�N�g�����֐�
	*/
	void CreateObjects();

	/**
	* @brief �I�u�W�F�N�g�j���֐�
	*/
	void DestroyObjects();

	//! �e�I�u�W�F�N�g�̃|�C���^�ϐ��Q
	CharacterBase* m_p_player;
	CharacterBase* m_p_enemy;
	GameMap* m_p_game_map;


	//! �Q�[���I������֐�
	bool IsGameFinish() { return m_is_game_finish; }

	//! �Q�[���I���t���O�擾�֐�

	/**
	* @brief �������o�b�t�@�ւ̏������݊֐�
	* �Q�[���̏��������݂̂ɍs��
	*/
	void SetBlankMap();

	/**
	* @brief �Q�[���}�b�v�̏������݊֐�
	*/
	void SetDrawMap();

	

private:
	TronGame();
	~TronGame();

	static TronGame* p_instance;

private:
	//! �����X�e�b�v
	enum class TronGameStep {
		STEP_INITIALIZE,	//! �������X�e�b�v
		STEP_UPDATE,		//! �X�V�X�e�b�v
		STEP_END			//! �I���X�e�b�v
	};

	TronGameStep m_step;	//! ���݂̃X�e�b�v

	bool m_cannot_move_player;	//! �v���C���[�������Ȃ��Ȃ������ǂ���
	bool m_cannot_move_enemy;	//! �G�l�~�[�������Ȃ��Ȃ������ǂ���

	bool m_is_game_finish;	//! �Q�[���I���t���O

};


#endif

