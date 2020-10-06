#ifndef DRAWER_BASE_H_
#define DRAWER_BASE_H_

/**
* @file DrawerBase.h
* @brief DrawerBaseクラスのヘッダ
*/


#include <string>

/**
* @class DrawerBase
* Drawerクラスの基底クラス
*/
class DrawerBase
{
public:
	DrawerBase();
	virtual ~DrawerBase();

	void Run();

	void Print();

	virtual void ClearBuffer() = 0;

	/*
		下記関数は純粋仮想だと引数に本来入るべき描画タイプの
		情報が今のままだと入れられないため、いったん派生先でそれぞれ作る
	*/
	// virtual void SetDrawBuffer() = 0;
	// virtual void SetBlankBuffer() = 0;
	// virtual void SetResult() = 0;

protected:
	std::string m_draw_string;

};

#endif