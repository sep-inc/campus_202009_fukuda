#ifndef PACMEN_CHARACTER_H_
#define PACMEN_CHARACTER_H_

#include "../PacMenGameObject.h"

/**
* @class CharacterBase
* @brief キャラクターの基底クラス
*/
class PacMenCharacterBase : public PacMenGameObject
{
public:
	PacMenCharacterBase();
	virtual ~PacMenCharacterBase();

	/**
	* @brief キャラクターの更新処理関数
	*/
	void Update()override;

	//! 移動座標選択処理
	virtual void SelectMovePos() = 0;

};

#endif
