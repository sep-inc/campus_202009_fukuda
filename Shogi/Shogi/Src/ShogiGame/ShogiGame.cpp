#include "ShogiGame.h"
#include "../Draw/Drawer.h"
#include <sstream>

ShogiGame* ShogiGame::p_instance = 0;

ShogiGame::ShogiGame():
	m_p_player1(nullptr),
	m_p_player2(nullptr),
	m_p_shogi_board(nullptr),
	m_p_pieces(nullptr),
	m_step(Step::Initialize),
	m_turn_counter(1),
	m_is_game_finish(false)
{
}

ShogiGame::~ShogiGame()
{
}

ShogiGame* ShogiGame::Instance()
{
	if (p_instance == 0) {
		p_instance = new ShogiGame;
	}
	return p_instance;
}

void ShogiGame::Update()
{
	switch (m_step) {
	case Step::Initialize:
		// オブジェクトの生成
		CreateObjects();

		// 将棋盤の初期化
		InitShogiBoard();

		// 描画情報セット
		LinkShogiBoard();
		SetShogiBoard();

		m_step = Step::Update;
		break;
	case Step::Update:
	{
		PlayerBase* player = nullptr;
		// プレイヤー切り替え
		if (m_turn_counter % 2 == 1) {
			player = m_p_player1;
		}
		else {
			player = m_p_player2;
		}
		player->Update();
		// ターン経過数加算
		m_turn_counter++;

		/* 勝敗判定処理 */
		ObjectType take_piece = player->GetTakePiece();
		if (take_piece == ObjectType::King1 || take_piece == ObjectType::King2) {
			// ゲーム終了処理
			m_is_game_finish = true;
		}

		/* 描画情報のセット */
		LinkShogiBoard();
		SetShogiBoard();
		if (m_is_game_finish) {
			Drawer::Instance()->SetResultString(SetResult(take_piece));
			m_step = Step::End;
		}
		
		break;
	}
	case Step::End:
		// オブジェクトの破棄
		DeleteObjects();


		break;
	}
}

void ShogiGame::CreateObjects()
{
	if (m_p_player1 == nullptr)
		m_p_player1 = new Player1;
	if (m_p_player2 == nullptr)
		m_p_player2 = new Player2;
	if (m_p_shogi_board == nullptr)
		m_p_shogi_board = new ShogiBoard;
	if (m_p_pieces == nullptr)
		m_p_pieces = new PieceData;
}

void ShogiGame::DeleteObjects()
{
	if (m_p_player1 != nullptr) {
		delete m_p_player1;
		m_p_player1 = nullptr;
	}
	if (m_p_player2 != nullptr) {
		delete m_p_player2;
		m_p_player2 = nullptr;
	}
	if (m_p_shogi_board != nullptr) {
		delete m_p_shogi_board;
		m_p_shogi_board = nullptr;
	}
	if (m_p_pieces != nullptr) {
		delete m_p_pieces;
		m_p_pieces = nullptr;
	}
	
}

bool ShogiGame::IsGameFinish()
{
	if (m_is_game_finish == true) {
		return true;
	}
	return false;
}

void ShogiGame::LinkShogiBoard()
{
	/*
		char* draw[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT];
		char a[] = "aa";
		draw[0][2] = a;
	*/
	
	// 1行目
	m_shogi_board_string = "  A    B    C    D  \n";
	// 2行目
	m_shogi_board_string += " ┏ ━ ┳ ━ ┳ ━ ┳ ━ ┓\n";
	
	Vec2 pos;
	int line_counter = 1;	// 行数のカウント変数
	std::string separation = "┃";	// 区切り
	std::string space = " ";		// 空白
	std::string new_line = "\n";	// 改行
	std::string middle_line = " ┣ ━ ╋ ━ ╋ ━ ╋ ━ ┫\n";	// 中間行

	for (pos.m_y = 0; pos.m_y < SHOGI_BOARD_HEIGHT; pos.m_y++) {
		// 行カウントを文字列に追加する処理
		std::ostringstream line_num;
		line_num << line_counter;
		m_shogi_board_string += line_num.str();
		m_shogi_board_string += separation;

		for (pos.m_x = 0; pos.m_x < SHOGI_BOARD_WIDTH; pos.m_x++) {
			m_shogi_board_string += space;
			// マス目の中身が空でない場合
			if (m_p_shogi_board->GetContens(pos) != nullptr) {
				m_shogi_board_string += m_p_shogi_board->GetContens(pos)->GetDrawString();
			}
			// マス目の中身が空の場合
			else {
				m_shogi_board_string += "　";
			}

			m_shogi_board_string += separation;
		}
		// 行数更新
		line_counter++;
		m_shogi_board_string += new_line;
		// 最後の行ならループ終了（middle_lineを追加しないため）
		if (pos.m_y == SHOGI_BOARD_HEIGHT - 1) {
			break;
		}
		m_shogi_board_string += middle_line;
	}
	// 最後の行
	m_shogi_board_string += " ┗ ━ ┻ ━ ┻ ━ ┻ ━ ┛\n";

}

void ShogiGame::SetShogiBoard()
{
	Drawer::Instance()->SetDrawMapString(m_shogi_board_string);
}

std::string ShogiGame::SetResult(ObjectType type)
{
	std::string result;
	if (type == ObjectType::King1) {
		result = "Player2の勝利\n";
	}
	else if (type == ObjectType::King2) {
		result = "Player1の勝利\n";
	}
	return result.c_str();
}

void ShogiGame::InitShogiBoard()
{
	// 将棋盤の初期配置作成
	PieceBase* init_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {
		{nullptr,							m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_knight1},
		{m_p_pieces->m_p_king2,				m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_gold_general1},
		{m_p_pieces->m_p_gold_general2,		m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		m_p_pieces->m_p_king1},
		{m_p_pieces->m_p_knight2,			m_p_pieces->m_p_pawn2,		nullptr,	m_p_pieces->m_p_pawn1,		nullptr}
	};

	// 将棋盤へセット
	for (int x = 0; x < SHOGI_BOARD_WIDTH; x++) {
		for (int y = 0; y < SHOGI_BOARD_HEIGHT; y++) {
			m_p_shogi_board->SetPiece(x, y, init_board[x][y]);
		}
	}
}
