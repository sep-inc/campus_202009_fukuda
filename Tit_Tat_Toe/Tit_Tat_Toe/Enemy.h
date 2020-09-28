#ifndef ENEMY_H_
#define ENEMY_H_

#include "Definition.h"

/**
* @file Enemy.h
* @brief Enemyクラスのヘッダ
*/


/**
* @class Enemy
* @brief Enemy関係の処理を行うクラス
*/
class Enemy
{
public:
	Enemy();
	~Enemy();

	/**
	* Enemyクラス初期化関数
	* Step_Initialize処理で呼び出す
	*/
	void Init();

	/**
	* ステップ更新関数
	* ステップを更新し、各ステップごとの処理を呼び出す
	*/
	void Update();

	/**
	* 入力座標選択関数
	* Mapクラスから空きマスの情報をもらい、
	* その中からランダムで入力する場所を選択する
	*
	* @return 選択した座標
	*/
	Vec2 SelectInputPos();

private:
	//! 現在の処理ステップ
	Step m_step;
	//! 描画タイプ
	DrawType m_draw_type;
};

#endif

