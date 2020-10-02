#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* Inputクラスのヘッダ
*/


/**
* @class Input
* @brief 入力処理クラス
*/
class Input {
public:
	static Input* Instance();

	/**
	* @brief 文字入力関数
	* @return 入力された文字
	*/
	char InputChar();

	/**
	* @brief 数字入力関数
	* @return 入力された数字
	*/
	int InputNum();


private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif
