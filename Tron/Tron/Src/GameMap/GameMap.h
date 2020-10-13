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
	* @brief 描画処理関数
	* @param drawer_ 描画クラスのポインタ
	*/
	void Draw(DrawerBase* drawer_);

	void InitDraw(DrawerBase* drawer_);

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


private:
	//! 初期化用のゲームマップ
	CharacterParam m_init_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];

	//! ゲームマップ
	CharacterParam m_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];
};

#endif

