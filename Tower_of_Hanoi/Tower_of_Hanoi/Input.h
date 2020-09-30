#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief Input�N���X�̃w�b�_
*/


/**
* @class Input
* @brief ���͏������܂Ƃ߂��N���X
*/
class Input
{
public:
	Input();
	~Input();

	/**
	* @brief �ړ����̍Y�ԍ����͊֐�
	* �ړ����������~�Ղ�����Y�̔ԍ�����͂���
	*
	* @return ���͂����Y�̔ԍ�
	*/
	int SelectSourcePile();


	/**
	* @brief �ړ���̍Y�ԍ����͊֐�
	* 
	* @param source_pile_num�@�ړ����̍Y�ԍ�
	* @return ���͂����Y�ԍ�
	*/
	int SelectDestinationPile(int source_pile_num);

};

#endif


