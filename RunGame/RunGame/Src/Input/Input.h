#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief Inputクラスのヘッダ
*/

/**
* @class Input
* @brief 入力処理クラス
*/
class Input
{
public:
	static Input* Instance();

	/**
	* @brief スペースキー入力関数
	* @return int 入力されたキー 何も入力されていなかったら-1
	*/
	int PressSpaceKey();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif

