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

	/**
	* @brief 移動可能範囲を返す関数
	* 指定された位置から移動可能な場所をリスト化し、もらった配列の中に格納する
	*
	* @param now_pos_ 現在地
	* @param move_list_ 移動可能範囲リストの配列
	*/
	void GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE]);

	/**
	* @brief 移動場所をセット、その場所から他の位置に移動が可能かを判定する関数
	* @param move_pos_ 移動先の座標
	* @param chara_ セットするキャラクターの情報
	* @return bool 移動可能な場所がなければtrueを返す
	*/
	bool SetMovePos(Vec2 move_pos_, CharacterParam chara_);


private:
	//! 初期化用マップの作成関数
	void CreateInitGameMap();

	/**
	* @brief ゲームマップを初期状態にする関数
	* ゲームの初期化時のみ使用する
	*/
	void ClearGameMap();


private:
	//! 初期化用のゲームマップ
	CharacterParam m_init_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];

	//! ゲームマップ
	CharacterParam m_game_map[TRON_DRAW_BUFFER_HEIGHT][TRON_DRAW_BUFFER_WIDTH];
};

#endif

