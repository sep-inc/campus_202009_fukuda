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
* @brief　マップの生成、管理を行うクラス
*/
class GameMap
{
public:
	GameMap();
	~GameMap();


	/**
	* @brief 初期化関数
	*/
	void Init();

	void Draw(DrawerBase* drawer_);


private:
	/**
	* @brief マップ生成関数
	*/
	void CreateMap();

	void AddMapParts(int parts_[][RUNGAME_MAP_PARTS_WIDTH], int height_, int add_num_);

	/**
	* @brief 0、1のマップをパラメータが入ったマップに変換する関数
	*/
	void ConvertGameMap();


private:
	//! 地面の配置のみを格納するマップ
	int m_ground_map[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_WIDTH];

	//! ゲームオブジェクトの情報を格納したマップ
	ObjectParam m_game_map[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_WIDTH];

	//! マップのパターン
	static int m_map_pattern1[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern2[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern3[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern4[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
};

#endif
