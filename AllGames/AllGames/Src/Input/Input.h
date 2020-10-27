#ifndef INPUT_H_
#define INPUT_H_

/**
* @class Input
* @brief 入力処理クラス
*/
class Input
{
public:
	static Input* Instance();

	/**
	* @brief 入力を受け付ける関数
	* 
	* @return int 入力されたキー
	*/
	int GetKey();

private:
	Input();
	~Input();

	static Input* p_instance;
};

#endif

