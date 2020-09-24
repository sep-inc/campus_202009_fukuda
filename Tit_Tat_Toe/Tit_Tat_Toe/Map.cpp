#include "Map.h"
#include "Global.h"
#include <cstdlib>



Map::Map():
	m_step(Step::Step_Initialize),
	m_game_map{},
	m_empty_pos{},
	m_empty_array_size(0),
	m_turn_num(0)
{
}


Map::~Map()
{
}

void Map::Init()
{
	// ゲームマップ配列をTypeNoneで初期化する
	for (int x = 0; x < GAME_MAP_WIDTH; x++) {
		for (int y = 0; y < GAME_MAP_HEIGHT; y++) {
			m_game_map[x][y] = DrawType::TypeNone;
		}
	}
}

void Map::Update()
{
	switch (m_step) {
	case Step::Step_Initialize:
		// 初期化
		Init();
		// ステップの更新
		m_step = Step::Step_Run;
		break;
	case Step::Step_Run:
		// 描画クラスにゲームマップの情報をセットする
		g_drawer.SetGameMap(m_game_map);
		// ターン経過数を進める
		m_turn_num++;
		// 空のマス目リストのクリア
		ClearEmptyPos();
		// 勝敗結果が確定した場合
		if (m_result != MatchResult::None) {
			// 勝敗結果を描画クラスにセットする
			g_drawer.SetResult(m_result);
			// ステップをStep_Endに更新する
			m_step = Step::Step_End;
		}
		break;
	case Step::Step_End:
		// プログラムを終了する
		exit(0);
		break;
	}
}

bool Map::IsEmpty(Vec2 pos)
{
	// 引数でもらった座標が空かどうか
	if (m_game_map[pos.m_x][pos.m_y] == DrawType::TypeNone) {
		return true;
	}
	return false;
}

void Map::SetPos(Vec2 pos, DrawType type)
{
	m_game_map[pos.m_x][pos.m_y] = type;
}

void Map::SetResult(MatchResult result)
{
	m_result = result;
}

int8_t Map::GetEmptyArraySize()
{
	// 空のマス目リストの情報を更新
	UpdateEnptyPos();
	// 更新した空のマス目リストの要素数を返す
	return m_empty_array_size;
}

Vec2 Map::GetSelectEnptyPos(int num)
{
	// 引数でもらった要素番号の空のマス目リストに入った座標を返す
	return m_empty_pos[num];
}

bool Map::IsFinishGame()
{
	// 勝敗結果が確定した場合
	if (m_result != MatchResult::None) {
		return true;
	}
	// ターン経過数が最大ターン数に達した場合
	if (m_turn_num == MAX_TURN_NUM) {
		return true;
	}
	return false;
}

