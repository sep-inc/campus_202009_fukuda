#ifndef BLOCK_H_
#define BLOCK_H_

#include "ObjectBase.h"

// ブロッククラス
class Block :public ObjectBase {
public:
	Block();
	~Block();

	// 初期化関数
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// 描画バッファへ書き込む関数
	void SetUpDrawBuffer();
	Vec2 GetBlockPos();
	// 描画フラグをオフにする関数
	void IsDelete();

private:
	Size m_size;	// サイズ

};


#endif

