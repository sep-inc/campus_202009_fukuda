#ifndef SELECT_GAME_SCENE_H_
#define SELECT_GAME_SCENE_H_

#include "../SceneBase.h"
#include "../../AllDefinition.h"
#include "SelectGameDefinition.h"

#include <cinttypes>

/**
* @class SelectGameScene
* @brief �Q�[���̑I���V�[���N���X
*/
class SelectGameScene : public SceneBase
{
public:
	SelectGameScene();
	~SelectGameScene();

	/**
	* @brief �X�V�����֐�
	*/
	void Update()override;

	/**
	* @brief �`�揈���֐�
	*/
	void Draw(DrawerBase* drawer_)override;


private:
	/**
	* @brief �������֐�
	*/
	void Init();
	/**
	* @brief �V�[���I�������֐�
	*
	* @return bool Enter�������ꂽ��true
	*/
	bool SelectScene();


private:
	//! SelectGame�̍X�V�X�e�b�v
	enum class SelectGameStep {
		STEP_INITIALIZE,
		STEP_UPDATE,
		STEP_END
	};

	//! �I������Q�[���̏����܂Ƃ߂��\����
	struct SelectGameParam {
		SceneType m_scene_type;									//! ���g�̎��
		char m_title_string[SELECT_GAME_DRAW_STRING_SIZE];		//! �`����

		SelectGameParam() :
			m_scene_type(SceneType::TYPE_NONE),
			m_title_string(" ")
		{
		}
	};

	//! ���݂̃X�e�b�v
	SelectGameStep m_now_step;
	//! �Q�[���̏��̔z��
	SelectGameParam m_games[ALL_GAME_NUM];
	//! ���ݑI�𒆂̃V�[���̔ԍ�
	int m_now_select_index;

};

#endif
