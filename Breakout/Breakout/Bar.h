#ifndef BAR_H_
#define BAR_H_

#include "ObjectBase.h"

// バークラス
class Bar :public ObjectBase {
public:
	Bar();
	~Bar();

	// 初期化関数
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// ステップ更新関数
	void Update()override;
	Vec2 GetBarPos();
	// 描画バッファへ書き込む関数
	void SetUpDrawBuffer()override;

private:
	// 壁との当たり判定
	void HitWall();
	// 左壁との当たり判定
	bool HitLeftWall();
	// 右壁との当たり判定
	bool HitRightWall();
	// 移動
	void Move();

private:
	Size m_size;	// サイズ
	Vec2 m_vec;		// ベクトル座標
};

#endif
