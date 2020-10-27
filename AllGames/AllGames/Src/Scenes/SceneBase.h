#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_

#include "../AllDefinition.h"
#include "../Draw/Drawers/DrawerBase.h"

/**
* @class SceneBase
* @brief �eScene�̊��N���X
*/
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	//! �X�V�����֐�
	virtual void Update() = 0;

	//! �`�揈���֐�
	virtual void Draw(DrawerBase* drawer_) = 0;

	inline SceneType GetNextScene()const { return m_next_scene; }

	/**
	* @brief �V�[���̏I���t���O��Ԃ��֐�
	*/
	bool IsGameFinish();

protected:
	SceneType m_next_scene;		//! ���̃V�[��
	bool m_is_scene_finish;		//! �V�[���I���t���O
};


#endif
