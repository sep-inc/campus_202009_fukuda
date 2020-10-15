#ifndef GAME_MAP_H_
#define GAME_MAP_H_

/**
* @file GameMap.h
* @brief GameMapクラスのヘッダ
*/

#include "../Definition.h"
#include "../Draw/DrawerBase.h"

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

};

#endif