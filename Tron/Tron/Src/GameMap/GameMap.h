#ifndef GAME_MAP_H_
#define GAME_MAP_H_

/**
* @file GameMap.h
* @brief GameMapクラスのヘッダ
*/

#include "../Definition.h"

/**
* @class GameMap
* @brief ゲームのマップ情報を管理するクラス
*/
class GameMap
{
public:
	GameMap();
	~GameMap();

	//! 動ける場所を返す関数
	void GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE]);

	//! 動いた先で、まだ動けるかの判定関数
	bool SetMovePos(Vec2 move_pos_, CharacterParam chara_);

	/**
	* @brief ゲームマップを初期状態にする関数
	* ゲームの初期化時のみ使用する
	*/
	void ClearGameMap();

	//! 初期化用マップの作成関数
	void CreateInitGameMap();

	/**
	* @brief 引数で指定された座標の描画文字を返す
	*/
	char* GetDrawString(Vec2 pos_);

private:
	//! 初期化用のゲームマップ
	CharacterParam m_init_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];

	//! ゲームマップ
	CharacterParam m_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];
};

#endif

