#ifndef SHOGI_BOARD_H_
#define SHOGI_BOARD_H_

/**
* @file ShogiBoard.h
* @brief ShogiBoardクラスのヘッダ
*/

#include "../Definition.h"
#include "../Piece/PieceBase.h"

/**
* @class ShogiBoard
* @brief 将棋盤クラス
*/
class ShogiBoard {
public:
	ShogiBoard();
	~ShogiBoard();

	/**
	* @brief 将棋盤初期化関数
	* 将棋盤に駒を初期位置に並べる
	*/
	void InitBoard();

	/**
	* @brief マスの中身を調べる関数
	* @param pos 調べたいマス目の座標
	* @return マスの中身
	*/
	PieceBase* GetContens(Vec2 pos);

	/**
	* @brief 駒をセットする関数
	* @param now_pos 移動させる駒の現在の座標
	* @param pos セットするマス目の座標
	*/
	void SetPiece(Vec2 now_pos, Vec2 move_pos);

	/**
	* @brief 王が存在しているかの判定関数
	* @param turn_num ターン経過数
	* @return 王が存在していたらtrue
	*/
	bool KingExists(int turn_num);


private:
	//! 将棋盤配列
	PieceBase* m_shogi_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT];

};

#endif

