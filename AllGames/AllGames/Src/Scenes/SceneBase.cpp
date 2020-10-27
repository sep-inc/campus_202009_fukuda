#include "SceneBase.h"

SceneBase::SceneBase():
	m_next_scene(SceneType::TYPE_NONE),
	m_is_scene_finish(false)
{
}

SceneBase::~SceneBase()
{
}

bool SceneBase::IsGameFinish()
{
	if (m_is_scene_finish) {
		return true;
	}
	return false;
	
}
