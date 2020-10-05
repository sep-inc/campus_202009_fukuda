#ifndef PIECE_DATA_H_
#define PIECE_DATA_H_

#include "PieceBase.h"

class PieceData {
public:
	PieceData();
	~PieceData();

	void CreatePieces();

	void DeletePieces();
	
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

