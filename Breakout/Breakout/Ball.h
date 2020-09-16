#ifndef BALL_H_
#define BALL_H_

#include "ObjectBase.h"

// 球クラス
class Ball :public ObjectBase {
public:
	Ball();
	~Ball();

	// 初期化関数
	void Init(float pos_x, float pos_y, bool enable, Kind kind)override;
	// ステップ更新関数
	void Update();
	// 描画バッファへ書き込む関数
	void SetUpDrawBuffer();

private:
	// 壁との当たり判定関数
	void HitWall();
	// ブロックとの当たり判定関数
	void HitBlock();
	// バーとの当たり判定関数
	// 実際の計算はブロックに持たせて、bool関数で返すように
	void HitBar();
	// 移動関数
	void Move();

	// 矩形と円との当たり判定計算関数群
	// 矩形の頂点とヒット
	bool HitRectVertexHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	// 矩形の上下とヒット
	bool HitRectUpDownHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	// 矩形の左右とヒット
	bool HitRectLeftRightHitBox(Vec2 vertex1_pos, Vec2 vertex2_pos);
	
	
	
private:
	float m_radius;			// 半径
	Size m_size;			// サイズ
	Vec2 m_vec;				// ベクトル座標
	Vec2 m_circle_center;	// 円の中心座標

};

#endif

