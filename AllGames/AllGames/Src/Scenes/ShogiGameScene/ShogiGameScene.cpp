#include "ShogiGameScene.h"
#include <sstream>

ShogiGameScene::ShogiGameScene() :
	m_p_player1(nullptr),
	m_p_player2(nullptr),
	m_p_shogi_board(nullptr),
	m_p_pieces(nullptr),
	m_step(ShogiSceneStep::STEP_INITIALIZE),
	m_turn_counter(1),
	m_result(ShogiResultType::NONE_RESULT)
{
	m_next_scene = SceneType::SELECT_GAME;
}

ShogiGameScene::~ShogiGameScene()
{
}

void ShogiGameScene::Update()
{
	switch (m_step) {
	case ShogiSceneStep::STEP_INITIALIZE:
		// オブジェクトの生成
		CreateObjects();

		// 初期化処理
		Init();
		InitShogiBoard();
		m_p_player1->Init(m_p_shogi_board);
		m_p_player2->Init(m_p_shogi_board);

		m_step = ShogiSceneStep::STEP_GAME_START;
		break;

	case ShogiSceneStep::STEP_GAME_START:
		// ゲームスタート処理
		if (GameStart()) {
			m_step = ShogiSceneStep::STEP_UPDATE;
		}
		break;

	case ShogiSceneStep::STEP_UPDATE:
	{
		ShogiPlayerBase* player = nullptr;
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
		if (JudgeResult(player->GetTakePiece())) {
			m_step = ShogiSceneStep::STEP_GAME_END;
		}

		break;
	}
	case ShogiSceneStep::STEP_GAME_END:
		/* ゲーム終了処理選択 */
		if (SelectGameEnd()) {
			m_step = ShogiSceneStep::STEP_END;
		}
		break;

	case ShogiSceneStep::STEP_END:
		if (m_is_scene_finish == true) {
			// オブジェクトの破棄
			DeleteObjects();
		}
		else {
			m_step = ShogiSceneStep::STEP_INITIALIZE;
		}

		break;
	}
}

void ShogiGameScene::Draw(DrawerBase* drawer_)
{
	// 描画用文字列への変換
	LinkShogiBoard();
	// 描画クラスへセット
	DrawShogiBoard(drawer_);
	// 勝敗情報のセット
	SetResult(drawer_);
}

SceneBase* ShogiGameScene::InstanceShogiGameScene()
{
	return static_cast<SceneBase*>(new ShogiGameScene);
}

void ShogiGameScene::CreateObjects()
{
	if (m_p_player1 == nullptr)
		m_p_player1 = new ShogiPlayer1;
	if (m_p_player2 == nullptr)
		m_p_player2 = new ShogiPlayer2;
	if (m_p_shogi_board == nullptr)
		m_p_shogi_board = new ShogiBoard;
	if (m_p_pieces == nullptr)
		m_p_pieces = new ShogiPieceData;
}

void ShogiGameScene::DeleteObjects()
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

void ShogiGameScene::Init()
{
	m_result = ShogiResultType::NONE_RESULT;
	m_turn_counter = 1;
}

void ShogiGameScene::LinkShogiBoard()
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

	Vec2_Int pos;
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

void ShogiGameScene::DrawShogiBoard(DrawerBase* drawer_)
{
	drawer_->SetDrawMapString(m_shogi_board_string);
}

void ShogiGameScene::SetResult(DrawerBase* drawer_)
{
	if (m_result == ShogiResultType::NONE_RESULT) {
		drawer_->SetResultString("\0");
	}
	else if (m_result == ShogiResultType::WIN_PLAYER1) {
		drawer_->SetResultString("Player1の勝利\n");
	}
	else if (m_result == ShogiResultType::WIN_PLAYER2) {
		drawer_->SetResultString("Player2の勝利\n");
	}
}

void ShogiGameScene::InitShogiBoard()
{
	// 将棋盤の初期配置作成
	ShogiPieceBase* init_board[SHOGI_BOARD_WIDTH][SHOGI_BOARD_HEIGHT] = {
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

bool ShogiGameScene::JudgeResult(ShogiGameObjectType take_piece_)
{
	// 王を取っていた場合勝敗情報をセットしtrueを返す
	if (take_piece_ == ShogiGameObjectType::KING1) {
		m_result = ShogiResultType::WIN_PLAYER2;
		return true;
	}
	else if (take_piece_ == ShogiGameObjectType::KING2) {
		m_result = ShogiResultType::WIN_PLAYER1;
		return true;
	}
	return false;
}
