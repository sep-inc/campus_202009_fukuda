#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* Input�N���X�̃w�b�_
*/


/**
* @class Input
* @brief ���͏����N���X
*/
class Input {
public:
	static Input* Instance();

	/**
	* @brief �������͊֐�
	* @return ���͂��ꂽ����
	*/
	char InputChar();

	/**
	* @brief �������͊֐�
	* @return ���͂��ꂽ����
	*/
	int InputNum();


private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif
