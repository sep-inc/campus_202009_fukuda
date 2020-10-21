#ifndef FRAME_COUNTER_H_
#define FRAME_COUNTER_H_

/**
* @file FrameCounter.h
* @brief FrameCounterクラスのヘッダ
*/

/**
* @class FrameCounter
* @brief FrameCounter 
*/
class FrameCounter
{
public:
	FrameCounter();
	~FrameCounter();

	/**
	* @brief フレームカウント更新関数
	*/
	void UpdateCounter();

	/**
	* @brief フレームカウントリセット関数
	*/
	void ResetCounter();

	/**
	* @brief フレームカウントが指定フレームに達しているかを返す関数
	* @return bool 指定フレームに達していたらtrue
	*/
	bool IsCountMax();

private:
	int m_now_frame;	//! 現在のフレームカウント
};

#endif
