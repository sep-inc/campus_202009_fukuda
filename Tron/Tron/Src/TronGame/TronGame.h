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

};


#endif

