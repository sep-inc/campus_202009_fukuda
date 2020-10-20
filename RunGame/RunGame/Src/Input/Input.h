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

	// 入力処理関数


private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif

