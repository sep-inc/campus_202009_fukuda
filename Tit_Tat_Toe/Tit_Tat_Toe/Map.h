#ifndef MAP_H_
#define MAP_H_

#include "Definition.h"

/**
* @file Map.h
* @brief Mapクラスのヘッダ
*/


/**
* @class Map
* @brief ゲーム座標でのマスを管理するクラス
*/
class Map{
public:
	Map();
	~Map();

	/**
	* Mapクラスの初期化関数
	* Step_Iitialize中の処理で呼ばれる
	*/
	void Init();

	/**
	* 処理ステップ更新関数
	* 処理ステップを更新し、各ステップごとの処理を呼び出す
	*/
	void Update();

	/**
	* 勝敗判定関数
	* 呼び出されたタイミングでの、ゲームマップ配列の状況から勝敗判定をする
	* ゲームマップへ座標をセットした直後に呼び出す
	*
	* return 勝敗判定結果
	*/
	MatchResult JudgeResult();

	/**
	* 入力された座標のマスが空かどうかを調べる関数
	* Player、Enemyの入力処理で呼ばれる
	*
	* @param pos 入力された座標
	* @return 入力マスが空だった場合、true
	*/
	bool IsEmpty(Vec2 pos);

	/**
	* ゲーム終了判定関数
	* 勝敗結果が確定しているかどうかと、ターンの経過数でゲームの終了判定をする
	* Player、Enemyが各々の更新処理の前に呼び出す
	*
	* return ゲーム終了条件が成立していたらtrue
	*/
	bool IsFinishGame();

	/**
	* 空のマス目リストの要素数を取得する関数
	* 要素数を取得する際に、UpdateEnptyPos関数で空のマス目リストを
	* 更新してから取得する
	*
	* @return 空のマス目リストの要素数
	*/
	int8_t GetEmptyArraySize();

	/**
	* 選択した要素の座標を返す関数
	* 引数に入った要素番号の空のマス目リストの座標を返す
	*
	* @param num 要素数
	* @return 指定された要素番号の座標
	*/
	Vec2 GetSelectEnptyPos(int num);


public:
	// セッター関数群

	/**
	* 入力座標セット関数
	* 座標に対応したゲームマップ配列の要素に描画タイプを格納する
	*
	* @param pos セットする座標
	* @param type セットする描画タイプ
	*/
	void SetPos(Vec2 pos, DrawType type);

	/**
	* 勝敗結果セット関数
	* Player、Enemyの勝敗を判定する処理の後に各々が呼び出す
	*
	* @param result セットする勝敗結果
	*/
	void SetResult(MatchResult result);


private:
	/**
	* 空のマス目リストを更新する関数
	* ゲームマップ配列から空のマス目の座標をリストアップする
	* 空のマス目リストが固定長の配列のため、使用する配列の要素数も計算する
	*/
	void UpdateEnptyPos();

	/**
	* 空のマス目リストを初期化する関数
	* 空のマス目リストと、使用した配列の要素数を0初期化する
	*/
	void ClearEmptyPos();


private:
	//! 現在の処理ステップ
	Step m_step;
	//! ゲームマップ配列
	DrawType m_game_map[GAME_MAP_WIDTH][GAME_MAP_HEIGHT];
	//! 空のマス目リスト配列
	Vec2 m_empty_pos[GAME_MAP_WIDTH * GAME_MAP_HEIGHT];
	//! 空のマス目リストの要素数
	int8_t m_empty_array_size;
	//! ゲームの経過ターン数
	int8_t m_turn_num;
	//! 現在の勝敗状況保存変数
	MatchResult m_result;
};


#endif