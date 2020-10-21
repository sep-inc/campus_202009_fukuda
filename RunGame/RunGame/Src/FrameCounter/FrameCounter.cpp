#include "FrameCounter.h"
#include "../Definition.h"

FrameCounter::FrameCounter():
	m_now_frame(0)
{
}

FrameCounter::~FrameCounter()
{
}

void FrameCounter::UpdateCounter()
{
	// カウントを加算
	m_now_frame++;
	// 指定フレームを超えたらリセット
	if (m_now_frame >= UPDATE_FRAME_NUM) {
		ResetCounter();
	}
}

void FrameCounter::ResetCounter()
{
	m_now_frame = 0;
}

bool FrameCounter::IsCountMax()
{
	// 指定フレームならtrue
	if (m_now_frame == UPDATE_FRAME_NUM) {
		return true;
	}
	return false;
}
