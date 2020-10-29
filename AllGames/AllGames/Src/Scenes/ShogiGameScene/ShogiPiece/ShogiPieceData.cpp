#include "ShogiPieceData.h"
#include "ShogiPieces/ShogiGoldGeneralPiece1.h"
#include "ShogiPieces/ShogiGoldGeneralPiece2.h"
#include "ShogiPieces/ShogiKingPiece1.h"
#include "ShogiPieces/ShogiKingPiece2.h"
#include "ShogiPieces/ShogiKnightPiece1.h"
#include "ShogiPieces/ShogiKnightPiece2.h"
#include "ShogiPieces/ShogiPawnPiece1.h"
#include"ShogiPieces/ShogiPawnPiece2.h"

ShogiPieceData::ShogiPieceData() :
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

ShogiPieceData::~ShogiPieceData()
{
	DeletePieces();
}

void ShogiPieceData::CreatePieces()
{
	if (m_p_king1 == nullptr)
		m_p_king1 = new ShogiKingPiece1;
	if (m_p_knight1 == nullptr)
		m_p_knight1 = new ShogiKnightPiece1;
	if (m_p_pawn1 == nullptr)
		m_p_pawn1 = new ShogiPawnPiece1;
	if (m_p_gold_general1 == nullptr)
		m_p_gold_general1 = new ShogiGoldGeneralPiece1;

	if (m_p_king2 == nullptr)
		m_p_king2 = new ShogiKingPiece2;
	if (m_p_knight2 == nullptr)
		m_p_knight2 = new ShogiKnightPiece2;
	if (m_p_pawn2 == nullptr)
		m_p_pawn2 = new ShogiPawnPiece2;
	if (m_p_gold_general2 == nullptr)
		m_p_gold_general2 = new ShogiGoldGeneralPiece2;
}

void ShogiPieceData::DeletePieces()
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