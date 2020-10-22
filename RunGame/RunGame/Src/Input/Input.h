#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief Inputクラスのヘッダ
*/

#include "../Definition.h"

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
	* @return bool キーが押されたらtrue
	*/
	bool PressSpaceKey(KeyType key_type_);

	int GetKey();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif

