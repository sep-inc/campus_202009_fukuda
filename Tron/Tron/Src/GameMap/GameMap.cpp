#include "GameMap.h"
#include <cstring>

GameMap::GameMap():
	m_init_game_map{},
	m_game_map{}
{
}

GameMap::~GameMap()
{
}

void GameMap::GetCanMovePos(Vec2 now_pos_, Vec2 move_list_[CAN_MOVE_LIST_SIZE])
{
	// �v�f���J�E���g�p
	int tmp = 0;
	// 1�}�X��̌���
	if (m_game_map[now_pos_.m_y - 1][now_pos_.m_x].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y - 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1�}�X���̌���
	if (m_game_map[now_pos_.m_y + 1][now_pos_.m_x].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x,now_pos_.m_y + 1 };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1�}�X���̌���
	if (m_game_map[now_pos_.m_y][now_pos_.m_x - 1].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x - 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
	// 1�}�X�E�̌���
	if (m_game_map[now_pos_.m_y][now_pos_.m_x + 1].m_type == ObjectType::TYPE_EMPTY) {
		Vec2 pos = { now_pos_.m_x + 1,now_pos_.m_y };
		move_list_[tmp] = pos;
		tmp++;
	}
}

bool GameMap::SetMovePos(Vec2 move_pos_, CharacterParam chara_)
{
	m_game_map[move_pos_.m_y][move_pos_.m_x] = chara_;
	// �Z�b�g�������W����4�����𒲂ׂāA��̏ꏊ���Ȃ����false
	if (m_game_map[move_pos_.m_y - 1][move_pos_.m_x].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y + 1][move_pos_.m_x].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x - 1].m_type == ObjectType::TYPE_EMPTY ||
		m_game_map[move_pos_.m_y][move_pos_.m_x + 1].m_type == ObjectType::TYPE_EMPTY) 
	{
		return false;
	}
	return true;
}

void GameMap::ClearGameMap()
{
	memcpy(m_game_map, m_init_game_map, sizeof(m_init_game_map));
}

void GameMap::CreateInitGameMap()
{
	// �Ǐ��̒�`
	CharacterParam frame;
	frame.m_type = ObjectType::FRAME;
	strcpy_s(frame.m_draw_string, DRAW_STRING_SIZE, "��");

	// �ǂ̃Z�b�g
	for (int i = 0; i < TRON_DRAW_BUFFER_HEIGHT; i++) {
		m_init_game_map[i][0] = frame;
		m_init_game_map[i][TRON_DRAW_BUFFER_WIDTH - 1] = frame;
	}

	for (int i = 0; i < TRON_DRAW_BUFFER_WIDTH; i++) {
		m_init_game_map[0][i] = frame;
		m_init_game_map[TRON_DRAW_BUFFER_HEIGHT - 1][i] = frame;
	}

	// �v���C���[�̏����ʒu�Z�b�g
	CharacterParam player;
	player.m_type = ObjectType::PLAYER;
	strcpy_s(player.m_draw_string, DRAW_STRING_SIZE, "��");
	m_init_game_map[INIT_PLAYER_POS_Y][INIT_PLAYER_POS_X] = player;

	// �G�l�~�[�̏����ʒu�Z�b�g
	CharacterParam enemy;
	enemy.m_type = ObjectType::ENEMY;
	strcpy_s(enemy.m_draw_string, DRAW_STRING_SIZE, "��");
	m_init_game_map[INIT_ENEMY_POS_Y][INIT_ENEMY_POS_X] = enemy;
}

char* GameMap::GetDrawString(Vec2 pos_)
{
	return m_game_map[pos_.m_y][pos_.m_x].m_draw_string;
}
