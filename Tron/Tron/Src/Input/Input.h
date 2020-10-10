#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief Input�N���X�̃w�b�_
*/

#include  "../Definition.h"

//! ���̓L�[
#define LEFT_KEY	0x4b
#define RIGHT_KEY	0x4d
#define UP_KEY		0x48
#define DOWN_KEY	0x50

/**
* @class Input
* @brief ���͏����N���X
*/
class Input 
{
public:
	static Input* Instance();

	/**
	* @brief �������͏����֐�
	* @return ���͂��ꂽ�����ɍ��킹���ړ���
	*/
	Vec2 InputDirection();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif
