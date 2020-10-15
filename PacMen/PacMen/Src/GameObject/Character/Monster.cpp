#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

Monster::Monster()
{
	m_param.m_pos.m_x = 0;
	m_param.m_pos.m_y = 0;
	m_param.m_type = PacMenObjectType::MONSTER;
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, "@ ");
	srand((unsigned)time(NULL));
}

Monster::~Monster()
{
}

void Monster::Init(GameMap* map_)
{
	m_p_game_map = map_;
	// 生成可能場所の取得
	Vec2 can_create_array[CAN_CREATE_POS_NUM] = {};
	int array_index = m_p_game_map->GetCanCreatePos(can_create_array);
	// 生成場所の選択
	int select_index = rand() % array_index;
	m_param.m_pos = can_create_array[select_index];
	// 生成場所をセット
	m_p_game_map->SetPos(m_param);
}

void Monster::SelectMovePos()
{
	Vec2 can_move_array[CAN_CHARACTER_MOVE_POS_LIST] = {};	// 移動可能範囲
	// 移動可能範囲の取得
	int array_index = m_p_game_map->GetCanMonsterMovePos(m_param.m_pos, can_move_array);
	if (array_index == 0) {
		return;
	}

	int select_index = rand() % array_index;
	Vec2 move_pos = can_move_array[select_index];
	m_p_game_map->SetMovePos(m_param, move_pos);
	m_param.m_pos = move_pos;
}
