#ifndef PIECE_DATA_H_
#define PIECE_DATA_H_

#include "PieceBase.h"

class PieceData {
public:
	PieceData();
	~PieceData();

	/**
	* @brief 各駒クラス生成関数
	*/
	void CreatePieces();

	/**
	* @brief 各駒クラス破棄関数
	*/
	void DeletePieces();
	
	// 各駒クラスのポインタ変数群
	PieceBase* m_p_king1;
	PieceBase* m_p_knight1;
	PieceBase* m_p_pawn1;
	PieceBase* m_p_gold_general1;
	
	PieceBase* m_p_king2;
	PieceBase* m_p_knight2;
	PieceBase* m_p_pawn2;
	PieceBase* m_p_gold_general2;
};

#endif

