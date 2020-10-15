#ifndef GAME_MAP_H_
#define GAME_MAP_H_

/**
* @file GameMap.h
* @brief GameMapクラスのヘッダ
*/

#include "../Definition.h"
#include "../Draw/DrawerBase.h"
#include <vector>

/**
* @class GameMap
* @brief ゲームのマップ情報を管理するクラス
*/
class GameMap
{
public:
	GameMap();
	~GameMap();

	/**
	* @brief 初期化処理関数
	*/
	void Init();

	/**
	* @brief 描画処理関数
	* @param drawer_ 描画クラスのポインタ
	*/
	void Draw(DrawerBase* drawer_);

	/**
	* @brief マップに移動情報をセットする関数
	*/
	void SetMovePos(PacMenObjectParam param_, Vec2 move_pos_);

	/**
	* @brief プレイヤーの移動可能範囲を返す関数
	*/
	void GetCanPlayerMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_PLAYER_MOVE_LIST_SIZE]);


private:
	//! 初期化用マップの作成関数
	void CreateInitGameMap();

	/**
	* @brief ゲームマップを初期状態にする関数
	* ゲームの初期化時のみ使用する
	*/
	void ClearGameMap();

private:
	//! 初期化用マップ
	PacMenObjectParam m_init_game_map[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH];
	//! ゲームマップ
	PacMenObjectParam m_game_map[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH];
	//! 壁の配置データ
	static int m_init_wall[PACMEN_DRAW_BUFFER_HEIGHT][PACMEN_DRAW_BUFFER_WIDTH];
	// 空情報
	PacMenObjectParam m_empty;

};

#endif