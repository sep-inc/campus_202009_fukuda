#ifndef GAME_STAGE_MANAGER_H_
#define GAME_STAGE_MANAGER_H_

/**
* @file GameStageManager.h
* @brief GameStageManagerクラスのヘッダ
*/


#include "Definition.h"


/**
* @class GameStageManager
* @brief 円盤の情報が入った3つの杭を管理するクラス
*/
class GameStageManager
{
public:
	GameStageManager();
	~GameStageManager();

	/**
	* @brief ステップ処理関数
	* ステップごとの処理を行う、この関数をメインで呼び出す
	*/
	void UpdateStep();

	/**
	* @brief 初期化関数
	*/
	void Init();

	/**
	* @brief プレイヤー入力情報セット関数
	*
	* @param source_num　移動元の杭番号
	* @param destination_pile　移動先の杭番号
	* @return 入力情報が正しくセットされればtrue
	*/
	bool SetInputPileNums(int source_num, int destination_num);


	/**
	* @brief ゲームクリア判定関数
	*
	* @return クリア条件が成立したらtrue
	*/
	bool IsClear();


private:
	//! 杭配列　左の要素：杭番号　右の要素 : 杭の要素番号
	DiskType m_piles[PILE_NUM][PILE_SIZE];	
	
	Step m_step;	//! 現在のステップ

};

#endif