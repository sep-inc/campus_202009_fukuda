#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "SceneBase.h"
#include "../Draw/Drawers/DrawerBase.h"
#include "../AllDefinition.h"
#include <cinttypes>

/**
* @class SceneManager
* @brief Scene���Ǘ�����N���X
*/
class SceneManager
{
public:
	static SceneManager* Instance();

	/**
	* @brief �Q�[���S�̂̍X�V�֐�
	*/
	void Update();

	/**
	* @brief �`������Z�b�g����֐�
	*/
	void Draw(DrawerBase* drawer_);


private:
	/**
	* @brief �V�[�������֐�
	* 
	* @param scene_ ��������V�[�� 
	*/
	void CreateScene(SceneType scene_);

	/**
	* @brief �V�[���j���֐�
	*/
	void DestroyScene();

private:
	//! �X�V�����̃X�e�b�v
	enum class SceneStep : uint8_t {
		STEP_INITIALIZE,
		STEP_UPDATE,
		STEP_END
	};

	//! �V�[���̃|�C���^�ϐ�
	SceneBase* m_p_scene;
	//! ���݂̃X�e�b�v
	SceneStep m_step;
	//! ���݂̃V�[��
	SceneType m_now_scene;

private:
	SceneManager();
	~SceneManager();

	static SceneManager* p_instance;
};

#endif