#ifndef INPUT_H_
#define INPUT_H_

#include "Definition.h"

/**
* @file Input.h
* @brief Input�N���X�̃w�b�_
*/


/**
* @class Input
* @brief ���͊֌W�̏���������N���X
*/
class Input {
public:
	Input();
	~Input();

	/**
	* �v���C���[�̓��͊֐�
	* �v���C���[�����͂���X�AY���W�̏����擾����
	* Player�N���X����Ăяo�����
	*
	* @return ���͂��ꂽXY���W
	*/
	Vec2 InputPlayer();

private:

};

#endif

