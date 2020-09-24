#ifndef DRAWER_H_
#define DRAWER_H_

#include "Definition.h"

/**
* @file Drawer.h
* @brief Drawer�N���X�̃w�b�_
*/


/**
* @brief �`�揈��������N���X
*/
class Drawer {
public:
	Drawer();
	~Drawer();

	/**
	* Drawer�N���X�������֐�
	* �Q�[�����[�v�̑O��1�x�����Ăяo��
	*/
	void Init();

	/**
	* Drawer�N���X�̏����܂Ƃߊ֐�
	* �����[�v�񂵂����������܂Ƃ߂邽�߂̊֐�
	*/
	void Run();


public:
	// �Z�b�g�֐��Q

	/**
	* �Q�[���}�b�v�Z�b�g�֐�
	* Map�N���X�ŌĂяo���A�`��o�b�t�@�ɃQ�[���}�b�v����������
	*
	* @param map[][] �`��o�b�t�@�ɏ������ރQ�[���}�b�v
	*/
	void SetGameMap(DrawType map[][GAME_MAP_HEIGHT]);

	/**
	* ���s���ʃZ�b�g�֐�
	* Map�N���X�ŌĂяo���A���s���ʂ��Z�b�g����
	*
	* @param result �Z�b�g���鏟�s����
	*/
	void SetResult(MatchResult result);


private:
	/**
	* �`��o�b�t�@�N���A�֐�
	* �`��o�b�t�@�ɏ������p�o�b�t�@���R�s�[����
	*/
	void BufferClear(); 

	/**
	* �`��֐�
	* �`��p�o�b�t�@��`�悷��֐�
	*/
	void DrawBuffer();

	/**
	* ���s���ʕ\���֐�
	* ���s�������Ƃ��̂ݓ����֐�
	*/
	void DrawResult();


private:
	//! �������p�o�b�t�@
	DrawType m_blank_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	//! �`��p�o�b�t�@
	DrawType m_draw_buffer[DRAW_BUFFER_WIDTH][DRAW_BUFFER_HEIGHT];
	// ���s���ʕۑ��ϐ�
	MatchResult m_result;

};

#endif

