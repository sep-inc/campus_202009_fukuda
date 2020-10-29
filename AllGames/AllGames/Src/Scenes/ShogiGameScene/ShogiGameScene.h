#ifndef SHOGIGAME_SCENE_H_
#define SHOGIGAME_SCENE_H_

#include "../SceneBase.h"
#include "ShogiPlayer/ShogiPlayer1.h"
#include "ShogiPlayer/ShogiPlayer2.h"
#include "ShogiBoard/ShogiBoard.h"
#include "ShogiPiece/ShogiPieceData.h"
#include <string>

/**
* @class ShogiGame
* @brief 将棋ゲーム本体のクラス
*/
class ShogiGameScene : public SceneBase
{
public:
	ShogiGameScene();
	~ShogiGameScene();

	/**
	* @brief ShogiGameクラスの更新関数
	*/
	void Update()override;

	/**
	* @brief 描画情報を作成、セットする関数
	* MainでUpdate後に呼び出す
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief インスタンス生成関数
	*/
	static SceneBase* InstanceShogiGameScene();


private:
	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DeleteObjects();

	/**
	* @brief シーン初期化関数
	*/
	void Init();

	/**
	* @brief 将棋盤を文字列に連結する関数
	*/
	void LinkShogiBoard();

	/**
	* @brief Drawerクラスに描画情報をセットする関数
	*/
	void DrawShogiBoard(DrawerBase* drawer_);

	/**
	* @brief Drawerクラスにリザルト情報をセットする関数
	*/
	void SetResult(DrawerBase* drawer_);

	/**
	* @brief 将棋盤初期化関数
	* 将棋盤をゲーム開始状態にする
	*/
	void InitShogiBoard();

	/**
	* @brief 勝敗判定関数
	* 
	* @param take_piece 取った駒のタイプ
	* @return bool 取った駒が王ならtrue
	*/
	bool JudgeResult(ShogiGameObjectType take_piece_);

	//! オブジェクトのポインタ変数群
	ShogiPlayer1* m_p_player1;
	ShogiPlayer2* m_p_player2;
	ShogiBoard* m_p_shogi_board;
	ShogiPieceData* m_p_pieces;


private:
	enum class ShogiSceneStep : int {
		STEP_INITIALIZE,	//! 初期化ステップ
		STEP_GAME_START,	//! ゲームの開始ステップ
		STEP_UPDATE,		//! 更新ステップ
		STEP_GAME_END,		//! ゲームの終了ステップ
		STEP_END			//! 終了ステップ
	};

	ShogiSceneStep m_step;			//! 現在のステップ
	int m_turn_counter;		//! ターン経過数
	ShogiResultType m_result;
	std::string m_shogi_board_string;	//! 描画用の将棋盤を連結した文字列

};

#endif
