#ifndef PLAYER2_H_
#define PLAYER2_H_

/**
* @file Player2.h
* @brief Player2�N���X�̃w�b�_
*/

#include "PlayerBase.h"

/**
* @class Player2
* @brief Player2�̏����N���X
*/
class Player2 : public PlayerBase {
public:
	Player2();
	~Player2();


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
	*/
	virtual void SelectPiece()override;

	/**
	* @brief �ǂ̃}�X�ֈړ������邩�̑I�������֐�
	*/
	virtual void SelectMoveSquares()override;


};

#endif
