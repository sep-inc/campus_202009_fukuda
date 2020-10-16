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

	/**
	* @brief キャラクターの更新処理関数
	*/
	void Update()override;

	//! 移動座標選択処理
	virtual void SelectMovePos() = 0;

};

#endif

