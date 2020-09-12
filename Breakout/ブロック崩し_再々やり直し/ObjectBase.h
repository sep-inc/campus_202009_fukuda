#ifndef OBJECTBASE_H_
#define OBJECTBASE_H_

#include "Definition.h"

// 基底クラス
class ObjectBase {
public:
	ObjectBase();
	virtual ~ObjectBase();

	// 初期化関数
	virtual void Init(float pos_x, float pos_y, bool enable, Kind kind);
	// ステップ更新関数
	virtual void Update();
	// 描画バッファへ書き込む関数
	virtual void SetUpDrawBuffer();

	// ステップの種類
	enum class Step : int {
		STEP_INITIALIZE,	// 初期化
		STEP_RUN,			// 表示用処理
		STEP_END,			// 解放

		MAX_STEP
	};

protected:
	Vec2 m_pos;			// 本来の座標
	float m_speed;		// 移動速度
	Step m_step;		// 現在のステップ
	Kind m_kind;		// 種類
	bool m_enable;		// 描画フラグ（trueなら描画）

};

#endif
