#include "Item.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>

Item::Item(int number_)
{
	m_param.m_pos.m_x = 0;
	m_param.m_pos.m_y = 0;
	m_param.m_type = PacMenObjectType::ITEM;

	// 引数でもらった整数を文字に変換
	std::ostringstream num_string;
	num_string << number_;
	
	std::string draw_string = " ";
	draw_string += num_string.str();
	strcpy_s(m_param.m_draw_string, DRAW_STRING_SIZE, draw_string.c_str());
	srand((unsigned)time(NULL));
}

Item::~Item()
{
}

void Item::Init(GameMap* map_)
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

void Item::Update()
{
	if (!m_is_delete)
		m_p_game_map->SetPos(m_param);
}

void Item::Draw(DrawerBase* drawer_)
{
	if(!m_is_delete)
		drawer_->SetDrawBuffer(m_param.m_pos, m_param.m_draw_string);
}

bool Item::CheckHit()
{
	if (m_is_delete == false) {
		if (m_p_game_map->GetContent(m_param.m_pos) == PacMenObjectType::PLAYER) {
			m_is_delete = true;
			return m_is_delete;
		}
	}
	return false;
}
