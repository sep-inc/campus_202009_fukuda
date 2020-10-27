#ifndef INPUT_H_
#define INPUT_H_

/**
* @class Input
* @brief ���͏����N���X
*/
class Input
{
public:
	static Input* Instance();

	/**
	* @brief ���͂��󂯕t����֐�
	* 
	* @return int ���͂��ꂽ�L�[
	*/
	int GetKey();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif

