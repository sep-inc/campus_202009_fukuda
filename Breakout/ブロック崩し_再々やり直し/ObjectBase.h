#ifndef OBJECTBASE_H_
#define OBJECTBASE_H_

#include "Definition.h"

// ���N���X
class ObjectBase {
public:
	ObjectBase();
	virtual ~ObjectBase();

	// �������֐�
	virtual void Init(float pos_x, float pos_y, bool enable, Kind kind);
	// �X�e�b�v�X�V�֐�
	virtual void Update();
	// �`��o�b�t�@�֏������ފ֐�
	virtual void SetUpDrawBuffer();

	// �X�e�b�v�̎��
	enum class Step : int {
		STEP_INITIALIZE,	// ������
		STEP_RUN,			// �\���p����
		STEP_END,			// ���

		MAX_STEP
	};

protected:
	Vec2 m_pos;			// �{���̍��W
	float m_speed;		// �ړ����x
	Step m_step;		// ���݂̃X�e�b�v
	Kind m_kind;		// ���
	bool m_enable;		// �`��t���O�itrue�Ȃ�`��j

};

#endif
