#ifndef DRAWER_MANAGER_H_
#define DRAWER_MANAGER_H_

#include "Drawers/DrawerBase.h"
#include "../AllDefinition.h"

/**
* @class DrawerManager
* @brief Drawer�N���X���Q�[�����Ƃɐ؂�ւ���V���O���g���N���X
*/
class DrawerManager
{
public:
	static DrawerManager* Instance();

	/**
	* @brief �`��֐�
	*/
	void Draw();

	/**
	* @brief �`����N���A�֐�
	*/
	void Clear();

	/**
	* @brief Drawer�N���X�I���֐�
	* �w�肳�ꂽ�Q�[���ɉ����āADrawer�𐶐��A�j������֐�
	*
	* @param game_type_ ��������Drawer�̃Q�[���̎��
	*/
	void SelectDrawer(SceneType game_type_);

	/**
	* @brief Drawer�̃C���X�^���X��Ԃ��֐�
	*/
	inline DrawerBase* GetDrawerInstance()const { return m_p_drawer; }


private:
	/**
	* @brief Drawer�N���X�����֐�
	*
	* @param game_type_ ��������Drawer�̎��
	*/
	void CreateDrawer(SceneType game_type_);

	/**
	* @brief Drawer�N���X�j���֐�
	*/
	void DestroyDrawer();


private:
	//! Drawer�N���X�̃|�C���^�ϐ�
	DrawerBase* m_p_drawer;


private:
	DrawerManager();
	~DrawerManager();

	static DrawerManager* p_instance;
};

#endif
