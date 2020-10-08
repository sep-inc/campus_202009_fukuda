#ifndef DRAWER_H_
#define DRAWER_H_

/**
* @brief Drawer�N���X�̃w�b�_
*/

#include <string>

/**
* @class Drawer
* @brief �`��N���X
*/
class Drawer {
public:
	static Drawer* Instance();

	/**
	* @brief �`�揈���܂Ƃߊ֐�
	*/
	void DrawBuffer();

	/**
	* @brief �`��p������̃N���A�֐�
	*/
	void ClearBuffer();

	/**
	* @brief �`��p������ɏ����Z�b�g����֐�
	*/
	void SetDrawMapString(std::string string);

	/**
	* @brief ���U���g�����Z�b�g����֐�
	*/
	void SetResultString(std::string string);


private:
	/**
	* @brief �Q�[����ʂ̕`��֐�
	*/
	void DrawMapString();

	/**
	* @brief �Q�[���̃��U���g���̕`��֐�
	*/
	void DrawResultString();

	
private:
	Drawer();
	~Drawer();

	static Drawer* p_instance;

private:
	std::string m_map_string;		//! �Q�[���`��p������
	std::string m_result_string;	//! ���U���g�`��p������
};

#endif

