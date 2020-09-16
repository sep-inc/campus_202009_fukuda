#ifndef BALL_H_
#define BALL_H_

#include "ObjectBase.h"

// ���N���X
class Ball :public ObjectBase {
public:
	Ball();
	~Ball();

	// �������֐�
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// �X�e�b�v�X�V�֐�
	void Update();
	// �`��o�b�t�@�֏������ފ֐�
	void SetUpDrawBuffer();

private:
	// �ǂƂ̓����蔻��֐�
	void HitWall();
	// �u���b�N�Ƃ̓����蔻��֐�
	void HitBlock();
	// �o�[�Ƃ̓����蔻��֐�
	// ���ۂ̌v�Z�̓u���b�N�Ɏ������āAbool�֐��ŕԂ��悤��
	void HitBar();
	// �ړ��֐�
	void Move();

	// ��`�Ɖ~�Ƃ̓����蔻��v�Z�֐��Q
	// ��`�̒��_�ƃq�b�g
	bool HitRectVertexHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	// ��`�̏㉺�ƃq�b�g
	bool HitRectUpDownHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	// ��`�̍��E�ƃq�b�g
	bool HitRectLeftRightHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	
	
	
private:
	float m_radius;			// ���a
	Size m_size;			// �T�C�Y
	Vec2 m_vec;				// �x�N�g�����W
	Vec2 m_circle_center;	// �~�̒��S���W

};

#endif

