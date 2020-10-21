#ifndef GAME_CAMERA_H_
#define GAME_CAMERA_H_

/**
* @file GameCamera.h
* @brief GameCameraクラスのヘッダ
*/

#include "../Definition.h"
#include "../Player/Player.h"
#include "../GameMap/GameMap.h"
#include "../Draw/DrawerBase.h"

/**
* @class GameCamera
* @brief カメラ処理クラス
*/
class GameCamera
{
public:
	GameCamera();
	~GameCamera();

	/**
	* @brief 更新処理関数（指定フレーム）
	* @param is_count_max_ カウントが指定フレームに達しているか
	*/
	void FixedUpdate(bool is_count_max_);

	/**
	* @brief 初期化関数
	*/
	void Init(Player* player_, GameMap* map_);

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_);

private:
	/**
	* @brief 移動関数
	*/
	void Move();


private:
	Vec2 m_pos;		//! 自身の座標
	int m_speed;	//! 移動速度

	//! 参照用
	Player* m_p_player;
	GameMap* m_p_map;
};


#endif

