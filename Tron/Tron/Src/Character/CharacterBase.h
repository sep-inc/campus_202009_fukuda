#ifndef CHARACTER_BASE_H_
#define CHARACTER_BASE_H_

/**
* @file CharacterBase.h
* @brief CharacterBase�N���X�̃w�b�_
*/

#include "../Definition.h"
#include "../GameMap/GameMap.h"

/**
* @class CharacterBase
* @brief �L�����N�^�[�̊��N���X
*/
class CharacterBase 
{
public:
	CharacterBase();
	virtual ~CharacterBase();

	/**
	* @brief �X�V�֐�
	*/
	virtual void Update();

	/**
	* @brief ���g�̃p�����[�^��Ԃ��֐�
	* @return ���g�̃p�����[�^
	*/
	inline CharacterParam GetMyParam()const { return m_param; }

	/**
	* @brief �ړ�������W��Ԃ��֐�
	* @return �ړ�������W
	*/
	inline Vec2 GetMovePos()const { return m_current_pos; }

	/**
	* @brief �Q�[���}�b�v�̃|�C���^���擾����֐�
	* @param �Q�[���}�b�v�̃|�C���^
	*/
	void SetGameMapPointer(GameMap* map_);


protected:
	//! �ړ����������I������֐�
	virtual void SelectMoveDirection() = 0;


protected:
	CharacterParam m_param;	//! ���g�̃^�C�v�ƕ`�敶���̃f�[�^
	Vec2 m_current_pos;		//! ���݂̈ʒu
	GameMap* m_p_map;		//! �Q�[���}�b�v�̃|�C���^�ϐ�
};

#endif

