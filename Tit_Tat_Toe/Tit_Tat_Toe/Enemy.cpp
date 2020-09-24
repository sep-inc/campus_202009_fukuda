#include "Enemy.h"
#include "Global.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy():
	m_step(Step::Step_Initialize),
	m_draw_type(DrawType::TypeNone)
{
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// 疑似乱数生成テーブルの初期化（時間）
	srand((unsigned)time(NULL));
	m_draw_type = DrawType::Enemy;
}

void Enemy::Update()
{
	switch (m_step) {
	case Step::Step_Initialize:
		// 初期化
		Init();
	// 初期化終了でステップ更新
		m_step = Step::Step_Run;
		break;
	case Step::Step_Run:
		// ゲーム終了判定条件が成立していない場合
		if (g_map.IsFinishGame() == false) {
			// 入力する場所を決め、ゲームマップ配列へセットする
			g_map.SetPos(SelectInputPos(), m_draw_type);
			// 勝敗判定を行い、結果をMapクラスへセットする
			g_map.SetResult(g_map.JudgeResult());
		}
		// ゲーム終了の条件が成立していた場合
		else {
			// ステップをStep_Endに更新する
			m_step = Step::Step_End;
		}
		break;
	case Step::Step_End:
		break;
	}
}

Vec2 Enemy::SelectInputPos()
{
	// 選択する要素数を空のマス目リストのサイズをもとにランダムで決める
	int select_num = rand() % (g_map.GetEmptyArraySize());
	// 決まった要素数に格納されている座標を返す
	return g_map.GetSelectEnptyPos(select_num);
}
