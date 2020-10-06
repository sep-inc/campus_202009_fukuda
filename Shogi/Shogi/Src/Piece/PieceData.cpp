#include "PieceData.h"
#include "KingPiece.h"
#include "KnightPiece.h"
#include "PawnPiece.h"
#include "GoldGeneralPiece.h"

PieceData::PieceData():
	m_p_king1(nullptr),
	m_p_knight1(nullptr),
	m_p_pawn1(nullptr),
	m_p_gold_general1(nullptr),
	m_p_king2(nullptr),
	m_p_knight2(nullptr),
	m_p_pawn2(nullptr),
	m_p_gold_general2(nullptr)
{
	CreatePieces();
}

PieceData::~PieceData()
{
	DeletePieces();
}

void PieceData::CreatePieces()
{
	if (m_p_king1 == nullptr)
		m_p_king1 = new KingPiece;
	if (m_p_knight1 == nullptr)
		m_p_knight1 = new KnightPiece;
	if (m_p_pawn1 == nullptr)
		m_p_pawn1 = new PawnPiece;
	if (m_p_gold_general1 == nullptr)
		m_p_gold_general1 = new GoldGeneralPiece;

	if (m_p_king2 == nullptr)
		m_p_king2 = new KingPiece;
	if (m_p_knight2 == nullptr)
		m_p_knight2 = new KnightPiece;
	if (m_p_pawn2 == nullptr)
		m_p_pawn2 = new PawnPiece;
	if (m_p_gold_general2 == nullptr)
		m_p_gold_general2 = new GoldGeneralPiece;
}

void PieceData::DeletePieces()
{
	if (m_p_king1 != nullptr) {
		delete m_p_king1;
		m_p_king1 = nullptr;
	}
	if (m_p_knight1 != nullptr) {
		delete m_p_knight1;
		m_p_knight1 = nullptr;
	}
	if (m_p_gold_general1 != nullptr) {
		delete m_p_gold_general1;
		m_p_gold_general1 = nullptr;
	}
	if (m_p_pawn1 != nullptr) {
		delete m_p_pawn1;
		m_p_pawn1 = nullptr;
	}

	if (m_p_king2 != nullptr) {
		delete m_p_king2;
		m_p_king2 = nullptr;
	}
	if (m_p_knight2 != nullptr) {
		delete m_p_knight2;
		m_p_knight2 = nullptr;
	}
	if (m_p_gold_general2 != nullptr) {
		delete m_p_gold_general2;
		m_p_gold_general2 = nullptr;
	}
	if (m_p_pawn2 != nullptr) {
		delete m_p_pawn2;
		m_p_pawn2 = nullptr;
	}
}
