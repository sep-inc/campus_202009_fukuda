#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_
/**
* @file ObjectManager.h
* @brief ObjectManager�N���X�̃w�b�_
*/


#include "Player.h"
#include "GameStageManager.h"
#include "Input.h"
#include "Drawer.h"


/**
* @class ObjectManager
* @brief �Q�[���ɕK�v�ȃI�u�W�F�N�g�̐����Ɣj�����s���V���O���g���N���X
*/
class ObjectManager
{
public:
	/**
	* @brief �I�u�W�F�N�g�}�l�[�W���[���Ăяo���֐�
	*
	* @return ���̉������I�u�W�F�N�g�}�l�[�W���[�N���X�̃|�C���^��Ԃ�
	*/
	static ObjectManager* Instance();


	/**
	* @brief �I�u�W�F�N�g�����֐�
	* �Q�[���ɕK�v�ȃI�u�W�F�N�g�𐶐����A�e�|�C���^�ϐ��Ɋi�[����
	*/
	void CreateObjects();
	

	/**
	* @brief �I�u�W�F�N�g�j���֐�
	* �e�|�C���^�ϐ��Ɋi�[���ꂽ�I�u�W�F�N�g��j������
	*/
	void DeleteObjects();

public:
	Player* m_p_player;
	GameStageManager* m_p_game_stage_manager;
	Input* m_p_input;
	Drawer* m_p_drawer;

private:
	ObjectManager();
	~ObjectManager();

private:
	static ObjectManager* p_instance;
};

#endif