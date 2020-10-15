#ifndef WALL_H_
#define WALL_H_

/**
* @file Wall.h
* @brief Wallクラスのヘッダ
*/

#include "PacMenGameObject.h"

/**
* @class Wall
* @brief 壁クラス
*/
class Wall : public PacMenGameObject
{
public:
	Wall();
	~Wall();

	void Init()override;

};

#endif

