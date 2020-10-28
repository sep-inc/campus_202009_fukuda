#ifndef SELECT_GAME_SCENE_H_
#define SELECT_GAME_SCENE_H_

#include "../SceneBase.h"
#include "../../AllDefinition.h"
#include "SelectGameDefinition.h"

#include <cinttypes>

/**
* @class SelectGameScene
* @brief ゲームの選択シーンクラス
*/
class SelectGameScene : public SceneBase
{
public:
	SelectGameScene();
	~SelectGameScene();

	/**
	* @brief 更新処理関数
	*/
	void Update()override;

	/**
	* @brief 描画処理関数
	*/
	void Draw(DrawerBase* drawer_)override;

	/**
	* @brief インスタンス生成関数
	*/
	static SceneBase* InstanceSelectGameScene();


private:
	/**
	* @brief 初期化関数
	*/
	void Init();
	/**
	* @brief シーン選択処理関数
	*
	* @return bool Enterが押されたらtrue
	*/
	bool SelectScene();


private:
	//! SelectGameの更新ステップ
	enum class SelectGameStep {
		STEP_INITIALIZE,
		STEP_UPDATE,
		STEP_END
	};

	//! 選択するゲームの情報をまとめた構造体
	struct SelectGameParam {
		SceneType m_scene_type;									//! 自身の種類
		char m_title_string[SELECT_GAME_DRAW_STRING_SIZE];		//! 描画情報

		SelectGameParam() :
			m_scene_type(SceneType::TYPE_NONE),
			m_title_string(" ")
		{
		}
	};

	//! 現在のステップ
	SelectGameStep m_now_step;
	//! ゲームの情報の配列
	SelectGameParam m_games[ALL_GAME_NUM];
	//! 現在選択中のシーンの番号
	int m_now_select_index;

};

#endif
