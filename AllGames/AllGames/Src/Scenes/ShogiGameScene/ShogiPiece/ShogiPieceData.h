#ifndef SHOGI_PIECE_DATA_H_
#define SHOGI_PIECE_DATA_H_

#include "ShogiPieceBase.h"

class ShogiPieceData {
public:
	ShogiPieceData();
	~ShogiPieceData();

	/**
	* @brief 各駒クラス生成関数
	*/
	void CreatePieces();

	/**
	* @brief 各駒クラス破棄関数
	*/
	void DeletePieces();

	// 各駒クラスのポインタ変数群
	ShogiPieceBase* m_p_king1;
	ShogiPieceBase* m_p_knight1;
	ShogiPieceBase* m_p_pawn1;
	ShogiPieceBase* m_p_gold_general1;

	ShogiPieceBase* m_p_king2;
	ShogiPieceBase* m_p_knight2;
	ShogiPieceBase* m_p_pawn2;
	ShogiPieceBase* m_p_gold_general2;
};

#endif

