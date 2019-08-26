#include "BaseScene.h"

SceneName BaseScene::nowScene = SceneName::mLoad;

SceneName BaseScene::GetNowScene()
{
	return nowScene;
}