MatchResult Map::JudgeResult()
{
	int have_both_types_line = 0;	// 1つの列に〇と✕両方のタイプを持つ列の総数
	Vec2 search_pos = {};			// 検索する列の座標
	DrawType square1 = DrawType::TypeNone;	// ジャッジする列の1マス目
	DrawType square2 = DrawType::TypeNone;	// ジャッジする列の2マス目
	DrawType square3 = DrawType::TypeNone;	// ジャッジする列の3マス目

	// 縦列のジャッジ処理
	while (search_pos.m_x < GAME_MAP_WIDTH) {
		search_pos.m_y = 0;
		square1 = DrawType::TypeNone;
		square2 = DrawType::TypeNone;
		square3 = DrawType::TypeNone;

		// 1マス目の中身を保存
		square1 = m_game_map[search_pos.m_x][search_pos.m_y];
		search_pos.m_y++;
		// 2マス目の中身を保存
		square2 = m_game_map[search_pos.m_x][search_pos.m_y];
		// 1、2マス目が空なら次列のジャッジへ進む
		if (square1 == DrawType::TypeNone && square2 == DrawType::TypeNone) {
			search_pos.m_x++;
			continue;
		}
		search_pos.m_y++;
		// 3マス目の中身を保存
		square3 = m_game_map[search_pos.m_x][search_pos.m_y];
		// マスのいずれか2つが空なら次列のジャッジへ進む
		if (square3 == DrawType::TypeNone && square1 == DrawType::TypeNone
			|| square3 == DrawType::TypeNone && square2 == DrawType::TypeNone) {
			search_pos.m_x++;
			continue;
		}
		// 全てのマスに中身がある場合
		if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone && square3 != DrawType::TypeNone) {
			// 全てのマスの中身が一致している場合勝敗を返す
			if (square1 == square2 && square2 == square3) {
				if (square3 == DrawType::Player) {
					return MatchResult::Win;
				}
				else if (square3 == DrawType::Enemy) {
					return MatchResult::Lose;
				}
			}
			// どれか中身が違えば次列のジャッジへ進む
			else {
				search_pos.m_x++;
				have_both_types_line++;
				continue;
			}
		}
		// いずれか2つのマスに中身があり、かつ中身の種類が違うため、次列へ進む
		if (square1 != square2 && square1 != square3 && square2 != square3) {
			have_both_types_line++;
			search_pos.m_x++;
			continue;
		}
		// いずれか2つのマスに中身があり、かつその2つの中身が同じ場合
		search_pos.m_x++;
	}

	// 検索用の座標を初期化
	search_pos.m_x = 0;
	search_pos.m_y = 0;

	// 横列のジャッジ処理
	while (search_pos.m_y < GAME_MAP_HEIGHT) {
		search_pos.m_x = 0;
		square1 = DrawType::TypeNone;
		square2 = DrawType::TypeNone;
		square3 = DrawType::TypeNone;

		// 1マス目の中身を保存
		square1 = m_game_map[search_pos.m_x][search_pos.m_y];
		search_pos.m_x++;
		// 2マス目の中身を保存
		square2 = m_game_map[search_pos.m_x][search_pos.m_y];
		// 1、2マス目が空なら次列のジャッジへ進む
		if (square1 == DrawType::TypeNone && square2 == DrawType::TypeNone) {
			search_pos.m_y++;
			continue;
		}
		search_pos.m_x++;
		// 3マス目の中身を保存
		square3 = m_game_map[search_pos.m_x][search_pos.m_y];
		// マスのいずれか2つが空なら次列のジャッジへ進む
		if (square3 == DrawType::TypeNone && square1 == DrawType::TypeNone
			|| square3 == DrawType::TypeNone && square2 == DrawType::TypeNone) {
			search_pos.m_y++;
			continue;
		}
		// 全てのマスに中身がある場合
		if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone && square3 != DrawType::TypeNone) {
			// 全てのマスの中身が一致している場合勝敗を返す
			if (square1 == square2 && square2 == square3) {
				if (square3 == DrawType::Player) {
					return MatchResult::Win;
				}
				else if (square3 == DrawType::Enemy) {
					return MatchResult::Lose;
				}
			}
			// どれか中身が違えば次列のジャッジへ進む
			else {
				search_pos.m_y++;
				have_both_types_line++;
				continue;
			}
		}
		// いずれか2つのマスに中身があり、かつ中身の種類が違うため、次列へ進む
		if (square1 != square2 && square1 != square3 && square2 != square3) {
			have_both_types_line++;
			search_pos.m_y++;
			continue;
		}
		// いずれか2つのマスに中身があり、かつその2つの中身が同じ場合
		search_pos.m_y++;
	}

	
	// マスの中身を初期化
	square1 = DrawType::TypeNone;
	square2 = DrawType::TypeNone;
	square3 = DrawType::TypeNone;

	// 斜めの列のジャッジ
	square1 = m_game_map[0][0];
	square2 = m_game_map[1][1];
	square3 = m_game_map[2][2];
	// いずれか2つのマスが空でない場合
	if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone
		|| square3 != DrawType::TypeNone && square1 != DrawType::TypeNone
		|| square3 != DrawType::TypeNone && square2 != DrawType::TypeNone) {
		// 全てのマスに中身がある場合
		if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone && square3 != DrawType::TypeNone) {
			// 全てのマスの中身が一致している場合勝敗を返す
			if (square1 == square2 && square2 == square3) {
				if (square3 == DrawType::Player) {
					return MatchResult::Win;
				}
				else if (square3 == DrawType::Enemy) {
					return MatchResult::Lose;
				}
			}
			// どれか中身が違えば次列のジャッジへ進む
			else {
				have_both_types_line++;
			}
		}
		// いずれか2つのマスに中身があり、かつ中身の種類が違うため、次列へ進む
		else if (square1 != square2 && square1 != square3 && square2 != square3) {
			have_both_types_line++;
		}
	}


	// マスの中身を初期化
	square1 = DrawType::TypeNone;
	square2 = DrawType::TypeNone;
	square3 = DrawType::TypeNone;

	// もう1つの斜めの列のジャッジ
	square1 = m_game_map[0][2];
	square2 = m_game_map[1][1];
	square3 = m_game_map[2][0];
	// いずれか2つのマスが空でない場合
	if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone
		|| square3 != DrawType::TypeNone && square1 != DrawType::TypeNone
		|| square3 != DrawType::TypeNone && square2 != DrawType::TypeNone) {
		// 全てのマスに中身がある場合
		if (square1 != DrawType::TypeNone && square2 != DrawType::TypeNone && square3 != DrawType::TypeNone) {
			// 全てのマスの中身が一致している場合勝敗を返す
			if (square1 == square2 && square2 == square3) {
				if (square3 == DrawType::Player) {
					return MatchResult::Win;
				}
				else if (square3 == DrawType::Enemy) {
					return MatchResult::Lose;
				}
			}
			// どれか中身が違えば次列のジャッジへ進む
			else {
				have_both_types_line++;
			}
		}
		// いずれか2つのマスに中身があり、かつ中身の種類が違うため、次列へ進む
		else if (square1 != square2 && square1 != square3 && square2 != square3) {
			have_both_types_line++;
		}
	}

	// 全通りに〇と✕が1つずつ存在した場合
	if (have_both_types_line == GAME_MAP_WIDTH + GAME_MAP_HEIGHT + 2) {
		return MatchResult::Draw;
	}

	return MatchResult::None;
}

void Map::UpdateEnptyPos()
{
	// ゲームマップ配列から空のマス目を検索
	for (int x = 0; x < GAME_MAP_WIDTH; x++) {
		for (int y = 0; y < GAME_MAP_HEIGHT; y++) {
			// 空のマス目があればリストに追加
			if (m_game_map[x][y] == DrawType::TypeNone) {
				m_empty_pos[m_empty_array_size].m_x = x;
				m_empty_pos[m_empty_array_size].m_y = y;
				// リストの要素数を数える
				m_empty_array_size++;
			}
		}
	}
}

void Map::ClearEmptyPos()
{
	// 空のマス目リストを0クリア
	for (int i = 0; i < m_empty_array_size; i++) {
		m_empty_pos[i].m_x = 0;
		m_empty_pos[i].m_y = 0;
	}
	// リストの要素数をクリア
	m_empty_array_size = 0;
}
