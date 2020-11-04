#ifndef TOWER_OF_HANOI_GAME_MAP_H_
#define TOWER_OF_HANOI_GAME_MAP_H_

#include "../TowerOfHanoiDefinition.h"

/**
* @class TowerOfHanoiGameMap
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

	/**
	* @brief 描画マップセット関数
	* 描画マップを描画クラスのSet関数でセットする
	*/
	void SetDrawMap();

	/**
	* @brief 描画時の外枠を作成する関数
	* ゲーム開始時に描画クラスの初期化用バッファにセットする
	*/
	void CreateDrawMapFrame();

	/**
	* @brief ゲームマップを描画用マップに変換する関数
	*/
	void ConvertDrawMap();

	/**
	* @brief 描画用マップをクリアする関数
	*/
	void ClearDrawMap();


private:
	//! 杭配列　左の要素：杭番号　右の要素 : 杭の要素番号
	TowerOfHanoiDiskType m_piles[TOWER_OF_HANOI_PILE_NUM][TOWER_OF_HANOI_PILE_SIZE];
	//! 描画用マップ
	TowerOfHanoiObjectType m_draw_map[TOWER_OF_HANOI_DRAW_WIDTH][TOWER_OF_HANOI_DRAW_HEIGHT];

};

#endif
