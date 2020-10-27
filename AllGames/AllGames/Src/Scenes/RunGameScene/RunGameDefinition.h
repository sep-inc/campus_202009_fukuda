#ifndef RUN_GAME_DEFINITION_H_
#define RUN_GAME_DEFINITION_H_

/**
* @file RunGameDefinition.h
* @brief RunGame�Ŏg�p�����`���܂Ƃ߂��w�b�_
*/

#include <cinttypes>

/* �萔�Q */

//! Run�Q�[���̕`��p�o�b�t�@�T�C�Y
#define RUNGAME_DRAW_WIDTH  11
#define RUNGAME_DRAW_HEIGHT 10

//! �`�悷�镶����̃T�C�Y
#define RUNGAME_DRAW_STRING_SIZE 8

//! �}�b�v�̃T�C�Y
#define RUNGAME_MAP_WIDTH  50
#define RUNGAME_MAP_HEIGHT 10

//! �}�b�v�̃p�[�c�̃T�C�Y
#define RUNGAME_MAP_PARTS_WIDTH 5

//! �}�b�v�̃p�[�c�̐�
#define RUNGAME_MAP_PARTS_NUM 4

//! �X�V�t���[����
#define UPDATE_FRAME_NUM 5

//! �v���C���[�̏����ʒu
#define RUNGAME_PLAYER_INIT_POS_X 1
#define RUNGAME_PLAYER_INIT_POS_Y 5

//! �v���C���[�̈ړ����x
#define RUNGAME_PLAYER_MOVE_SPEED 1

//! �v���C���[�̃W�����v�̍���
#define RUNGAME_PLAYER_JUMP_HEIGHT 2


/* �񋓌Q */

//! �I�u�W�F�N�g�̎��
enum class RunGameObjectType : uint8_t
{
	TYPE_NONE,	//! �^�C�v����
	PLAYER,		//! �v���C���[
	GROUND,		//! �n��

	MAX_TYPE
};


/* �\���̌Q */

//! �I�u�W�F�N�g�̃p�����[�^
struct RunGameObjectParam
{
	RunGameObjectType m_type;						//! ���g�̎��
	char m_draw_string[RUNGAME_DRAW_STRING_SIZE];	//! �`�敶����

	RunGameObjectParam() :
		m_type(RunGameObjectType::TYPE_NONE),
		m_draw_string("�@")
	{}
};

#endif
