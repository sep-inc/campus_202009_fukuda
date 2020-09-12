#ifndef BAR_H_
#define BAR_H_

#include "ObjectBase.h"

// �o�[�N���X
class Bar :public ObjectBase {
public:
	Bar();
	~Bar();

	// �������֐�
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// �X�e�b�v�X�V�֐�
	void Update()override;
	Vec2 GetBarPos();
	// �`��o�b�t�@�֏������ފ֐�
	void SetUpDrawBuffer()override;

private:
	// �ǂƂ̓����蔻��
	void HitWall();
	// ���ǂƂ̓����蔻��
	bool HitLeftWall();
	// �E�ǂƂ̓����蔻��
	bool HitRightWall();
	// �ړ�
	void Move();

private:
	Size m_size;	// �T�C�Y
	Vec2 m_vec;		// �x�N�g�����W
};

#endif
