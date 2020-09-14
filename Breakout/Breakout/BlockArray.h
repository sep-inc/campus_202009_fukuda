#ifndef BLOCKARRAY_H_
#define BLOCKARRAY_H_

#include "Block.h"

// ブロックを配列で管理するクラス
class BlockArray {
public:
	BlockArray();
	~BlockArray();

	// 初期化関数
	void Init();
	// ステップ更新関数
	void Update();
	// ブロック配置関数
	void SetUpBlocks();
	// 各ブロックの描画バッファへ書き込む関数を呼び出す関数
	void SetUpDrawBuffer();


	Block m_block_array[BLOCK_NUM_X][BLOCK_NUM_Y];		// ブロック配列
private:
	
	ObjectBase::Step m_step;							// 現在のステップ
	

};

#endif

