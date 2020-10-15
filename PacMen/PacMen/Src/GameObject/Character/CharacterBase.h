#ifndef CHARACTER_BASE_H_
#define CHARACTER_BASE_H_

/**
* @file CharacterBase.h
* @brief CharacterBaseクラスのヘッダ
*/

#include "../PacMenGameObject.h"

/**
* @class CharacterBase
* @brief キャラクターの基底クラス
*/
class CharacterBase : public PacMenGameObject
{
public:
	CharacterBase();
	virtual ~CharacterBase();

	void Update()override;

	//! 移動座標選択処理
	virtual Vec2 SelectMovePos() = 0;

};

#endif

