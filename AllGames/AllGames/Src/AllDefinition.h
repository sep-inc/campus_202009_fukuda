#ifndef ALL_DEFINITION_H_
#define ALL_DEFINITION_H_

/**
* @file AllDefinition.h
* @brief �S�ẴQ�[���Ŏg�p�����`���܂Ƃ߂��w�b�_
*/

#include <cinttypes>

/* �Q�[���̑��� */
#define ALL_GAME_NUM 6


/* �񋓌Q */

//! �Q�[���̎��
enum class SceneType : uint8_t
{
	TYPE_NONE,		//! �^�C�v����
	SELECT_GAME,	//! �Q�[���I���V�[��
	TIT_TAT_TOE,	//! �}���o�c�Q�[��
	TOWER_OF_HANOI,	//! �n�m�C�̓�
	TRON,			//! �g����
	PACMEN,			//! �p�b�N�}��
	RUN_GAME,		//! Run�Q�[��
	SHOGI			//! ����

};

//! �L�[�̎��
enum KeyType
{
	NULL_KEY	= 0x00,		//! NULL
	ENTER_KEY	= 0x0d,		//! Enter
	SO_KEY		= 0x0e,		//! �V�t�g�A�E�g
	ESCAPE_KEY  = 0x1b,		//! Esc
	SPACE_KEY	= 0x20,		//! Space

	LEFT_KEY	= 0x4b,		//! �����L�[
	RIGHT_KEY	= 0x4d,		//! �E���L�[
	UP_KEY		= 0x48,		//! ����L�[
	DOWN_KEY	= 0x50		//! �����L�[
};


#endif
