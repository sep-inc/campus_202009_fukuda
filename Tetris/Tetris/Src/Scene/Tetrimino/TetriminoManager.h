#ifndef TETRIMINO_MANAGER_H_
#define TETRIMINO_MANAGER_H_

#include "TetriminoBase.h"

/**
* @class TetriminoManager
* @brief テトリミノの管理を行うクラス
*/
class TetriminoManager
{
public:
	TetriminoManager();
	~TetriminoManager();

	/**
	* @brief テトリミノ生成関数
	*/
	void CreateTetrimino();

	/**
	* brief 動かしているテトリミノを破棄する関数
	*/
	void DestroyActiveTetrimino();


private:
	TetriminoBase* m_active_tetrimino;	//! 現在動かしているテトリミノ
	TetriminoBase* m_waiting_tetrimino;	//! 待機中のテトリミノ

};

#endif
