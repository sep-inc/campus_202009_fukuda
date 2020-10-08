#ifndef DRAWER_H_
#define DRAWER_H_

/**
* @brief Drawerクラスのヘッダ
*/

#include <string>

/**
* @class Drawer
* @brief 描画クラス
*/
class Drawer {
public:
	static Drawer* Instance();

	/**
	* @brief 描画処理まとめ関数
	*/
	void DrawBuffer();

	/**
	* @brief 描画用文字列のクリア関数
	*/
	void ClearBuffer();

	/**
	* @brief 描画用文字列に情報をセットする関数
	*/
	void SetDrawMapString(std::string string);

	/**
	* @brief リザルト情報をセットする関数
	*/
	void SetResultString(std::string string);


private:
	/**
	* @brief ゲーム画面の描画関数
	*/
	void DrawMapString();

	/**
	* @brief ゲームのリザルト情報の描画関数
	*/
	void DrawResultString();

	
private:
	Drawer();
	~Drawer();

	static Drawer* p_instance;

private:
	std::string m_map_string;		//! ゲーム描画用文字列
	std::string m_result_string;	//! リザルト描画用文字列
};

#endif

