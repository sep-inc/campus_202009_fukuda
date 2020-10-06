#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

/**
* @file DrawerManager.h
* @brief DrawerManager�N���X�̃w�b�_
*/

#include "DrawerBase.h"

/*
* @class DrawerManager
* @brief �Q�[�����Ƃ̕`��N���X�̊Ǘ����s���N���X
*/
class DrawerManager {
public:
	static DrawerManager* Instance();

	/**
	* @brief Drawer�N���X�����֐�
	* �e�Q�[�����Ƃ�Drawer�N���X�𐶐�����
	*/
	void CreateDrawer();

	/**
	* @brief ��������Drawer�N���X�̃|�C���^��Ԃ�
	*/
	inline DrawerBase* GetDrawerInstance()const { return m_drawer; }

private:
	DrawerBase* m_drawer;

private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;

};

#endif
