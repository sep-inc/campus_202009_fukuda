#ifndef BLOCK_H_
#define BLOCK_H_

#include "ObjectBase.h"

// �u���b�N�N���X
class Block :public ObjectBase {
public:
	Block();
	~Block();

	// �������֐�
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// �`��o�b�t�@�֏������ފ֐�
	void SetUpDrawBuffer();
	// ���W�擾�֐��i�����蔻��Ŏg�p�j
	Vec2 GetBlockPos();
	// �\���t���O�擾�֐�
	bool GetDrawFlag();
	// �`��t���O���I�t�ɂ���֐��i�����蔻�莞�Ɏg�p�j
	void IsDelete();

private:
	Size m_size;	// �T�C�Y

};


#endif

