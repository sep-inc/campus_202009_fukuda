#ifndef SHOGI_GAME_H_
#define SHOGI_GAME_H_

/**
* @file ShogiGame.h
* @brief ShogiGameクラスのヘッダ
*/

#include "../Definition.h"
#include "../Player/Player1.h"
#include "../Player/Player2.h"
#include "../ShogiBoard/ShogiBoard.h"
#include "../Piece/PieceData.h"
#include <string>
/**
* @class ShogiGame
* @brief 将棋ゲーム本体のクラス
*/
class ShogiGame {
public:
	static ShogiGame* Instance();

	/**
	* @brief ShogiGameクラスの更新関数
	*/
	void Update();

	/**
	* @brief オブジェクト生成関数
	*/
	void CreateObjects();

	/**
	* @brief オブジェクト破棄関数
	*/
	void DeleteObjects();

	/**
	* @brief 終了判定を返す関数
	* Mainのループを終了させる処理で使用
	*
	* @return 終了フラグ
	*/
	bool IsGameFinish();

	/**
	* @brief 将棋盤を文字列に連結する関数
	*/
	void LinkShogiBoard();

	/**
	* @brief Drawerクラスに描画情報をセットする関数
	*/
	void SetShogiBoard();

	/**
	* @brief Drawerクラスにリザルト情報をセットする関数
	*/
	std::string SetResult(ObjectType type);

	/**
	* @brief 将棋盤初期化関数
	* 将棋盤をゲーム開始状態にする
	*/
	void InitShogiBoard();

	//! オブジェクトのポインタ変数群
	Player1* m_p_player1;
	Player2* m_p_player2;
	ShogiBoard* m_p_shogi_board;
	PieceData* m_p_pieces;

private:
	ShogiGame();
	~ShogiGame();

	static ShogiGame* p_instance;

private:
	Step m_step;			//! 現在のステップ
	int m_turn_counter;		//! ターン経過数
	bool m_is_game_finish;	//! ゲーム終了フラグ
	std::string m_shogi_board_string;	//! 描画用の将棋盤を連結した文字列

};

#endif

