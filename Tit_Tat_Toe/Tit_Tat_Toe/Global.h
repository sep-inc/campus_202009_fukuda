#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Drawer.h"
#include "Input.h"

/**
* @file Global.h
* @brief �O���[�o���ϐ��Q�̃w�b�_
*/


// �Q�[���I�u�W�F�N�g
//! �v���C���[�N���X�̃C���X�^���X
extern Player g_player;
//! ����N���X�̃C���X�^���X
extern Enemy g_enemy;
//! �Q�[���}�b�v�N���X�̃C���X�^���X
extern Map g_map;

// �V�X�e��
//! �`��N���X�̃C���X�^���X
extern Drawer g_drawer;
//! �C���v�b�g�N���X�̃C���X�^���X
extern Input g_input;

#endif

