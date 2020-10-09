#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

/**
* @file DrawerManager.h
* @brief DrawerManager�N���X�̃w�b�_
*/

#include "DrawerBase.h"
#include "../Definition.h"

/**
* @class DrawerManager
* @brief Drawer�N���X���Q�[�����Ƃɐ؂�ւ���V���O���g���N���X
*/
class DrawerManager {
public:
	static DrawerManager* Instance();

	/**
	* @brief Drawer�N���X�̐����֐�
	* �w�肳�ꂽ�Q�[�����Ƃ�Drawer�N���X�𐶐�����@�����݂�1��ނ݂̂̐���
	*/
	void CreateDrawer();

	/**
	* @brief Drawer�N���X�̔j���֐�
	*/
	void DeleteDrawer();

	//! Draewr�N���X�̃|�C���^
	DrawerBase* m_p_drawer;

private:
	DrawerManager();
	~DrawerManager();
	
	static DrawerManager* p_instance;

};

#endif

