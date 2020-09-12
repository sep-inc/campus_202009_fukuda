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
	Vec2 GetBlockPos();
	// �`��t���O���I�t�ɂ���֐�
	void IsDelete();

private:
	Size m_size;	// �T�C�Y

};


#endif

