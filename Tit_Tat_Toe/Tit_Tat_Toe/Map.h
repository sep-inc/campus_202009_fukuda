#ifndef MAP_H_
#define MAP_H_

#include "Definition.h"

/**
* @file Map.h
* @brief Map�N���X�̃w�b�_
*/


/**
* @class Map
* @brief �Q�[�����W�ł̃}�X���Ǘ�����N���X
*/
class Map{
public:
	Map();
	~Map();

	/**
	* Map�N���X�̏������֐�
	* Step_Iitialize���̏����ŌĂ΂��
	*/
	void Init();

	/**
	* �����X�e�b�v�X�V�֐�
	* �����X�e�b�v���X�V���A�e�X�e�b�v���Ƃ̏������Ăяo��
	*/
	void Update();

	/**
	* ���s����֐�
	* �Ăяo���ꂽ�^�C�~���O�ł́A�Q�[���}�b�v�z��̏󋵂��珟�s���������
	* �Q�[���}�b�v�֍��W���Z�b�g��������ɌĂяo��
	*
	* return ���s���茋��
	*/
	MatchResult JudgeResult();

	/**
	* ���͂��ꂽ���W�̃}�X���󂩂ǂ����𒲂ׂ�֐�
	* Player�AEnemy�̓��͏����ŌĂ΂��
	*
	* @param pos ���͂��ꂽ���W
	* @return ���̓}�X���󂾂����ꍇ�Atrue
	*/
	bool IsEmpty(Vec2 pos);

	/**
	* �Q�[���I������֐�
	* ���s���ʂ��m�肵�Ă��邩�ǂ����ƁA�^�[���̌o�ߐ��ŃQ�[���̏I�����������
	* Player�AEnemy���e�X�̍X�V�����̑O�ɌĂяo��
	*
	* return �Q�[���I���������������Ă�����true
	*/
	bool IsFinishGame();

	/**
	* ��̃}�X�ڃ��X�g�̗v�f�����擾����֐�
	* �v�f�����擾����ۂɁAUpdateEnptyPos�֐��ŋ�̃}�X�ڃ��X�g��
	* �X�V���Ă���擾����
	*
	* @return ��̃}�X�ڃ��X�g�̗v�f��
	*/
	int8_t GetEmptyArraySize();

	/**
	* �I�������v�f�̍��W��Ԃ��֐�
	* �����ɓ������v�f�ԍ��̋�̃}�X�ڃ��X�g�̍��W��Ԃ�
	*
	* @param num �v�f��
	* @return �w�肳�ꂽ�v�f�ԍ��̍��W
	*/
	Vec2 GetSelectEnptyPos(int num);


public:
	// �Z�b�^�[�֐��Q

	/**
	* ���͍��W�Z�b�g�֐�
	* ���W�ɑΉ������Q�[���}�b�v�z��̗v�f�ɕ`��^�C�v���i�[����
	*
	* @param pos �Z�b�g������W
	* @param type �Z�b�g����`��^�C�v
	*/
	void SetPos(Vec2 pos, DrawType type);

	/**
	* ���s���ʃZ�b�g�֐�
	* Player�AEnemy�̏��s�𔻒肷�鏈���̌�Ɋe�X���Ăяo��
	*
	* @param result �Z�b�g���鏟�s����
	*/
	void SetResult(MatchResult result);


private:
	/**
	* ��̃}�X�ڃ��X�g���X�V����֐�
	* �Q�[���}�b�v�z�񂩂��̃}�X�ڂ̍��W�����X�g�A�b�v����
	* ��̃}�X�ڃ��X�g���Œ蒷�̔z��̂��߁A�g�p����z��̗v�f�����v�Z����
	*/
	void UpdateEnptyPos();

	/**
	* ��̃}�X�ڃ��X�g������������֐�
	* ��̃}�X�ڃ��X�g�ƁA�g�p�����z��̗v�f����0����������
	*/
	void ClearEmptyPos();


private:
	//! ���݂̏����X�e�b�v
	Step m_step;
	//! �Q�[���}�b�v�z��
	DrawType m_game_map[GAME_MAP_WIDTH][GAME_MAP_HEIGHT];
	//! ��̃}�X�ڃ��X�g�z��
	Vec2 m_empty_pos[GAME_MAP_WIDTH * GAME_MAP_HEIGHT];
	//! ��̃}�X�ڃ��X�g�̗v�f��
	int8_t m_empty_array_size;
	//! �Q�[���̌o�߃^�[����
	int8_t m_turn_num;
	//! ���݂̏��s�󋵕ۑ��ϐ�
	MatchResult m_result;
};


#endif