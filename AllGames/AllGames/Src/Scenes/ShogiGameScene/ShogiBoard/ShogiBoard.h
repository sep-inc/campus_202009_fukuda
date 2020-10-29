#ifndef SHOGI_BOARD_H_
#define SHOGI_BOARD_H_

#include "../../../Utility/Utility.h"
#include "../ShogiGameDefinition.h"
#include "../ShogiPiece/ShogiPieceBase.h"

/**
* @class ShogiBoard
* @brief 将棋盤クラス
*/
class ShogiBoard {
public:
	ShogiBoard();
	~ShogiBoard();

	/**
	* @brief マスの中身を調べる関数
	* @param pos 調べたいマス目の座標
	* @return マスの中身
	*/
	ShogiPieceBase* GetContens(Vec2_Int pos);

	/**
	* @brief 駒をセットする関数
	* @param x セットするX座標
	* @param y セットするY座標
	* @param piece セットするクラスのポインタ
	*/
	void SetPiece(int x, int y, ShogiPieceBase* piece);

	/**
	* @brief 移動する駒をセットする関数
	* @param now_pos 移動させる駒の現在の座標
	* @param pos セットするマス目の座標
	*/
	void SetMovePiece(Vec2_Int now_pos, Vec2_Int move_pos);


private:
	//! 将棋盤配列
	ShogiPieceBase* m_shogi_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT];

};

#endif
