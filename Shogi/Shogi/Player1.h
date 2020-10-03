#ifndef PLAYER1_H_
#define PLAYER1_H_

/**
* @file Player1.h
* @brief Player1�N���X�̃w�b�_
*/


#include "PlayerBase.h"

/**
* @class Player1
* @brief Player1�̏����N���X
*/
class Player1 : public PlayerBase {
public:
	Player1();
	~Player1();


	/**
	* @brief �����X�V�֐�
	*/
	void Update()override;

	/**
	* @brief �������֐�
	*/
	void Init()override;

	/**
	* @brief �ǂ̋���ړ������邩�̑I�������֐�
	* @brief �I�񂾍��W
	*/
	virtual Vec2 SelectPiece()override;

	/**
	* @brief �ǂ̃}�X�ֈړ������邩�̑I�������֐�
	* @brief �I�񂾍��W
	*/
	virtual Vec2 SelectMoveSquares()override;


};

#endif
