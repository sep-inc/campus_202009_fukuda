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
	* @brief 指定フレームのみ行う更新処理関数
	* @param is_count_max_ カウントが指定フレームに達しているか
	*/
	void FixedUpdate(bool is_count_max_);

	/**
	* @brief 初期化関数
	*/
	void Init();

	void Draw(DrawerBase* drawer_);

	/**
	* @brief Player情報をセットする関数
	*/
	void SetPlayer(Vec2 player_pos, ObjectParam player_, ObjectParam player_head_);

	/**
	* @brief 地面に当たっているかを返す
	*/
	bool IsHitGround(Vec2 pos_);

	/**
	* @brief 次の壁に当たっているか
	*/
	bool IsHitWall(Vec2 pos_);


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

	/**
	* @brief カメラの更新関数
	*/
	void UpdateCamera();

	/**
	* @brief マップをクリアする関数
	*/
	void ClearMap();


private:
	//! 地面の配置のみを格納するマップ
	int m_ground_map[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_WIDTH];

	//! ゲームオブジェクトの情報を格納したマップ
	ObjectParam m_game_map[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_WIDTH];

	//! ゲームオブジェクトの情報を格納したマップ
	ObjectParam m_init_game_map[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_WIDTH];

	//! マップのパターン
	static int m_map_pattern1[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern2[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern3[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];
	static int m_map_pattern4[RUNGAME_MAP_HEIGHT][RUNGAME_MAP_PARTS_WIDTH];

	Vec2 m_camera_pos;
	int m_camera_speed;
};

#endif
