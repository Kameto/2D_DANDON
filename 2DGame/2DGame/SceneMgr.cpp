#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	mpScene = new LoadScene();
	preScene = mpScene->GetNowScene();
}

SceneMgr::~SceneMgr()
{
	REL_CLS(mpScene);
}

void SceneMgr::ChangeScene()
{
	REL_CLS(mpScene);

	switch (mpScene->GetNowScene())
	{
	case SceneName::mLoad:
		mpScene = new LoadScene();
		break;
	case SceneName::mStart:
		mpScene = new StartScene();
		break;
	case SceneName::mGame:
		mpScene = new GameScene();
		break;
	case SceneName::mEnd:
		mpScene = new EndScene();
		break;
	default:
		break;
	}
}

void SceneMgr::SceneUpdate() 
{
	preScene = mpScene->GetNowScene();
	mpScene->Update();
	if (mpScene->GetNowScene() != preScene)
	{
		ChangeScene();
	}
}

void SceneMgr::SceneDraw() 
{
	mpScene->Draw();
}