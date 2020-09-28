#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Drawer.h"
#include "Input.h"

/**
* @file Global.h
* @brief グローバル変数群のヘッダ
*/


// ゲームオブジェクト
//! プレイヤークラスのインスタンス
extern Player g_player;
//! 相手クラスのインスタンス
extern Enemy g_enemy;
//! ゲームマップクラスのインスタンス
extern Map g_map;

// システム
//! 描画クラスのインスタンス
extern Drawer g_drawer;
//! インプットクラスのインスタンス
extern Input g_input;

#endif

